with Sales_Iphone as (
    Select p.product_id, s.buyer_id from Sales s
    left join Product p on p.product_id = s.product_id
    Where p.product_name = 'iPhone'
), Sales_S8 as (
    Select p.product_id, s.buyer_id from Sales s
    left join Product p on p.product_id = s.product_id
    Where p.product_name = 'S8'
)

Select distinct s8.buyer_id from Sales_Iphone si
right join Sales_S8 s8 on s8.buyer_id = si.buyer_id
where si.product_id is null