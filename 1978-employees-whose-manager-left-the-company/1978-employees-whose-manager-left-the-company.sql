# Write your MySQL query statement below
SELECT employee_id
FROM Employees AS E 
WHERE E.salary<30000 AND E.manager_id NOT IN (
SELECT employee_id 
FROM Employees AS E1
)
ORDER BY employee_id