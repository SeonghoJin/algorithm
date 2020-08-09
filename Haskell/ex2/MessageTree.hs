module MessageTree where

import Log  
import LogAnalysis

data MessageTree = Leaf
                 | Node MessageTree LogMessage MessageTree

insert :: LogMessage -> MessageTree -> MessageTree

insert (Unknown _) tree = tree
insert msg Leaf = Node Leaf msg Leaf
insert msg@(LogMessage _ ti _) (Node left msg2@(LogMessage _ ti2 _) right)
       | ti <= ti2 = Node (insert msg left) msg2 right
       | ti > ti2 = Node left msg2 (insert msg right)

build :: [LogMessage] -> MessageTree
build [] = Leaf
build (m : ms) = insert m (build ms)

inOrder :: MessageTree -> [LogMessage]
inOrder Leaf = []
inOrder (Node left msg right) = (inOrder left) ++ [msg] ++ (inOrder right)

whatWentWrong :: [LogMessage] -> [String]
whatWentWrong [] = []
whatWentWrong ((LogMessage (Error v) _ s):xs) | v >= 50 = s : whatWentWrong xs
whatWentWrong ((LogMessage _ _ _):xs) = whatWentWrong xs
whatWentWrong ((Unknown _):xs) = whatWentWrong xs

