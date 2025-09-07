# Write your MySQL query statement below
select (select count(*) as total from FriendRequest) as total, (select count(*) as t from (select requester_id from FriendRequest f
LEFT JOIN RequestAccepted r ON f.sender_id = r.requester_id and f.send_to_id = r.accepter_id
group by sender_id, send_to_id
HAVING requester_id is not null) as c) as success