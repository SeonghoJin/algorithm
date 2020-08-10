module StudyEx4 where




greater100xs xs = filter (>100) xs

myTest :: [Integer] -> Bool
myTest xs = even (length (greater100xs xs))

myTest' xs = even . length . greater100xs . xs

foobar' :: [Integer] -> Integer
foobar' = sum . map (\x -> 7*x + 2) . filter (>3)