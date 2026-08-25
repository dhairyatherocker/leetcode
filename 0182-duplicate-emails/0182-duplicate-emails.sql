# Write your MySQL query statement below
SELECT DISTINCT P.email AS Email
FROM Person as P 
INNER JOIN 
Person as PE
WHERE p.id!=PE.id AND p.email=PE.email