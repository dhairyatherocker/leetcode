# Write your MySQL query statement below
-- SELECT SUM(tiv_2016) AS tiv_2016  
-- FROM (
-- SELECT tiv_2015,tiv_2016      
-- FROM  Insurance AS I
-- WHERE (
-- SELECT COUNT(*)    
-- FROM  Insurance AS I1
-- WHERE I.lat=I1.lat AND I.lon=I1.lon    
-- )=1
-- GROUP BY tiv_2015,tiv_2016
-- HAVING COUNT(tiv_2016)>1     
-- ) AS T
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance AS I
WHERE (
    SELECT COUNT(*)
    FROM Insurance AS I1
    WHERE I1.lat = I.lat
      AND I1.lon = I.lon
) = 1
AND I.tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
);

