# Write your MySQL query statement below
-- SELECT S.product_id  AS product_id , S. year AS first_year,S.quantity AS quantity,S. price  AS  price  
-- FROM Sales AS S 
-- WHERE S.year =(
--    SELECT MIN(S1.year)
--     FROM Sales AS S1
--     WHERE S1.product_id = S.product_id
-- )=0 

SELECT S.product_id,
       S.year AS first_year,
       S.quantity,
       S.price
FROM Sales AS S
JOIN (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) AS F
ON S.product_id = F.product_id
AND S.year = F.first_year;