# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets as T
WHERE LENGTH(content)>15