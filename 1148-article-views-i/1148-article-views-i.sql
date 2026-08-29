# Write your MySQL query statement below
SELECT  DISTINCT author_id AS id
FROM Views AS V
WHERE V.author_id=V.viewer_id
ORDER BY  author_id ASC 