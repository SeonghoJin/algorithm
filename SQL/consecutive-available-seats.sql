# Write your MySQL query statement below
Select c.seat_id from Cinema c
left join Cinema c1 on c.seat_id + 1 = c1.seat_id
left join Cinema c2 on c.seat_id - 1 = c2.seat_id
where (c.free and c1.free) or (c.free and c2.free)