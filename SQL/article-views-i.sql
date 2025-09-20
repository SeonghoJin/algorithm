# Write your MySQL query statement below
Select distinct v.author_id as id from Views v
Where v.author_id = v.viewer_id
order by v.author_id