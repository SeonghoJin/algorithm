With activity_cnt as (
    Select COUNT(*) as cnt, f.activity as name from Friends f
    group by f.activity
), active as (
    Select a.name, COALESCE(activity_cnt.cnt, 0) as cnt from Activities a
    left join activity_cnt on a.name = activity_cnt.name
)

select active.name as activity from active
where active.cnt != (Select MAX(activity_cnt.cnt) from activity_cnt) 
and  active.cnt != (Select MIN(activity_cnt.cnt) from activity_cnt)
