# Write your MySQL query statement below
WITH first_login AS (
    SELECT
        player_id,
        MIN(event_date) AS first_day
    FROM Activity
    GROUP BY player_id
)

SELECT
    ROUND(
        COUNT(*) * 1.0 /
        (SELECT COUNT(*) FROM first_login),
        2
    ) AS fraction
FROM first_login f
JOIN Activity a
ON a.player_id = f.player_id
AND a.event_date = DATE_ADD(f.first_day, INTERVAL 1 DAY);
