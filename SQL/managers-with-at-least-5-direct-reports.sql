# Write your MySQL query statement below
Select name from Employee e 
Left join (Select managerId from Employee e
group by managerId
having COUNT(*) >= 5) as cnt on cnt.managerId = e.id
where cnt.managerId is not null