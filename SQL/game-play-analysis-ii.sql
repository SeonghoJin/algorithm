SELECT a.player_id, a.device_id From Activity as a
JOIN (Select player_id, MIN(event_date) as first_date from Activity Group by player_id) as b
ON a.player_id = b.player_id AND a.event_date = b.first_date