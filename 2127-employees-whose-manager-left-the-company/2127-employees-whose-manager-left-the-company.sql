# Write your MySQL query statement below
with cte as(
    select (case when manager_id not in (select employee_id from Employees) then manager_id end) as ids
    from Employees 
)

select employee_id
from Employees 
where salary<30000
and manager_id in (select ids from cte)
order by 1 asc;
