# Write your MySQL query statement below
SELECT A.activity_date AS day , COUNT(DISTINCT A.user_id) AS  active_users
FROM Activity AS A
WHERE MONTH(A.activity_date)="07" OR (MONTH(A.activity_date)="06" AND DAY(A.activity_date)>='28')
GROUP BY A.activity_date
