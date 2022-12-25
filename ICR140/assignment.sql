


SELECT A.CourseName AS instructor, B.CourseName AS Student, C.Name AS course
FROM instructor, Student, course
WHERE A.CourseName == B.CourseName


SELECT course
FROM instructor
LEFT JOIN Student
ON instructor.course = Student.course;



ALTER TABLE instructor RENAME COLUMN phone to hours;


UPDATE instructor
SET Name='soheil'
WHERE id='301';

UPDATE instructor
SET course='HTML', course='CSS'
WHERE id='301',id='303';

ALTER TABLE Student
ADD course;


CREATE TABLE instructorCourse(
    id int NOT NULL,
    courseId int NOT NULL,
    instructorId int,
	PRIMARY KEY (id),
	FOREIGN KEY (id) REFERENCES Student(id)
);


SELECT s.name as Student_name, i.name as instructor_name,c.name as course_name
FROM Student as s
JOIN studentCourse as sc on c.ID=sc.studentID
JOIN instructorCourse as ic on c.ID=ic.instructorID

/*-------DEC 22, 2022-------------*/

SELECT o.OrderID, c.customerNumber, c.CustomerName, p.productName
FROM Customers AS c, Orders AS o, orderdetails AS or, products AS p,

RIGHT JOIN products
ON c.customerNumber = o.customerNumber AND o.orderNumber = or.orderNumber AND or.productCode = p.productCode;


SELECT distinct
    CONCAT(ContactFirstName,'', contactLastName) as customerName,
    productName
FROM Customers

JOIN orders on customers.customerNumber = orders.customerNumber 
JOIN orderdetails on orders.orderNumber = orderdetails.orderNumber 
JOIN products on orderdetails.productCode = products.productCode;


(select 1
union
SELECT 2)
union
(select 1
union
SELECT 2)

SELECT count(*)

SELECT customerName
FROM orders
WHERE orderDate BETWEEN '2003-02-11' and '2003-03-18';
WHERE left(customerName,1) BETWEEN 'C' and 'V'
ORDER by customerName;


insert into classicmodels.customers(customerName)
select name from itd.instructor

select max(amount) as maxAmount, 
min(amount) as minAmount,
avg(amount) as avgAmount
from payments;
