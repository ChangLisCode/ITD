/* Jan 10,2023*/

/*
Trailing Comma  Style 
SELECT A,
B,
FROM
Leading Comma Style
SELECT a
,b
,count
FROM
*/

-- COMMENT  IN YOUR QUERIES --
/* (Ctrl + / )or (Command + /), to comment out multiple lines
(Ctrl + .) or ( Command + . ) to undo commenting out of */

-- The name of the section of your queries is called "Documentation" 
/*Author: 
ABOUT: 

CHANGE LOG:
10.JAN. 2023: Chang added actor_id to this SQL
*/


SELECT first_name, last_name, actor_id
count(1)
FROM actor
WHERE last_name IN (
    'Akroyd',
    --'Allen',
    'Ball',
    'Cruise',
    'Jackman'
)
GROUP BY first_name, last_name, actor_id
ORDER BY 2 ASC, 1 ASC;

--
SELECT first_name,
       last_name,
       count(1)
FROM actor
WHERE last_name >= 'Allen'
      AND first_name <> 'Kim'
GROUP BY first_name,
         last_name
HAVING COUNT(1) = 1
       OR COUNT(1) = 2
ORDER BY 1 ASC,
         2 ASC;
/* 
'Cuba Allen', and 'Meryl Allen' is not in the list, 
due to query 'count(1) and count(2) is based on last_name.
and capital 'L' is before 'l' make the difference,so k between L and l.
*/


/*
Format your SQL, Format your own SQL code using this free online
https://www.red-gate.com/website/sql-formatter

SQL style guide - Real sampel project
https://www.sqlstyle.guide/
*/


SELECT Total defects, A, B
FROM table
GROUP BY Total defects, A, B
ORDER BY Total defects DESC
LIMIT 3;
/*
GROUP BY list the column of selected data
ORDER BY make the list in order
*/

SELECT GENDER, FISCAL_YEAR, EMP_ACTIVE
FROM table
GROUP BY GENDER, FISCAL_YEAR, EMP_ACTIVE
ORDER BY FISCAL_YEAR DESC;

--ORDER BY BUSINESS_UNIT, FISCAL_YEAR, FISCAL_PERIOD;


SELECT first_name, last_name,
COUNT(*),
MIN (actor_id) smallest_actor_id,
MAX (actor_id) largest_actor_id,
SUM (actor_id) sum_actor_id,
AVG (actor_id) _actor_id
FROM actor

--WHERE last_name < 'ALLEN'
--AND
--first_name <> 'Kim'

GROUP BY first_name, last_name

--HAVING COUNT(*) = 1
--OR
--COUNT(*) = 2

ORDER BY 1 ASC;

INSERT INTO employee_test VALUES
(1, 'M', '1', '14', '2');

INSERT INTO employeeTest VALUES
(1, 'M', '0001', '2014', '201402');
 
INSERT INTO employeeTest VALUES
(2, 'M', '0001', '2014', '201402');

INSERT INTO employeeTest VALUES
(3, 'F', '0001', '2014', '201403');
 
INSERT INTO employeeTest VALUES
(4, 'M', '0001', '2014', '201404');

(emp_num, gender,business_unit,fisal_year,fiscal_period) VALUES
(1, 'M', '1', '14', '2');

ALTER  TABLE employeeTest TO employee_test

例如 ALTER  TABLE admin_user RENAME TO a_user

