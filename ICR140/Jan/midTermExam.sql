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
/* not finished*/
SELECT city.city_id, city.city
FROM city
WHERE city.city LIKE 'L%' 
    OR city.city LIKE 'M%'
    OR city.city LIKE 'K%'
ORDER BY city.city_id;

-- 7 --
/* not finished*/
SELECT COUNT(DISTINCT postal_code)
FROM address;

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

-- 14 --
SELECT language_id, name,
CONCAT(language_id,', ',name) AS "New column"
FROM language
ORDER BY language_id, name DESC;

-- 15 --
/* not finished* FROM D TO H */

SELECT first_name, last_name
FROM actor
WHERE first_name LIKE 'D%'
    TO first_name LIKE 'I%';


-- 16 --
/* not finished. FROM L TO Z */
SELECT first_name, last_name,actor_id,
CONCAT(first_name,'_', last_name,'@',actor_id) AS "Mail"
FROM actor
WHERE first_name LIKE 'L%'
    OR first_name LIKE 'Z%';

-- 17 -- 
/* not finished*/
SELECT COUNT(first_name), last_name
FROM actor
WHERE first_name = 'Ben' 
	OR first_name = 'Bob' 
	OR first_name = 'Allen' 
	OR last_name = 'Brown'
GROUP BY first_name;