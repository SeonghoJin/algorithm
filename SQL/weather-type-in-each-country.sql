# Write your MySQL query statement below
Select c.country_name, 
    (case 
    when AVG(weather_state) <= 15 then "Cold"
    when AVG(weather_state) >= 25 then "Hot"
    else "Warm"
    end) as weather_type
from Countries c
left join Weather w on c.country_id = w.country_id
where w.day >= '2019-11-01' and w.day < '2019-12-01'
group by w.country_id
