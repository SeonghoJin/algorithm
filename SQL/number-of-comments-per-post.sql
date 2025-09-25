# Write your MySQL query statement below
With SubIdSet as (
    select distinct sub_id from Submissions 
    where parent_id is null
),
CommentSet as (
    select sub_id, parent_id from Submissions
    where parent_id is not null
    group by sub_id, parent_id
)

Select s.sub_id as post_id, count(ss.parent_id) as number_of_comments from SubIdSet s
left join CommentSet ss on s.sub_id = ss.parent_id
group by post_id
order by post_id