Select s.id, (
    case
        when s.id = (Select COUNT(*) from Seat) and s.id % 2 = 1 then s.student
        when s.id % 2 = 1 then s1.student
        when s.id % 2 = 0 then s2.student
    end
) as student from Seat s
left join Seat s1 on 
s.id % 2 = 1 and s.id + 1 = s1.id 
left join Seat s2 on 
s.id % 2 = 0 and s.id - 1 = s2.id