# Write your MySQL query statement belo
Select id, name from Students
where department_id not in (Select id from Departments)