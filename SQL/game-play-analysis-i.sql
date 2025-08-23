SELECT player_id, MIN(event_date) as first_login from Activity
    Group by player_id