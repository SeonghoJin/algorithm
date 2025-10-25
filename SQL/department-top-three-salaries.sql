# Write your MySQL query statement below
Select d.name as Department, ranks.name as Employee, ranks.salary as Salary from (Select salary, name, departmentId, DENSE_RANK() OVER (partition by departmentId order by salary desc) as r from Employee) as ranks
left join Department d on ranks.departmentId = d.id
where ranks.r <= 3
