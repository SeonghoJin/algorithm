With SaleSpring AS (
    Select * from Sales s
    where s.sale_date >= '2019-01-01' and s.sale_date <= '2019-03-31'
    group by s.product_id
), NotSalesSpring AS (
    Select * from Sales s
    where s.sale_date < '2019-01-01' or s.sale_date > '2019-03-31'
    group by s.product_id
)

Select ss.product_id, p.product_name from SaleSpring ss
left join NotSalesSpring nss on nss.product_id = ss.product_id
left join Product p on p.product_id = ss.product_id
where nss.product_id is null