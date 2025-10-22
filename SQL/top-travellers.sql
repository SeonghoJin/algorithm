# Write your MySQL query statement below
Select name, coalesce(SUM(distance), 0) as travelled_distance from users u
left join Rides r on u.id = r.user_id
group by u.id
order by SUM(distance) desc, name asc