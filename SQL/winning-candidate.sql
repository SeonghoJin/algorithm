# Write your MySQL query statement below
Select c.name from Candidate c
left join (Select candidateId as id, COUNT(*) as total from Vote v
group by v.candidateId) as t on t.id = c.id
order by t.total desc limit 1