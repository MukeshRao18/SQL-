# Write your MySQL query statement belw
with sample as(
    select requester_id id from RequestAccepted
    union all
    select accepter_id id from RequestAccepted
)

select id,count(*) num from sample
group by id
order by num desc
limit 1
;

