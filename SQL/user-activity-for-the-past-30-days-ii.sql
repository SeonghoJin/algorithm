With distinctSession as (
    Select a.user_id, a.session_id from Activity a
    where a.activity_date > '2019-6-27'
    group by a.user_id, a.session_id
), unique_user as (
    Select count(distinct a.user_id) as user_count from Activity a
    where a.activity_date > '2019-6-27'
)

Select coalesce(ROUND((Select Count(session_id) from distinctSession) /(Select * from unique_user), 2) , 0)as average_sessions_per_user;