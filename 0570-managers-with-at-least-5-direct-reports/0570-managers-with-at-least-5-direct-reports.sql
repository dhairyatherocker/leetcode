# Write your MySQL query statement below
SELECT  E1.name AS name
FROM Employee AS E1 INNER JOIN Employee AS E2 ON E1.id=E2.managerId 
GROUP BY E1.id,E1.name 
HAVING COUNT(*)>=5