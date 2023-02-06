
/* SourseCode_Database_final_assignment */

-- Q1
CREATE TABLE students_public_information (
	student_id int NOT NULL PRIMARY KEY,
	first_name varchar(255)NOT NULL,
    last_name varchar(255) NOT NULL,
    date_of_birth int NOT NULL,
    gender int NOT NULL
)

-- Q2
CREATE TABLE students_confidential_information (
    BCID_number int NOT NULL PRIMARY KEY,
    personal_healthy_number int NOT NULL,
    first_name varchar(255)NOT NULL,
    last_name varchar(255)NOT NULL,
    registration_date int NOT NULL,
    gpa int NOT NULL,
    nationality varchar(255)NOT NULL,
    address varchar(255)NOT NULL,
    city varchar(255)NOT NULL,
    country varchar(255)NOT NULL,
    postal_code int NOT NULL
)

-- Q3
CREATE TABLE programs(
    program_id int PRIMARY KEY,
    program varchar(300),    
    program_code varchar(300) PRIMARY KEY,
    degree_grade varchar(300),
    branch_1 varchar(300),
    branch_2 varchar(300),
    branch_3 varchar(300),    
    branch_4 varchar(300),    
    branch_5 varchar(300),    
    branch_6 varchar(300),
    branch_7 varchar(300),
    branch_8 varchar(300),
    branch_9 varchar(300),
    branch_10 varchar(300)
)

--  Q4 
CREATE TABLE faculties_2(
    faculty_id int PRIMARY KEY,
    faculty varchar(300),    
    faculty_code varchar(300),
)

INSERT INTO faculties_2 VALUES
(101, 'Applied Science','F1'),
(102, 'Architecture','F2'),
(103, 'Education', 'F3'),
(104, 'Physical Health', 'F4'),
(105, 'Finance', 'F5'),
(106, 'Art', 'F6')


CREATE TABLE faculties(
	program_id int PRIMARY KEY,
	F1_Applied_Science varchar(300),
	F2_Architecture varchar(300),
	F3_Education varchar(300),
	F4_Physical_Health varchar(300),
	F5_Finance varchar(300),
	F6_Art varchar(300)	
);

--  Q5
CREATE TABLE branches(
    branch_code int PRIMARY KEY,
    branch varchar(300),    
    phone varchar(300),
    address,varchar(300),
    fax int,
    postal_code int,
    manager varchar(300),
    staff_ID int,
    personal_phone int,
    second_phone_emergency int NOT NULL,
    third_phone int
)

-- Q6
CREATE TABLE advertisement_budget(
    budget_id int PRIMARY KEY,
    faculty varchar(300),
    student_amount int,
    budget int
);

create table register(
	register_id int PRIMARY KEY,
	program_id int FOREIGN KEY REFERENCES faculties(program_id),
    program varchar(300),
    student_amount varchar(300),
    branch varchar(300)
)

SELECT  program_id, COUNT (*) 
FROM register
GROUP BY program_id
ORDER BY program_id;


-- Q7
SELECT program_id, SUM(student_amount) AS total_student FROM register
GROUP BY program_id;

-- P15: no student

-- Q8, Q9, Q10
-- n/a

-- Q11
SELECT * FROM register
WHERE student_amount = 0
ORDER BY branch ASC;

-- 12
SELECT branch, SUM(student_amount) 
	AS total_student 
FROM register
GROUP BY  branch
HAVING SUM(student_amount) < 15
	OR SUM(student_amount) > 30
ORDER BY SUM(student_amount) ASC;

-- Q13
SELECT branch, SUM(student_amount) 
	AS total_student_01 
FROM register
GROUP BY  branch
ORDER BY branch ASC;


-- Q14
SELECT first_name, last_name
FROM students_program
WHERE (program = 'MSc. in software Engineering' 
        AND branch = '6th'
        AND degree_grade = 'MSc')
     OR 
      (program = 'Diploma in Software Design' 
        AND (branch = '4th' OR branch = '5th')
        AND degree_grade = 'Diploma');

-- Q15
SELECT student_id, first_name, last_name, program, branch, gpa
FROM students_program

WHERE (program LIKE '%Mechanical Engineering%')
    AND (branch  = '8th')
ORDER BY gpa ASC;

-- Q16
SELECT program, program_id,student_amount
FROM 4th
FULL OUTER JOIN 5th
ON 4th.program = 5th.program;

-- Q17
SELECT first_name, last_name,gpa
FROM students_program
WHERE program LIKE '%Software Design%'
ORDER BY gpa ASC;

-- Q18
SELECT first_name, last_name,program
FROM students_program
ORDER BY program ASC;



