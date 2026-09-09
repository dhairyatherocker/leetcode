# Write your MySQL query statement below
SELECT 
    S.stock_name,
    (
        (SELECT SUM(S2.price)
         FROM Stocks AS S2
         WHERE S2.stock_name = S.stock_name
           AND S2.operation = 'Sell')
        -
        (SELECT SUM(S2.price)
         FROM Stocks AS S2
         WHERE S2.stock_name = S.stock_name
           AND S2.operation = 'Buy')
    ) AS capital_gain_loss
FROM Stocks AS S
GROUP BY S.stock_name;