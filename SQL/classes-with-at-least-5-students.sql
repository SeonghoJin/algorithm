-- Select b.class From (Select class ,COUNT(*) as cnt From Courses Group by class) as b where b.cnt >= 5;
Select class From Courses Group by class Having COunt(*) >= 5