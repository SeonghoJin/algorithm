# Write your MySQL query statement below

With uniques as (
    Select i1.pid, i1.tiv_2015, i1.tiv_2016 
    from Insurance i1
    left join Insurance i2 on i1.lat = i2.lat and i1.lon = i2.lon
    group by i1.pid
    having count(*) = 1 -- 수정: i2.pid를 세어 위치가 고유한지 확인
), 
same as (
    Select u1.tiv_2016 
    from uniques u1
    left join uniques u2 on u1.tiv_2015 = u2.tiv_2015
    group by u1.pid
    having count(*) >= 2 -- 수정: u2.pid를 세어 tiv_2015가 중복되는지 확인
)

Select ROUND(SUM(tiv_2016), 2) as tiv_2016 from same;