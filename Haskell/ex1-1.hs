import Control.Exception  -- assert를 사용하기 위해 임포트

toDigitList :: [Char] -> [Integer]
toDigitList [] = []
toDigitList (x:xs) = (read [x] ::Integer) : toDigitList xs 

toDigits :: Integer -> [Integer]
toDigits n 
  | n <= 0 = []
  | otherwise = toDigitList (show n)

toDigitsRev :: Integer -> [Integer]
toDigitsRev n = reverse (toDigits n) 

-- test 코드
test v1 v2 s = assert (v1==v2) s

-- 최상위 수준에 날 식이 들어가면 `parse error: naked expression at top level`이라는 오류가 나옴 
-- 리스트를 만들고 리스트를 출력하는 함수를 만들어서 `doTest`라는 이름을 붙이자.

testValue = [
  test (toDigitList ['0','1']) [0,1] "toDigitList[0,1] success",
  test (toDigitList []) [] "toDigitList[] success",
  test (toDigits 1) [1] "toDigits 1 success",
  test (toDigits 101023) [1,0,1,0,2,3] "toDigits 101023 success",
  test (toDigits 9876543210987654321) [9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1] "toDigits 987654321987654321 success",
  test (toDigitsRev 101023) [3,2,0,1,0,1] "toDigitsRev 101023 success",
  test (toDigitsRev 101023) [3,2,0,1,0,1] "toDigitsRev2 101023 success"
]

doTest = print testValue