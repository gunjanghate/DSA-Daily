# Write your MySQL query statement below

with first_year as (
    select product_id, 
    min(year) as fy 
    from Sales
    group by product_id
)

select s.product_id, f.fy as first_year, s.quantity, s.price
from first_year f JOIN Sales s on 
f.product_id = s.product_id
and s.year = f.fy; 

