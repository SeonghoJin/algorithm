Select d.name as Department, e.name as Employee, e.salary as salary from Employee e
left join (Select departmentId, MAX(salary) as salary from Employee group by departmentId) as max_e on max_e.departmentId = e.departmentId
left join Department d on d.id = e.departmentId
where max_e.salary = e.salary
