# Write your MySQL query statement below
Select tw.tweet_id from Tweets tw
where CHAR_LENGTH(tw.content) > 140 
or LENGTH(tw.content) - LENGTH(REPLACE(tw.content, '@', '')) > 3
or LENGTH(tw.content) - LENGTH(REPLACE(tw.content, '#', '')) > 3