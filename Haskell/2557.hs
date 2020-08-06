main = do 
    n <- read <$> getLine :: IO Int
    print ( sum [0..n] );
    
