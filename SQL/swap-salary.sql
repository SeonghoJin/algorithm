UPDATE Salary SET sex = (case when sex = 'm' then 'f' when sex = 'f' then 'm' ELSE '' End) 
