# Write your MySQL query statement below
Select p.product_id, SUM(quantity) as total_quantity From Sales s
JOIN Product p on p.product_id = s.product_id 
Group by product_id