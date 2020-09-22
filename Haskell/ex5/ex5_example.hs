{-# LANGUAGE MultiParamTypeClasses #-}
data Foo = F Int | G Char

instance Eq Foo where
  (F i1) == (F i2) = i1 == i2
  (G c1) == (G c2) = c1 == c2
  _ == _ = False

  foo1 /= foo2 = not (foo1 == foo2)

data Foo' = F' Int | G' Char
  deriving (Eq, Ord, Show)

t1 = F' 2 == G' 'a'
t2 = F' 2 == F' 3
t3 = F' 3 == F' 3


class Blerg a b where
 blerg :: a -> b -> Bool

class Listable a where
  toList :: a -> [Int]

instance Listable Int where
  -- toList :: Int -> [Int]
  toList x = [x]

instance Listable Bool where
  -- toList :: Bool -> [Int]
  toList True  = [1]
  toList False = [0]

sumL :: Listable a => a -> Int
sumL = sum . (\x -> toList x)


foo :: (Listable a, Ord a) => a -> a -> Bool 
foo = \x y -> sum (toList x) == sum (toList y) || x < y


instance ((Listable a, Listable b) => Listable (a,b)) where
  toList (x,y) = toList x ++ toList y



add :: Int -> Int -> Int
add = \x y -> x + y

