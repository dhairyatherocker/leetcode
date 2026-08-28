# Write your MySQL query statement below
SELECT C.name AS name 
FROM Customer as C
WHERE C.referee_id IS NULL OR C.referee_id!=2 