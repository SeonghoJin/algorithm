Select a.activity_date as day, count(distinct a.user_id) as active_users from Activity a
where a.activity_date <= '2019-07-27' AND a.activity_date > '2019-07-27' - INTERVAL 30 DAY
group by a.activity_date
order by a.activity_date