# Write your MySQL query statement below
select activity_date as day ,count(distinct user_id) as active_users from 
Activity 
where activity_date BETWEEN DATE_SUB('2019-07-28', INTERVAL 30 DAY) AND '2019-07-28'
group by activity_date;
