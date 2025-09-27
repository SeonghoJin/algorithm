# Write your MySQL query statement below
With TeamSize AS (
    Select COUNT(*) as cnt, team_id from Employee group by team_id
)

Select e.employee_id, t.cnt as team_size from Employee e
left join TeamSize t on e.team_id = t.team_id