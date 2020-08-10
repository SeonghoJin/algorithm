data Thing = Shoe | Ship | King deriving Show

isSmall :: Thing -> Bool
isSmall Ship = False
isSmall King = False
isSmall _    = True

data FailableDouble = Failure
                    | OK Double
                    deriving Show
                    
safeDiv :: Double -> Double -> FailableDouble

safeDiv _ 0 = Failure
safeDiv x y = OK (x / y)

failureToZero :: FailableDouble -> Double
failureToZero x = case x of
                    Failure -> 0
                    OK d -> d

data Person = Person String Int Thing deriving Show

brent :: Person
brent = Person "Brent" 31 King

stan :: Person
stan = Person "Stan" 94 Shoe

getAge :: Person -> Int
getAge (Person _ a _) = a
getAge _ = 0

baz :: Person -> String
baz p@(Person n _ _) = "The name field of (" ++ show p ++ ") is " ++ n

checkFav :: Person -> String
checkFav (Person n _ King) = n ++ ", you're my kind of person!"
checkFav (Person n a b)          = n ++ ", your favorite thing is lame. " ++ checkFav(Person n a King)

ex03 :: String -> String
ex03 x = case x of 
        [] -> "3"
        (s : ss) -> [s] ++ (ex03 ss)

data IntList = Empty | Cons Int IntList

intListProd :: IntList -> Int
intListProd Empty      = 1
intListProd (Cons x l) = x * intListProd l