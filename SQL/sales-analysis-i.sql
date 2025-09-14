Select s.seller_id from Sales s
group by s.seller_id HAVING SUM(s.price) = (Select SUM(s.price) as total from Sales s
group by s.seller_id
order by total desc
limit 1)