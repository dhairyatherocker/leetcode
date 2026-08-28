# Write your MySQL query statement below
SELECT  actor_id,director_id
FROM  ActorDirector AS AD
GROUP BY actor_id,director_id
HAVING COUNT(*)>=3   