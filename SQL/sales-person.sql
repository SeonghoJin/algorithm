Select name from SalesPerson as s 
LEFT JOIN (Select o.sales_id from Orders as o
LEFT join Company as c on c.com_id = o.com_id Where c.name = 'RED') as r on s.sales_id = r.sales_id
Where r.sales_id is null