Select e.name, b.bonus From Employee as e 
LEFT JOIN Bonus as b ON b.empId = e.empId
WHERE b.bonus < 1000 OR b.bonus is NULL