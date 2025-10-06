Select a.player_id, a.event_date, SUM(a2.games_played) as games_played_so_far from Activity a
left join Activity a2 on a2.player_id = a.player_id and a.event_date >= a2.event_date
group by player_id, event_date