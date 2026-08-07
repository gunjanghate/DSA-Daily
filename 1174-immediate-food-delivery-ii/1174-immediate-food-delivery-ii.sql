# Write your MySQL query statement below
with first_orders as (
     select customer_id,
     min(order_date) as first_order
     from Delivery
     group by customer_id
)

select ROUND(
    avg(d.order_date = d.customer_pref_delivery_date) * 100
    ,2) as immediate_percentage  
from first_orders f 
JOIN Delivery d on f.customer_id = d.customer_id
and f.first_order = d.order_date; 