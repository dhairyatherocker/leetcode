# Write your MySQL query statement below
SELECT F.user_id,COUNT(DISTINCT F.follower_id)  AS followers_count
FROM Followers AS F
GROUP BY F.user_id
