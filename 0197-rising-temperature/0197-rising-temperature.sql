# Write your MySQL query statement below
SELECT today.id
FROM Weather yesterday 
JOIN Weather today

WHERE DATEDIFF(today.recordDate,yesterday.recordDate) = 1
    AND today.temperature > yesterday.temperature
;