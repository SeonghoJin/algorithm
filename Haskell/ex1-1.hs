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

