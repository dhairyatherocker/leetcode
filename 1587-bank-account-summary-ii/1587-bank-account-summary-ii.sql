# Write your MySQL query statement below
SELECT U.name AS name , SUM(T.amount) AS balance
FROM Users AS U INNER JOIN Transactions AS T ON U.account=T.account
GROUP BY T.account
HAVING SUM(T.amount)>10000 