# Write your MySQL query statement below
select q.query_name as query_name , round(sum(rating/position)/count(*),2) as quality,
round(sum(case when q.rating<3 then 1 else 0 end)*100/count(*),2) as poor_query_percentage
from Queries q
where q.query_name is not null
group by query_name;