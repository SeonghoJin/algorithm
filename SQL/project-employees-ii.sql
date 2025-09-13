select p.project_id from Project p
Group by p.project_id 
HAVING COUNT(p.project_id) = (SELECT MAX(t.cnt) from (Select COUNT(*) as cnt  from Project p
Group by p.project_id) as t)