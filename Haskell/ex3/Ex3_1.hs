module Ex3_1 where

skip :: Int -> Int-> [a] -> [a]
skip a b xs | a+b-1 >= (length xs) = []
            | otherwise = xs !! (a+b-1) : skip (a+b) b xs

exampleList = [1,2,3,4,5,6,7,8,9,10]
example1 = skip 0 1 exampleList
example2 = skip 0 2 exampleList
example3 = skip 0 3 exampleList

skips :: [a] -> [[a]]

skips xs = map (\x -> skip 0 x xs) [1..(length xs - 1)]



main = do
    print example1
    print example2
    print example3



