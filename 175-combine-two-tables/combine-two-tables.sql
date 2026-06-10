# Write your MySQL query statement below

-- to return 
-- first name, last name, city, state of each person

select Person.firstname, Person.lastName, Address.city, Address.state
from Person
left Join Address
on Person.personId=Address.personId