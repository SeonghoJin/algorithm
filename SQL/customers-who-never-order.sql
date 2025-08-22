Select name as Customers From Customers as c 
    Where c.id not in (Select customerId from Orders)