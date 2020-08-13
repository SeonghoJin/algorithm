-- ex1-2.hs
import Control.Exception  -- assert를 사용하기 위해 임포트

doubleEveryOtherFromLeft :: [Integer] -> [Integer]
doubleEveryOtherFromLeft [] = []
doubleEveryOtherFromLeft (x:[]) = x:[]
doubleEveryOtherFromLeft (x1:x2:xs) = x1:(x2*2):(doubleEveryOtherFromLeft xs)

doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther xs = reverse (doubleEveryOtherFromLeft (reverse xs))

-- test 코드
test v1 v2 s = assert (v1==v2) (s)

deol = doubleEveryOtherFromLeft
deor = doubleEveryOther

testValue = [
    test (deol [1,2,3,4]) [1,4,3,3] "deol [1,2,3,4]",
    test (deor [1,2,3,4]) [2,2,6,4] "deor [1,2,3,4]"
            ]
