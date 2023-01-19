/* 2023.Jan.10*/

-- one -- 
SELECT  description
FROM film
WHERE description LIKE '%Feminist%';

-- two --
SELECT title
FROM film
WHERE title LIKE 'P%' 
    OR title LIKE 'S%'
    OR title LIKE 'T%';

-- three --
SELECT amount,payment_id 
FROM payment
WHERE amount = 0.00
ORDER BY payment_id ASC;

-- 4 --
SELECT COUNT(language_id),name
FROM language
GROUP BY name;

-- 5 --
SELECT category_id  
FROM category
WHERE category_id LIKE 'Horror' 
    OR category_id LIKE 'Travel'
    OR category_id LIKE 'Sci-Fi';

-- 6 --
/*
Write a query to represent all the cities their names start with “L” or “M” or “K” and you need to put in order the executed data based on city id and have counted for repetition of the cities’ names
*/
SELECT city_id, city, COUNT(city)
FROM city
WHERE city LIKE 'L%' 
    OR city LIKE 'M%'
    OR city LIKE 'K%'
GROUP BY city_id,city
ORDER BY city_id;


SELECT city.city_id, city.city
FROM city
WHERE city.city LIKE 'L%' 
    OR city.city LIKE 'M%'
    OR city.city LIKE 'K%'
ORDER BY city.city_id;

-- 7 --
/* Write a query to find how many postal codes are totally available under the address table. And also, write a query to make prove there is no repetitive postal code that is probably a mistake in the inserted data.*/
-- SELECT COUNT(DISTINCT postal_code)
-- FROM address;

SELECT postal_code, COUNT(postal_code)
FROM address
WHERE postal_code !=''
GROUP BY postal_code
HAVING COUNT(postal_code) > 1;

-- 8 --
SELECT phone
FROM address
ORDER BY postal_code;

-- 9 --
SELECT first_name, last_name
FROM actor
WHERE first_name LIKE 'Dan'
    OR first_name LIKE 'Ed'
    OR first_name LIKE 'Fay'
    OR last_name LIKE 'Cage'
    OR last_name LIKE 'Chase';

-- 10 --
SELECT first_name, last_name
FROM actor
WHERE (first_name LIKE '%rr%'
    OR first_name LIKE '%ff%'
    OR first_name LIKE '%cc%cc%'
    OR first_name LIKE '%nn%nn%'
    OR first_name LIKE '%pp%pp%')
    OR 
    (last_name LIKE '%rr%'
    OR last_name LIKE '%ff%'
    OR last_name LIKE '%cc%cc%'
    OR last_name LIKE '%nn%nn%'
    OR last_name LIKE '%pp%pp%')
    OR 
    (last_name LIKE 'T%e');


-- 11 --
/* not finished*/
ALTER TABLE film
RENAME COLUMN film_id TO film_id2
RENAME COLUMN title TO title2
RENAME COLUMN description TO description2
RENAME COLUMN release_year TO release_year2;


-- 12 --
SELECT postal_code
FROM address
WHERE postal_code LIKE '____';

-- 13 --
SELECT postal_code
FROM address
WHERE postal_code LIKE '4____'
	OR postal_code LIKE '5____'
	OR postal_code LIKE '6____'
LIMIT 10;
2000*40%*10%
-- 14 --
SELECT language_id, name,
CONCAT(language_id,', ',name) AS "New column"
FROM language
ORDER BY language_id, name DESC;

-- 15 --
SELECT first_name, last_name
FROM actor
WHERE first_name BETWEEN 'D%' -- it is same whether there is %
    AND 'I%';


-- 16 --
/*  FROM L TO Z */
SELECT first_name, last_name, actor_id,
CONCAT(first_name,'_', last_name,'@',actor_id) AS "Mail"
FROM actor
WHERE first_name BETWEEN 'L%' AND 'Z%';

-- 17 -- 
/*17. In the given database, under the actor table, we recently found a mistake with two of the last names. All the people whose first names are either “Ben”, or “Bob”, or “Allen” are coming from one family and are siblings. Therefore, their last names must be adjusted to “Brown”. Then, you need to write a query to show how many Ben, Bob, and Allen we have separately and how many “Brown” as the last name we have in this table.
*/


SELECT COUNT(first_name),
       last_name
FROM actor
WHERE first_name IN ( 'Ben', 'Bob', 'Allen' )
      OR last_name = 'Brown';

UPDATE actor
set last_name = 'Brown'
WHERE first_name IN ( 'Ben', 'Bob', 'Allen' );