SELECT e.name as Employee FROM Employee as e
    LEFT JOIN Employee as ee ON e.managerId = ee.id
    Where ee.salary < e.salary