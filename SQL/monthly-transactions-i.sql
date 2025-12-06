# Write your MySQL query statement below
Select DATE_FORMAT(t.trans_date, '%Y-%m') as month, t.country, COUNT(*) as trans_count, sum(if(t.state = "approved", 1, 0)) as approved_count, sum(t.amount) as trans_total_amount, sum(if(t.state = "approved", t.amount, 0)) as approved_total_amount from Transactions t
group by t.country, DATE_FORMAT(t.trans_date, '%Y-%m')