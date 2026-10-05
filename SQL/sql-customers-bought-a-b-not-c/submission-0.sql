select orders.customer_id ,  customer_name
from customers
join orders on orders.customer_id = customers.customer_id
where product_name = 'A'

Intersect

select orders.customer_id ,  customer_name
from customers
join orders on orders.customer_id = customers.customer_id
where product_name = 'B'


Except

select orders.customer_id ,  customer_name
from customers
join orders on orders.customer_id = customers.customer_id
where product_name = 'C'

order by customer_name;
