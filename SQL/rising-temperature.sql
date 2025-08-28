Select w1.id from Weather as w1, Weather as w2
Where w1.recordDate  = DATE_ADD(w2.recordDate, INTERVAL 1 DAY) AND w1.temperature > w2.temperature
