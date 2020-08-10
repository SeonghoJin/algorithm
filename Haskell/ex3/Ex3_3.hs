module Ex3_3 where



initialMap :: Num p1 => p2 -> p1
initialMap x = 0

addMap :: (Eq a ,Num b)=> (a -> b) -> a -> b -> a -> b
addMap map key value = \k -> if k==key then value else (map k)

f :: (Eq t, Num a) => (t -> a) -> t -> t -> a
f = \map -> \x -> addMap map x ((map x) + 1)

calcDist :: (Foldable t1, Eq t2, Num a) => t1 t2 -> t2 -> a
calcDist xs = foldl f initialMap xs

distMap :: Integer -> Integer
distMap = calcDist [1,2]


