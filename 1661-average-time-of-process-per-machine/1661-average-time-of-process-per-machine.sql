# Write your MySQL query statement below

select s.machine_id, ROUND(AVG(e.timestamp - s.timestamp),3) as processing_time from Activity s
join Activity e on s.machine_id = e.machine_id and s.activity_type = "start" and 
e.activity_type = "end" 
group by s.machine_id;