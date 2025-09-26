# Write your MySQL query statement below
Select aa.student_id, aa.student_name, sub.subject_name, count(ex.subject_name) as attended_exams from Students aa
cross join Subjects sub
left join Examinations ex on ex.student_id = aa.student_id and sub.subject_name = ex.subject_name
group by aa.student_id, sub.subject_name
order by aa.student_id, sub.subject_name