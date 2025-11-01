# Write your MySQL query statement below
With mindates AS (
    Select player_id, MIN(event_Date) as min_date from      Activity a
    group by player_id
), a as (Select COUNT(*) as cnt from Activity a
left join mindates on a.event_date = DATE_ADD(mindates.min_date, INTERVAL 1 DAY) and a.player_id = mindates.player_id
where mindates.player_id is not null)

select ROUND((Select * from a) / (Select COUNT(distinct player_id) from Activity), 2) as fraction


