-- Write your query below
select users.name , SUM(COALESCE(rides.distance, 0)) as "travelled_distance"
from users
left join rides on rides.user_id = users.id
group by users.name
order by travelled_distance DESC, users.name ASC;

