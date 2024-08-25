# Write your MySQL query statement below
select left(trans_date,7) as month,country,count(id) as trans_count,IFNULL(sum(state='approved'),0) as approved_count,sum(amount) as trans_total_amount, IFNULL(sum((case when state='approved' then 1 end)*amount),0) as approved_total_amount
from Transactions T
group by month,country;