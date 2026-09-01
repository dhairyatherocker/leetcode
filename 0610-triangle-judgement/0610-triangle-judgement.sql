# Write your MySQL query statement below
SELECT x,y,z,
       CASE 
       WHEN x+y>z AND 
       Y+Z>X AND
       x+z>y
       THEN "Yes"
       ELSE "No"
    END AS triangle
FROM  Triangle      
