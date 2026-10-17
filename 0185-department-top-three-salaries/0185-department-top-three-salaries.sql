# Write your MySQL query statement below
SELECT D.name AS Department, E.name AS Employee, E.salary AS Salary
FROM Employee AS E INNER JOIN  Department AS D ON E.departmentId=D.id
WHERE (
    SELECT COUNT(DISTINCT E1.salary)
    FROM Employee AS E1
    WHERE E1.departmentId = E.departmentId
      AND E1.salary > E.salary
) < 3;