SELECT t1.name AS Employee
FROM Employee as t1 
JOIN Employee as t2 ON t1.managerid = t2.id
AND t1.salary > t2.salary;

SELECT t1.name AS Employee
FROM Employee as t1 
JOIN Employee as t2 ON t1.managerid = t2.id
WHERE t1.salary > t2.salary;
