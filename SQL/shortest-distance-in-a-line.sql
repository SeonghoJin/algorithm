SELECT ABS(p1.x - p2.x) as shortest FROM Point as p1, Point as p2
having shortest != 0 order by shortest limit 1;