# Write your MySQL query statement below
SELECT machine_id AS machine_id,ROUND((SUM(CASE WHEN A.activity_type="end" THEN A.timestamp END)-SUM(CASE WHEN A.activity_type="start" THEN A.timestamp END))/COUNT(DISTINCT A.process_id),3) AS processing_time
FROM Activity AS A
GROUP BY machine_id
