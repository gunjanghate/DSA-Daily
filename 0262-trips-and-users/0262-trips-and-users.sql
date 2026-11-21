# Write your MySQL query statement below

select t.request_at as Day, 
round(
    sum(
        Case when status in ('cancelled_by_driver' ,'cancelled_by_client')
        then 1 else 0 end ) / count(*)
    ,2) as 'Cancellation Rate'
from Trips t where t.request_at between "2013-10-01" and "2013-10-03"
and client_id not in (select users_id from Users where banned='Yes' and role = 'client') and 
driver_id not in (select users_id from Users where banned='Yes' and role = 'driver')
group by t.request_at
;