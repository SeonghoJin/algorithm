# Write your MySQL query statement below
select sell_date, count(distinct a.product) as num_sold, GROUP_CONCAT(distinct a.product ORDER BY a.product asc SEPARATOR ',') as products from Activities a
group by a.sell_date
