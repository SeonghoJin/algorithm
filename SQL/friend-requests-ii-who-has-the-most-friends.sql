With Requests as (
    Select requester_id as id, count(accepter_id) as cnt from RequestAccepted
    group by requester_id
), Acceptes as (
    Select accepter_id as id, count(requester_id) as cnt from RequestAccepted
    group by accepter_id
)

Select rid as id, total as num from (Select rid, rcnt+acnt as total, RANK() over (order by rcnt+acnt desc) as ran from (Select r.id as rid, IFNULL(r.cnt, 0) as rcnt, IFNULL(a.id, r.id) as aid, IFNULL(a.cnt, 0) as acnt from Requests r
left join Acceptes a on r.id = a.id
UNION
Select IFNULL(r.id, a.id), IFNULL(r.cnt, 0), a.id, a.cnt from Acceptes a
left join Requests r on r.id = a.id) as t) as r
where r.ran = 1
