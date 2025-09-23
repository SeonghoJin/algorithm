with FriendRequestCount AS (
    Select Count(distinct sender_id, send_to_id) from FriendRequest
), RequestAcceptCount AS (
    Select Count(distinct requester_id, accepter_id) from RequestAccepted
)

Select ROUND(IFNULL((Select * from RequestAcceptCount) / (Select * from FriendRequestCount), 0), 2) as accept_rate