module FilterList where


-- FilterList.hs
data List t = E | C t (List t)

filterList _ E = E
filterList p (C x xs)
  | p x       = C x (filterList p xs)
  | otherwise = filterList p xs