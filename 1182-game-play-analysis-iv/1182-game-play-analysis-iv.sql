# Write your MySQL query statement below
select round(count(distinct player_id)/(select distinct count(distinct player_id) from Activity),2) as fraction
from Activity a
where (player_id,DATE_SUB(a.event_date,interval 1 day)) in 
(select player_id,min(event_date) from
Activity
group by
player_id);