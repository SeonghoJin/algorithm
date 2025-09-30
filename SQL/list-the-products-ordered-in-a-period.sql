# Write your MySQL query statement below
Select p.product_name, SUM(o.unit) as unit from Orders o
left join Products p on o.product_id = p.product_id
where order_date >= '2020-02-00' and order_date < '2020-03-00'
group by o.product_id
having SUM(o.unit) >= 100
