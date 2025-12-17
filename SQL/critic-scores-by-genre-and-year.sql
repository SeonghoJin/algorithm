Select gee.name as genre, (Select ROUND(AVG(g.critic_score), 2) as score_2011 from games g
left join genres gr on gr.genre_id = g.genre_id
where critic_score is not null and year = 2011 and gee.genre_id = g.genre_id
group by g.genre_id) as score_2011, 
(Select ROUND(AVG(g.critic_score), 2) as score_2011 from games g
left join genres gr on gr.genre_id = g.genre_id
where critic_score is not null and year = 2012 and gee.genre_id = g.genre_id
group by g.genre_id) as score_2012,
(Select ROUND(AVG(g.critic_score), 2) as score_2012 from games g
left join genres gr on gr.genre_id = g.genre_id
where critic_score is not null and year = 2013 and gee.genre_id = g.genre_id
group by g.genre_id) as score_2013,
(Select ROUND(AVG(g.critic_score), 2) as score_2013 from games g
left join genres gr on gr.genre_id = g.genre_id
where critic_score is not null and year = 2014 and gee.genre_id = g.genre_id
group by g.genre_id) as score_2014,
(Select ROUND(AVG(g.critic_score), 2) as score_2014 from games g
left join genres gr on gr.genre_id = g.genre_id
where critic_score is not null and year = 2015 and gee.genre_id = g.genre_id
group by g.genre_id) as score_2015 from genres gee