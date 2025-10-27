# Write your MySQL query statement below
Select di.shortest from (Select ROUND(SQRT((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)), 2) as shortest from Point2D p1
join Point2d p2) as di
where di.shortest != 0
order by di.shortest asc
limit 1