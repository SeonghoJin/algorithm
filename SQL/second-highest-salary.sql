With TopSalary AS (
    Select MAX(e1.salary) as max_salary from Employee e1
)

SELECT (Select e2.salary as SecondHighestSalary from Employee e2 Where e2.salary != (Select max_salary from TopSalary)
order by e2.salary desc LIMIT 1) AS SecondHighestSalary