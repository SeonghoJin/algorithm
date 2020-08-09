module IntList where

data IntList = Empty | Cons Int IntList
    deriving Show

addOneToAll :: IntList -> IntList
addOneToAll Empty = Empty
addOneToAll (Cons x xs) = Cons ((+) x 1) (addOneToAll xs)  

absAll :: IntList -> IntList
absAll Empty = Empty
absAll (Cons x xs) = Cons (abs x) (absAll xs)

squareAll :: IntList -> IntList
squareAll Empty = Empty
squareAll (Cons x xs) = Cons ((*) x x) (xs)

addOne :: Int -> Int
addOne x = (+) x 1

square :: Int -> Int
square x = (*) x x

mapIntList :: (Int -> Int) -> IntList -> IntList
mapIntList f x = case x of
                    Empty -> Empty 
                    Cons t ts -> Cons (f t) (mapIntList f ts) 


exampleList = Cons (-1) (Cons 2 (Cons (-6) Empty))
example1 = mapIntList addOne exampleList
example2 = mapIntList abs    exampleList
example3 = mapIntList square exampleList


keepOnlyPositive :: IntList -> IntList

keepOnlyPositive x = case x of 
                     Empty -> Empty
                     Cons t ts | t > 0 -> Cons t (keepOnlyPositive ts)
                               | otherwise -> keepOnlyPositive ts

keepOnlyPositive Empty = Empty
keepOnlyPositive (Cons x xs)
  | x > 0    = Cons x (keepOnlyPositive xs)
  | otherwise = keepOnlyPositive xs                   

keepOnlyEven :: IntList -> IntList
keepOnlyEven Empty = Empty
keepOnlyEven (Cons x xs) | even x = Cons x (keepOnlyEven xs)
                         | otherwise = keepOnlyEven xs

eve :: IntList -> IntList
eve Empty = Empty
eve (Cons x xs) | even x = Cons x xs
                | otherwise = xs

keepPositive :: IntList -> IntList
keepPositive Empty = Empty
keepPositive (Cons x xs) | x > 0 = Cons x xs
                         | otherwise = xs

filter_ :: (IntList -> IntList) -> IntList -> IntList
filter_ _ Empty = Empty
filter_ f (Cons x xs) = f (Cons x (filter_ f xs))


