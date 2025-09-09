# Write your MySQL query statement below
Select product_name, year, price from Sales s
JOIN Product p ON p.product_id = s.product_id