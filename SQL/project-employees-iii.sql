# Write your MySQL query statement below
with PROJECT_MAX_EXP AS (
    Select p.project_id, MAX(e.experience_years) as max_years from Project p
    left join Employee e on e.employee_id = p.employee_id
    group by p.project_id
)

Select p.project_id, p.employee_id from Project p
left join Employee e on e.employee_id = p.employee_id
left join PROJECT_MAX_EXP exp_ on 
exp_.project_id = p.project_id
where exp_.max_years = e.experience_years