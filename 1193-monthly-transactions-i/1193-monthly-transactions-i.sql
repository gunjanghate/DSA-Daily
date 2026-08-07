# Write your MySQL query statement below

select DATE_FORMAT(trans_date, '%Y-%m') as month,
country,
Count(*) as trans_count,
Sum(state="approved") as approved_count,
Sum(amount) as trans_total_amount,
Sum(
    case
    when state = "approved"
    then amount
    else 0
    END
) as approved_total_amount
from Transactions
group by month, country; 
