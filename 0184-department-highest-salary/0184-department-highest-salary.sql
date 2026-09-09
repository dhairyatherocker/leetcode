# Write your MySQL query statement below
SELECT D.name AS Department,E.name AS Employee,E.salary AS Salary 
FROM Employee AS E INNER JOIN  Department AS D ON E.departmentId=D.id
WHERE (
    SELECT COUNT(*)
    FROM Employee AS E1 INNER JOIN  Department AS D1 ON E1.departmentId=D1.id
    WHERE D.name=D1.name AND E.salary<E1.salary)=0
