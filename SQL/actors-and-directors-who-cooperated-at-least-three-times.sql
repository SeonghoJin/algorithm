Select actor_id, director_id From ActorDirector Group by actor_id, director_id
HAVING COUNT(*) >= 3