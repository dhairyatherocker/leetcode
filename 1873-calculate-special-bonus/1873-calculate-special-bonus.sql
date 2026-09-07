# Write your MySQL query statement below
SELECT employee_id,(CASE WHEN LEFT(name,1)!='M' AND employee_id%2!=0 THEN salary ELSE 0 END) AS bonus
FROM Employees AS E
ORDER BY employee_id