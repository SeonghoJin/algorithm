module Ex3_2 where


localMax :: Int -> Int -> Int -> [Int]
localMax x y z | y > x && y > z = [y]
               | otherwise = []

localMaxima :: [Int] -> [Int]
localMaxima [] = []
localMaxima (x:y:zs) | zs == [] = []
                     | otherwise = case zs of
                                    k:ks -> (localMax x y k) ++ localMaxima (y : k : ks)