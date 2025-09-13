Select p.project_id, AVG(e.experience_years) as average_years From Project p
LEFT JOIN employee e on e.employee_id = p.employee_id
group by p.project_id