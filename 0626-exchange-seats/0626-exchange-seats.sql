# Write your MySQL query statement below
SELECT S2.id AS id,S1.student AS student
FROM Seat AS S1 INNER JOIN Seat AS S2   
WHERE (MOD(S1.id,2)=0 AND S2.id=S1.id-1) OR (MOD(S1.id,2)=1 AND S2.id=S1.id+1)

UNION 

SELECT S.id AS id , S.student AS student
FROM Seat AS S
WHERE MOD(S.id,2)=1 AND s.id+1 NOT IN (
SELECT s.id 
FROM Seat AS s    
)