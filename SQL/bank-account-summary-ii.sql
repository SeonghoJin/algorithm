# Write your MySQL query statement below
Select u.name as NAME, SUM(t.amount) as BALANCE from Transactions t
left join Users u on u.account = t.account
group by t.account
having SUM(t.amount) >= 10000