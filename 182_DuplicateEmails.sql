SELECT email FROM (SELECT email, COUNT(*) FROM person GROUP BY email HAVING COUNT(email) > 1) as t1 ;
