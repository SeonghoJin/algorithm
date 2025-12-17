Select r.athlete_id as id, a.name, GROUP_CONCAT(medal order by medal SEPARATOR ',') as medals from records r
left join games g on g.id = r.game_id
left join athletes a on a.id = r.athlete_id
left join teams t on t.id = r.team_id
left join events e on e.id = r.event_id
where e.event = 'Volleyball Women''s Volleyball' and medal is not null and team = "KOR"
group by r.athlete_id 