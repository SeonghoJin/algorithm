module Ex4_2 where


data Tree a = Leaf
            | Node Integer (Tree a) a (Tree a)
  deriving (Show, Eq)

temp :: Tree Integer
temp = Node 0 (Node 1 (Leaf) 2 (Leaf)) 4 (Node 1 (Leaf) 3 (Leaf))



