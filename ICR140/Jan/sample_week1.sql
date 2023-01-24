--Jan-05
SELECT first_name, last_name, actor_id
FROM actor
WHERE last_name LIKE 'H%s'

-- The letter is not executed
ORDER BY 1 ASC;

-- assignment 3
SELECT first_name, last_name, actor_id
FROM actor
WHERE (first_name LIKE 'B%n' OR first_name LIKE 'B%b')
	AND ((last_name LIKE 'W%m' OR last_name LIKE 'W%s'
		  OR last_name LIKE 'W%t') 
	 	OR(last_name LIKE 'Z%m' OR last_name LIKE 'Z%s'
			OR last_name LIKE 'Z%t'))

ORDER BY 1 ASC;

-- assignment 4
SELECT  actor_id, first_name, last_name
FROM actor
WHERE ((first_name Between 'D' and 'R') 
			AND (
				first_name LIKE '%pp%'
				OR first_name LIKE '%dd%'
				OR first_name LIKE '%rr%'
				OR first_name LIKE '%ee%'
				OR first_name LIKE '%ss%'			
				))
OR ((last_name Between 'D' and 'R') 
			AND (
				last_name LIKE '%pp%'
				OR last_name LIKE '%dd%'
				OR last_name LIKE '%rr%'
				OR last_name LIKE '%ee%'
				OR last_name LIKE '%ss%'	
				))

ORDER BY 1 ASC, 2 ASC, 3 ASC;

-- assignment 5
SELECT  actor_id, first_name, last_name
FROM actor
WHERE ((first_name LIKE 'Ba%' OR first_name LIKE 'Be%') 
	   AND (last_name BETWEEN 'B' and 'K'))
	   OR (actor_id%10=0
			    AND(
					(
					first_name LIKE '%ll%'
					OR first_name LIKE '%rr%'
					OR first_name LIKE '%ee%'
					OR first_name LIKE '%ss%'			
					)
				 OR (
					last_name LIKE '%ll%'
					OR last_name LIKE '%rr%'
					OR last_name LIKE '%ee%'
					OR last_name LIKE '%ss%'	
					)
				)
		   )
ORDER BY 1 ASC, 2 ASC, 3 ASC;


-- Jan - 06
DO $$
--1st step: Declaration of our variables
-- 2nd step: Initialization
DECLARE
    a integer := 10;
    b integer := 20;

BEGIN
IF a > b THEN
    RAISE NOTICE 'a is greater than b';
END IF;

IF a < b THEN
    RAISE NOTICE 'a is less than b';
END IF;

IF a = b THEN
    RAISE NOTICE 'a is equal b';
END IF;

END $$;

-------

SELECT last_name,
count(*)
FROM actor
WHERE last_name > 'A'
GROUP BY last_name
ORDER BY 1;

-- 06 Jan.2023 --

--assignments 6
SELECT COUNT (DISTINCT first_name) AS Repetition_first_name,
COUNT (DISTINCT last_name) AS Repetion_last_name,
COUNT (DISTINCT last_name AND first_name) AS Repetion_full_name
FROM actor;

--Assignment 7
/*In the given database, who are those 2 people who have the name first name and last name?
Write a query to find those two people.*/

select first_name, last_name, count(*)
from actor
group by first_name, last_name
HAVING count(*) > 1;

--Assignment 8
/*In the given database, find all the unique first names from the actor table that occur more than 3 times. Sort the results in ASCENDING order by first name.
*/
SELECT DISTINCT first_name, count(*)
FROM actor
GROUP BY first_name
HAVING count(*) > 3;

--Assignment 9
/* In the given base, execute all the first names and then all the last names that are repeated 3 or 4 times.*/

SELECT first_name, COUNT(*) 
FROM actor
GROUP BY first_name
HAVING (COUNT(first_name) = 3 OR COUNT(first_name) = 4)

union
SELECT last_name, COUNT(*)
FROM actor
GROUP BY last_name
HAVING (COUNT(last_name) = 3 OR COUNT(last_name) = 4);






--

SELECT last_name,
first_name,
CONCAT(first_name,' ', last_name),
CONCAT(last_name,' ', first_name),
CONCAT(first_name,', ',last_name),
first_name || ' ' || last_name,
first_name || ' -- ' || last_name,
CONCAT(first_name, ' ', last_name) AS "Full Name"
FROM actor
ORDER BY last_name
LIMIT 20;