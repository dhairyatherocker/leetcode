# Write your MySQL query statement below
SELECT W.name AS name ,W.population AS population ,w.area AS area
FROM World as W 
WHERE W.population>=25000000 OR W.area>=3000000