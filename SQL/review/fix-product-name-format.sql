# Write your MySQL query statement below
Select TRIM(LOWER(s.product_name)) as product_name, DATE_FORMAT(s.sale_date, '%Y-%m') as sale_date, count(*) as total from Sales s
GROUP BY DATE_FORMAT(s.sale_date, '%Y-%m'), TRIM(LOWER(s.product_name))
order by TRIM(LOWER(s.product_name)) asc, DATE_FORMAT(s.sale_date, '%Y-%m') asc