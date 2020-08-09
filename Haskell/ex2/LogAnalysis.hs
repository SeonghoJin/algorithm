{-# OPTIONS_GHC -Wall #-}
module LogAnalysis where

import Log

parseMessage :: String -> LogMessage
parseMessage x = case (words x) of 
                    [] -> Unknown x
                    (_: []) -> Unknown x
                    (_ : _ : []) -> Unknown x
                    (x:y:zs) | x == "I" -> LogMessage Info (read y :: Int) (unwords zs)
                             | x == "W" -> LogMessage Warning (read y :: Int) (unwords zs)
                    (x:y:z:zs) | x == "E" -> LogMessage (Error (read y :: Int)) (read z :: Int) (unwords zs)
                    otherwise -> Unknown x

parse :: String -> [LogMessage]
parse x = map parseMessage (lines x)

mapparse = map parseMessage
text = "E 2 562 help help\nI 29 la la la\nThis is not in the right format"