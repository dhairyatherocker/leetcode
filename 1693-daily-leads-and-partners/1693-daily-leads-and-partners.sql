# Write your MySQL query statement below
SELECT 
    D.date_id,
    D.make_name,
    COUNT(DISTINCT D.lead_id) AS unique_leads,
    COUNT(DISTINCT D.partner_id) AS unique_partners
FROM DailySales AS D
GROUP BY D.date_id, D.make_name;