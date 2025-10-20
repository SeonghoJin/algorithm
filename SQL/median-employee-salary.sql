# Write your MySQL query statement below
With Medians AS (
    Select id, (( count(*) - 1 ) / 2) + 1  as total, company  from Employee e
    group by e.company 
), Ranks AS (
    Select id, salary, company, (ROW_NUMBER() OVER (PARTITION BY company order by salary)) as r from Employee e
)

Select r.id, m.company, r.salary  from Ranks r
left join Medians m on m.company = r.company
and (r.r = Floor(m.total) or r.r = Ceil(m.total) or r.r = m.total)
having m.company is not null