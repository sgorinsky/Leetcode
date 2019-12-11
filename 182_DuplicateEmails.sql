# Write your MySQL query statement below
select email from (select email, count(*) from person group by email having count(email) > 1) as t1 ;
