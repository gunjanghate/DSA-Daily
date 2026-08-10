# Write your MySQL query statement below


select m.employee_id, m.name,
Count(*) as reports_count, 
Round(AVG(e.age),0) as average_age 
from Employees e join Employees m
where m.employee_id = e.reports_to
group by m.employee_id 
order by m.employee_id;