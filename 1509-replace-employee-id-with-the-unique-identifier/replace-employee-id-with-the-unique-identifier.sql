# Write your MySQL query statement below
select unique_id,name from Employees left join EmployeeUNI using(id)
#select unique_id,name from Employees as e left join EmployeeUNI as u where  e.id = u.id;