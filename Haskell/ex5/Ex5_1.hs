module Ex5_1 where
import ExprT



eval :: ExprT -> Integer

eval (Lit v) = v
eval (Add e1 e2) = (eval e1) + (eval e2)
eval (Mul e1 e2) = (eval e1) * (eval e2)