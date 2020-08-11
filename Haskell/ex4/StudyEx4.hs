module StudyEx4 where


myTest' :: [Integer] -> Bool
myTest' = even . length . filter (>100)

foobar' :: [Integer] -> Integer
foobar' = sum . map (\x -> 7*x + 2) . filter (>3)

