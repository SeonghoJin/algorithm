module Ex4_1 where

length':: [a] -> Integer
length' = foldr (\_ x-> 1 + x) 0

sum' :: Num a => [a] -> a
sum' = foldr (+) 0

product' :: Num a => [a] -> a
product' = foldr (*) 1

and' :: [Bool] -> Bool
and' = foldr (&&) True

or' :: [Bool] -> Bool
or' = foldr (||) False

any' :: (a -> Bool) -> [a] -> Bool
any' = \f -> or' . map f 

all' :: (a -> Bool) -> [a] -> Bool
all' = \f -> and' . map f 

fun1 :: [Integer] -> Integer
fun1 [] = 1
fun1 (x:xs)
  | even x    = (x - 2) + fun1 xs
  | otherwise = fun1 xs

fun2 :: Integer -> Integer
fun2 1 = 0
fun2 n | even n    = n + fun2 (n `div` 2)
       | otherwise = fun2 (3 * n + 1)

fun1' :: [Integer] -> Integer
fun1' = foldr (\a b -> b - 2 + a) 1 . filter even 


fun :: Integer -> Integer
fun = \x -> if even x then x `div` 2 else 3 * x + 1

fun2' :: Integer -> Integer
fun2' = sum . filter even . takeWhile (>1) . iterate (\x -> if even x then x `div` 2 else 3 * x + 1)

exampleList = [1..5]

