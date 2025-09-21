# Write your MySQL query statement b
Select q.person_name  from queue q
where (Select sum(weight) from queue q2 where q.turn >= q2.turn) <= 1000
order by q.turn DESC
LIMIT 1