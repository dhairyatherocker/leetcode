# Write your MySQL query statement below
SELECT C.class AS class
FROM Courses AS C
GROUP BY c.class
HAVING COUNT(C.student)>=5 