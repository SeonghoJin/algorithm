module Ex4_2 where


data Tree a = Leaf
            | Node Integer (Tree a) a (Tree a)
  deriving (Show, Eq)

temp :: Tree Integer
temp = Node 0 (Node 1 (Leaf) 2 (Leaf)) 4 (Node 1 (Leaf) 3 (Leaf))

exampleTree :: Tree Integer
exampleTree = Node 2 (Node 1 (Node 0 Leaf 2 Leaf ) 2 Leaf) 5 Leaf
   

height :: Tree a -> Integer
height Leaf = -1   -- 높이가 0인 트리도 있으므로 -1을 Leaf 노드의 높이로 잡자
height (Node h _ _ _) = h

insert :: a -> Tree a -> Tree a
insert x Leaf = Node 0 Leaf x Leaf
insert x (Node 0 Leaf v Leaf) = Node 1 (insert x Leaf) v Leaf
insert x (Node h left v right) = 
  let
    leftH = height left
    rightH = height right
  in
    if leftH > rightH then 
      Node h left v (insert x right)
    else if leftH < rightH then
      Node h (insert x left) v right
    else 
      Node (h+1) (insert x left) v right


foldTree :: [a] -> Tree a
foldTree = foldr insert Leaf


exampleList = [1,2,3,4,5,6,7]
tt = foldTree exampleList

isBalanced :: Tree a -> Bool

isBalanced Leaf = True
isBalanced (Node _ left v right) =let 
                                  leftH = height left
                                  rightH = height right
                                  in
                                    (abs (leftH - rightH) <= 1) && isBalanced left && isBalanced right
                                    

