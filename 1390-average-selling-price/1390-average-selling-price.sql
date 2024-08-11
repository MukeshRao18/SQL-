# Write your MySQL query statement below
select p.product_id as product_id, IFNULL(round((sum(price*units)/sum(units)),2),0) as average_price
from Prices p left join 
UnitsSold u on 
u.product_id = p.product_id and
u.purchase_date between p.start_date and p.end_date
group by p.product_id;