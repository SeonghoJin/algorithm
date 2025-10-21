# Write your MySQL query statement below
Select d.dept_name, COUNT(s.dept_id) as student_number  from Department d
left join Student s on s.dept_id = d.dept_id
group by d.dept_id
order by COUNT(s.dept_id) desc