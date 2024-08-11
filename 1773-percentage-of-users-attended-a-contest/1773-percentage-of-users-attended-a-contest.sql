# Write your MySQL query statement below
select r.contest_id as contest_id , IFNULL(ROUND((COUNT(u.user_id) / (SELECT COUNT(*) FROM Users)) * 100, 2), 0) as percentage
from Users u left join
Register r on 
r.user_id=u.user_id
WHERE 
    r.contest_id IS NOT NULL
group by r.contest_id
order by percentage DESC, r.contest_id ASC;
