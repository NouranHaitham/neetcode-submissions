select customers.name
from customers
left join orders on customers.id = orders.customer_id
where orders.id is NULL;
