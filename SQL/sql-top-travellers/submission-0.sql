-- Write your query below
select users.name , 

case
when SUM(rides.distance) is null
then 0
else SUM(rides.distance)
end as "travelled_distance"


from users
left join rides on rides.user_id = users.id
group by users.name
order by travelled_distance DESC, users.name ASC;

