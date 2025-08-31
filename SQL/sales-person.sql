-- Select name from SalesPerson as s 
-- LEFT JOIN (Select o.sales_id from Orders as o
-- LEFT join Company as c on c.com_id = o.com_id Where c.name = 'RED') as r on s.sales_id = r.sales_id
-- Where r.sales_id is null

SELECT
    s.name
FROM
    salesperson s
WHERE
    s.sales_id NOT IN (SELECT
            o.sales_id
        FROM
            orders o
                LEFT JOIN
            company c ON o.com_id = c.com_id
        WHERE
            c.name = 'RED')
;