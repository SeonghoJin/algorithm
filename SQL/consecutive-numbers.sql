# Write your MySQL query statement below
Select l.num as ConsecutiveNums from Logs l
left join Logs l1 on l1.id = l.id + 1 and l.num = l1.num
left join Logs l2 on l2.id = l.id + 2 and l.num = l2.num
where l.id is not null and l1.id is not null and l2.id is not null
group by l.num