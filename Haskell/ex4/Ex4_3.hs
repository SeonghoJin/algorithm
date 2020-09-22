module Ex4_3 where

xor :: [Bool] -> Bool

xor = odd . length . filter (\x -> x) 

temp = xor [True, True, True]
t2 = xor [True,True,False,True]
t3 = xor [True,True,False,False]

map1 :: Foldable t => (a1 -> a2) -> t a1 -> [a2]
map1 f = foldr ((:) . f ) [] 

