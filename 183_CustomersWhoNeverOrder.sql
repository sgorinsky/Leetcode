SELECT customers.name as 'Customers'
FROM customers
WHERE customers.id NOT IN (SELECT customerid from orders);
