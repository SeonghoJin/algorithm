Select
  a.first_name as first_name,
  a.last_name as last_name,
  sum(p.amount) as total_revenue
from
  payment p
  left join rental r on r.rental_id = p.rental_id
  left join inventory i on i.inventory_id = r.inventory_id
  left join film_actor fa on fa.film_id = i.film_id
  left join actor a on a.actor_id = fa.actor_id
group by
  a.actor_id
order by
  total_revenue desc
limit 5