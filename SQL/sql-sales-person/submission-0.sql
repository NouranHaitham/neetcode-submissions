-- Write your query below
select sales_person.name
from sales_person
where sales_person.sales_id NOT IN(
    select orders.sales_id
    from orders
    left join company on company.com_id = orders.com_id
    where company.name = 'CRIMSON'
    )
