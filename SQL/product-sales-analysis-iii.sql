# Write your MySQL query statement below
select s.product_id, year as first_year, quantity, price from sales s
JOIN (select MIN(year) as min_year, product_id from sales s2 group by s2.product_id) as t on s.year = t.min_year and s.product_id = t.product_id

-- select product_id, year as first_year, quantity, price from sales s
-- where s.year = (select MIN(year) from sales s2 where s.product_id = s2.product_id)
-- order by product_id
