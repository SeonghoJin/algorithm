# Write your MySQL query statement below
Select q.id, q.year, coalesce(npv.npv, 0) as npv from queries q
left join npv on (npv.id, npv.year) = (q.id, q.year)