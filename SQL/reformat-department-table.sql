# Write your MySQL query statement below
Select distinct d1.id, 
d2.revenue as Jan_Revenue, 
d3.revenue as Feb_Revenue, 
d4.revenue as Mar_Revenue, 
d5.revenue as Apr_Revenue, 
d6.revenue as May_Revenue, 
d7.revenue as Jun_Revenue, 
d8.revenue as Jul_Revenue, 
d9.revenue as Aug_Revenue, 
d10.revenue as Sep_Revenue, 
d11.revenue as Oct_Revenue, 
d12.revenue as Nov_Revenue, 
d13.revenue as Dec_Revenue From Department d1
left join Department d2 on d2.id = d1.id and d2.month ='Jan' 
left join Department d3 on d3.id = d1.id and d3.month ='Feb' 
left join Department d4 on d4.id = d1.id and d4.month ='Mar'
left join Department d5 on d5.id = d1.id and d5.month ='Apr' 
left join Department d6 on d6.id = d1.id and d6.month ='May' 
left join Department d7 on d7.id = d1.id and d7.month ='Jun' 
left join Department d8 on d8.id = d1.id and d8.month ='Jul' 
left join Department d9 on d9.id = d1.id and d9.month ='Aug' 
left join Department d10 on d10.id = d1.id and d10.month ='Sep' 
left join Department d11 on d11.id = d1.id and d11.month ='Oct'
left join Department d12 on d12.id = d1.id and d12.month ='Nov'
left join Department d13 on d13.id = d1.id and d13.month ='Dec'
 
