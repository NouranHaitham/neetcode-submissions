-- Write your query below
select distinct seller_name
from seller 
left join orders on orders.seller_id = seller.seller_id
where seller.seller_id 
In(select distinct seller_id from orders where Extract(Year from sale_date) <> 2020

except

select distinct seller_id from orders where Extract(Year from sale_date) = 2020
) or order_id is null
order by seller.seller_name ASC;
