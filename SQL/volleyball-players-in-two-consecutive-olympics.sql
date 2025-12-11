With korAthlete AS (Select r.athlete_id, a.name, g.year from records r
left join athletes a on a.id = r.athlete_id
left join events e on e.id = r.event_id
left join teams t on t.id = r.team_id
left join games g on g.id = r.game_id
where e.event = 'Volleyball Women''s Volleyball' and t.team = 'KOR')

select DISTINCT ka.athlete_id as id, ka.name from korAthlete ka
left join korAthlete ka2 on ka2.athlete_id = ka.athlete_id and ka.year = (ka2.year + 4)
where ka2.athlete_id is not null
