# Write your MySQL query statement below
SELECT T1.id AS id,"Root" AS type
FROM Tree AS T1
WHERE T1.p_id IS NULL

UNION 

SELECT T2.id AS id ,"Inner" AS type
FROM Tree AS T2
WHERE T2.p_id IS NOT NULL AND 
(
SELECT COUNT(*)
FROM Tree AS T1
WHERE T2.id!=T1.id AND T2.id=T1.p_id
)>=1

UNION 

SELECT T2.id AS id ,"Leaf" AS type
FROM Tree AS T2
WHERE T2.p_id IS NOT NULL AND 
(
SELECT COUNT(*)
FROM Tree AS T1
WHERE T2.id!=T1.id AND T2.id=T1.p_id
)=0

