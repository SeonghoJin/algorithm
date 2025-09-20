# Write your MySQL query statement below
Select t.id, (case
    when count(t.p_id) = 0 then 'Root'
    when count(t2.id) = 0 then 'Leaf'
    else 'Inner'
    end
) as type from Tree t
left join Tree t2 on t.id = t2.p_id
group by id