-- Jan 16
CREATE TABLE students 
(student_id int PRIMARY KEY,
first_name varchar(255), 
last_name varchar(255), 
programming varchar(255),
code int);

INSERT INTO students VALUES
(1111,'Allen','Paul','Software Design', 1234);
 
INSERT INTO students VALUES
(9999,'Allen','Paul','Software Design', 1234)
,(2222,'Alex','Paul','Software Design', 1234)
,(3333,'William','sichu','Software Design', 1234)
,(4444,'Paul','Duke','Software Design', 1234)
,(5555,'Wood','silver','Software Design', 1234)
,(6666,'Jason','colt','Software Design', 1234)
,(7777,'Sean','peter','Software Design', 1234)
,(8888,'Dude','will','Software Design', 1234)


SELECT * FROM students;

UPDATE Customers
SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
WHERE CustomerID = 1;

DELETE FROM students WHERE student_id = 9999;

CREATE TABLE student2(
column1 int PRIMARY KEY,
column2 varchar(300)，
column3 varchar(300),
column4 varchar(300),
column5 varchar(300)
);

COPY PUBLIC ."student2" TO '/Users/chang/Desktop/Untitl00.csv'DELIMITER ',' CSV HEADER;

-- ERROR:  could not open file "/Users/chang/Desktop/002" for writing: Permission denied
-- HINT:  COPY TO instructs the PostgreSQL server process to write a file. You may want a client-side facility such as psql's \copy.
-- SQL state: 42501


COPY PUBLIC."student2" TO '/Users/chang/Desktop/002.csv'DELIMITER ',' CSV HEADER;

COPY (select * from contacts where age < 45) TO 'C:tmpyoung_contacts_db.csv'  WITH DELIMITER ',' CSV HEADER;


-- Jan 18 ---
SELECT first_name,
       last_name,
       film.title
FROM actor
    LEFT OUTER JOIN film_actor
        ON film_actor.actor_id = actor.actor_id
    -- WHERE first_name = 'Woody' AND last_name = 'Hoffman'

    LEFT OUTER JOIN film
        ON film.film_id3 = film_actor.film_id
WHERE first_name = 'Woody'
      AND last_name = 'Hoffman'
      AND film.title = 'Snowman Rollercoaster'
ORDER BY 3;

--- get both capital and small charactor
LIKE  'snowman'
LOWER(first_field) = LOWER('name');

WITH SETA AS(
    SELECT 'X' AS A 
    UNION ALL
    SELECT 'Y'
    UNION ALL
    SELECT 'Z')

, SETB AS (
   SELECT '1' AS B
   UNION ALL
   SELECT '2'
   UNION ALL
   SELECT '3'
   )

SELECT A, b
FROM SETA
LEFT JOIN SETB
ON setA.A = setB.b

-- Jan 19 --




