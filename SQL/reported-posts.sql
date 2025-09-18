# Write your MySQL query statement below
Select extra as report_reason, Count(distinct post_id) as report_count from Actions a
where a.action_date = "2019-07-04"
and a.action = "report"
group by extra