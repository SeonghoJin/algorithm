Select MAX(num) as num from (Select Count(num) as c, num from MyNumbers group by num) as CountNum
where CountNum.c = 1