Select c.customer_id  from Customer c
group by c.customer_id
HAVING count( distinct c.product_key) = (Select count(*) from Product)