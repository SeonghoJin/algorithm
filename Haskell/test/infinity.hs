
data Tree  = Empty | Node Tree Int Tree 
            deriving Show 

exampleTree1 = Node (Node Empty 1 (Node Empty 3 (Node Empty 4 Empty))) 5 (Node Empty 2 Empty)

f :: Tree -> Tree
f Empty = Empty
f (Node l x r) = Node (f r) x (f l)

exampleTree2 = f exampleTree1

-- ExampleTree1 = Node (Node Empty 1 (Node Empty 3 (Node Empty 4 Empty))) 5 (Node Empty 2 Empty)

-- ExampleTree2 = Node (Node Empty 2 Empty) 5 (Node (Node (Node Empty 4 Empty) 3 Empty) 1 Empty)

