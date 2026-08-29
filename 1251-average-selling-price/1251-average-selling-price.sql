# Write your MySQL query statement below
SELECT P.product_id,
       ROUND(
           COALESCE(SUM(US.units * P.price) / SUM(US.units), 0),
           2
       ) AS average_price
FROM Prices AS P
LEFT JOIN UnitsSold AS US
    ON P.product_id = US.product_id
    AND US.purchase_date >= P.start_date
    AND US.purchase_date <= P.end_date
GROUP BY P.product_id;   