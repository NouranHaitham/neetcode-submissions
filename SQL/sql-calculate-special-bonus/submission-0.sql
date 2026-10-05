select employee_id , salary as bonus
from employees
where employee_id%2 = 1 and name Not like 'M%'

union

select employee_id , 0
from employees
where NOT(employee_id%2 = 1 and name Not like 'M%')
order by employee_id;
