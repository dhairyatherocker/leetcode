# Write your MySQL query statement below
SELECT A1.player_id, A1.event_date AS first_login
FROM Activity AS A1
WHERE (
    SELECT COUNT(*)
    FROM Activity AS A2
    WHERE A1.player_id = A2.player_id
      AND A1.event_date > A2.event_date
) = 0;