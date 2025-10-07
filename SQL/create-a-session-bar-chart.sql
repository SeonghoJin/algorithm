With bins AS (Select "[0-5>" as bin, 0 as t1, 300 as t2
UNION 
Select "[5-10>" as bin, 300 as t1, 600 as t2
UNION
Select "[10-15>" as bin, 600 as t1, 900 as t2
UNION
Select "15 or more" as bin, 900 as t1, 10000000000 as t2
)


select b.bin, COUNT(s.session_id) as total from bins b
left join Sessions s on s.duration >= b.t1 and s.duration < b.t2
group by b.bin


-- SELECT '[0-5>' AS 'bin', SUM(duration/60 < 5) AS 'total'
-- FROM Sessions
-- UNION
-- SELECT '[5-10>' AS 'bin', SUM(duration/60 >= 5 AND duration/60 < 10) AS 'total'
-- FROM Sessions
-- UNION
-- SELECT '[10-15>' AS 'bin', SUM(duration/60 >= 10 AND duration/60 < 15) AS 'total'
-- FROM Sessions
-- UNION
-- SELECT '15 or more' AS 'bin', SUM(duration/60 >= 15) AS 'total'
-- FROM Sessions