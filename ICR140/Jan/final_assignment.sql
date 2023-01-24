CREATE DATABASE students;

CREATE TABLE students_public_information (
	student_id int NOT NULL PRIMARY KEY,
	first_name varchar(255)NOT NULL,
    last_name varchar(255) NOT NULL,
    date_of_birth int NOT NULL,
    gender int NOT NULL
)
INSERT INTO students_public_information VALUES(
1996020002,'Nick'	'Wahlberg',	19960207,	'02')
,(1997030003,	'Ed	Chase',	19970315,'03')
,(1998010004,	'Jennifer',	'Davis',19980106,	'01')
,(1999020005,	'Johnny','Lollobrigida',19990215,	'02')
,(1995030006,	'Bette','Nicholson',19950306,	'03')
,(1996010007,	'Grace','Mostel',19960115,	'01')
,(1997020008,	'Matthew','Johansson',	19970222,	'02')
,(1998030009,	'Joe','Swank',19980315,	'03')
,(1999010010,	'Christian','Gable',19990122,	'01')
,(1995020011,	'Zero','Cage',	19950217,	'02')
,(1996030012,	'Karl','Berry',	19960307,	'03')
,(1997010013,	'Uma','Wood',	19970115,	'01')
,(1995020014,	'Vivien','Bergen',	19950206,	'02')
,(1996030015,	'Cuba','Olivier',	19960315,	'03')
,(1997010016,	'Fred','Costner',	19970106,	'01')
,(1998020017,	'Helen','Voight',	19980217,	'02')
,(1999030018,	'Dan','Torn',	19990315,	'03')
,(1997010019,	'Lucille','Tracy',	19970122,	'01')
,(1998020020,	'Kirsten','Paltrow',	19980217,	'02')


CREATE TABLE students_confidential_information (
- Nationality varchar(255)NOT NULL
- BCID number (it is a 9-digit number)
- Address that includes Unit number, Street Number, Street name, City, Country, and postal code
- Registration Date
- Personal Health Number (for emergency cases)
- Cumulative GPA (out of 4.3)	student_id int NOT NULL PRIMARY KEY,
	first_name varchar(255)NOT NULL,
    last_name varchar(255) NOT NULL,
    date_of_birth int NOT NULL,
    gender int NOT NULL
)


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

INSERT INTO students_confidential_information VALUES
(471675840,161968,'Penelope','Guiness',20210506,4.3,'USA','47 MySakila Drive','Alberta','canada',87788)
,(539758313,902731,'Nick,Wahlberg',20210506,4.3,'USA','8 MySQL Boulevard','QLD','us',65231)
,(177727722,934730,'Ed,Chase',20210506,4.3,'Canada,23 Workhaven Lane','Alberta',canada,87877)
,(675292816,292826,'Jennifer','Davis',20210506,4.3,'USA','1411 Lillydale Drive','LD','us',65535)
,(262076994,860426,'Johnny','Lollobrigida',20210506,4.3,'Japan','1913 Hanoi Way','Nagasaki','uk',35200)
,(694933788,716712,'Bette',Nicholson,20210506,4.3,'Japan','1121 Loja Avenue','California','japan',17886)
,(705800322,657282,'Grace','Mostel',20210506,4.3,'Japan','692 Joliet Street','Attika','korea',83579)
,(876295323,380575,'Matthew','Johansson',20210506,4.3,'Japan','1566 Inegl Manor','Mandalay','us',53561)
,(307703950,647885,'Joe','Swank',20210506,4.3,'Korea','3 Idfu Parkway','Nantou','japan',42399)
,(171822533,687538,'Christian','Gable',20210506,4.3,'Japan','1795 Santiago de Compostela Way','Texas','korea',18743)
,(680428310,465887,'Zero','Cage',20210506,4.3,'Korea','800 Santiago de Compostela Parkway','Central Serbia','us',93896)
,(697760867,695479,'Karl,Berry,20210506,4.3,'Canada','478 Joliet Way,Hamilton','canada',77948)
,(920811325,517338,'Uma,Wood',20210506,4.3,'Canada','613 Korolev Drive','Masqat','us',45844)
,(499352017,990911,'Vivien,Bergen',20210506,4.3,'Korea','1531 Sal Drive,Esfahan','japan',53628)
,(347487831,949312,'Cuba','Olivier',20210506,4.3,'Japan','1542 Tarlac Parkway','Kanagawa','us',55563)
,(889318963,407752,'Fred,Costner',20210506,4.3,'Canada','808 Bhopal Manor','Haryana','korea',10672)
,(212869228,747791,'Helen,Voight',20210506,4.3,'Canada','270 Amroha Parkway','Osmaniy','us',29610)
,(800024380,272573,'Dan,Torn,20210506,4.3,'Canada','770 Bydgoszcz Avenue','California','korea',16266)
,(250767749,144453,'Lucille','Tracy',20210506,4.3,'Canada','419 Iligan Lane','Madhya Pradesh','us',72878)
,(914090181,892775,'Kirsten','Paltrow',20210506,4.3,'Canada','360 Toulouse Parkway','England','canada',54308)


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
VALUES

 (101, 'MSc. in Mechanical Engineering','MS', P2,)
,(102, 'MSc. in software Engineering','MS', P6)
,(103, 'Master of Business Administration','MS', P18)
,(104, 'Master of Architecture', 'MS', P4)
,(105, 'BSc. in Architectural Design', 'BSc', P3)
,(111, 'BSc. in Mechanical Engineering','BSc',  P1)
,(112, 'BSc. in software Engineering','BSc', P5)
,(113, 'Bachelor of Business Administration','BSc', P17)
,(114, 'Bachelor of Literature', 'BSc', P22)
,(121, 'Diploma in Software Design','Diploma', P7)
,(122, 'Diploma in Hardware Design','Diploma', P8)
,(123, 'Diploma in General Programming','Diploma', P9)
,(124, 'Diploma in Building Information Modelling', 'Diploma', P11) 
,(125, 'Diploma in Cyber Security', 'Diploma', P15)
,(126, 'Diploma in Kinesiology', 'Diploma', P13)
,(127, 'Diploma in Accounting', 'Diploma', P14)
,(128, 'Diploma in Art', 'Diploma', P16)
,(129, 'Diploma in Experimental Animation','Diploma', P19) 
,(130, 'Diploma in Communication Design', 'Diploma', P20)
,(131, 'Diploma in Industrial Design', 'Diploma', P21)
,(132, 'Diploma in Education', 'Diploma', P12) 

--  Q6 
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


-- Q
CREATE TABLE faculties(
	program_id int,
	F1_Applied_Science varchar(300),
	F2_Architecture varchar(300),
	F3_Education varchar(300),
	F4_Physical_Health varchar(300),
	F5_Finance varchar(300),
	F6_Art varchar(300)
	
);




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
INSERT INTO branches VALUES
(101,'1st',7165712203,'470 Boksburg Street',161968374,94399,'Dan',646,876295394,663449709,1858624103),
(102,'2nd',6572822850,'1427 A Corua Place',902731223,16744,'Renee',349,3077030263,9472333692,7014573190),
(103,'3rd',3806575226,'479 San Felipe del Progreso Avenue',934707245,61117,'Cuba',361,171833480,99049142,22366673),
(104,'4th',6488569361,'867 Benin City Avenue',19649594,48942,'Warren',295,680420138,1071300143,821972086),
(105,'5th',6352972773,'981 Kumbakonam Place',998009782,76022,'Penelope',280,697767968,4077804223,8007535041),
(106,'6th',4658878070,'1016 Iwakuni Street',665356025,37359,'Liza',200,920811322,565014456,484176933),
(107,'7th',6954796875,'663 Baha Blanca Parkway',6782267005,23616,'Salma',329,499351790,255800636,720998660),
(108,'8th',5173383142,'1860 Taguig Loop',18461851,52535,'Julianne',162,347487378,4274544876,1351178909),
(109,'9th',9909111073,'1816 Bydgoszcz Loop',5252555978,69367,'Scarlett',440,889319672,241832687,198170793),
(110,'10th',9493123333,'587 Benguela Manor',745994958,74428,'Albert',582,212869936,251160471,978987654)


CREATE TABLE advertisement_budget(
    budget_id int PRIMARY KEY,
    faculty varchar(300),
    student_amount int,
    budget int
);


F1, 137
F2, 26
F3, 13
F4, 3
F5, 10
F6, 3

create table register(
	register_id int PRIMARY KEY,
	program_id int,
    program varchar(300),
    student_amount varchar(300),
    branch varchar(300)
)

INSERT INTO register VALUES
(1,'P1','Mechanical Engineering' ,'BSc',8,'1st'),
(2,'P2','Mechanical Engineering','MSc',5,'1st'),
(3,'P3','Architectural Design' ,'BSc',5,'1st'),
(4,'P4','Architecture' ,'Master',4,'1st'),
(5,'P5','software Engineering' ,'BSc',0,'1st'),
(6,'P6','software Engineering' ,'MSc',1,'1st'),
(7,'P1','Mechanical Engineering' ,'BSc' ,9,'2nd'),
(8,'P2','Mechanical Engineering','MSc' ,0,'2nd'),
(9,'P3','Architectural Design' ,'BSc' ,7,'2nd'),
(10,'P4','Architecture' ,'Master' ,0,'2nd'),
(11,'P5','software Engineering' ,'BSc' ,5,'2nd'),
(12,'P6','software Engineering' ,'MSc' ,0,'2nd'),
(13,'P7','Software Design' ,'Diploma' ,0,'2nd'),
(14,'P8','Hardware Design' ,'Diploma' ,1,'2nd'),
(15,'P9','General Programming' ,'Diploma' ,0,'2nd'),
(16,'P8','Hardware Design','Diploma' ,5,'3rd'),
(17,'P9','General Programming','Diploma' ,6,'3rd'),
(18,'P10','Data Science','Master',7,'3rd'),
(19,'P11','Building Information Modelling' ,'Diploma' ,0,'3rd'),
(20,'P12','Education','Diploma' ,5,'3rd'
),(21,'P13','Kinesiology','Diploma' ,1,'3rd'
),(22,'P14','Accounting','Diploma' ,0,'3rd'
),(23,'P15','Cyber Security','Diploma' ,0,'3rd'
),(24,'P16','Art' ,'Diploma' ,0,'3rd'
),(25,'P5','software Engineering' ,'BSc',6,'4th'
),(26,'P6','software Engineering' ,'MSc',0,'4th'
),(27,'P7','Software Design' ,'Diploma' ,7,'4th'
),(28,'P8','Hardware Design' ,'Diploma' ,5,'4th'
),(29,'P1','Mechanical Engineering' ,'BSc',0,'4th'
),(30,'P2','Mechanical Engineering' ,'MSc',1,'4th'
),(31,'P3','Architectural Design' ,'BSc',0,'4th'
),(32,'P3','Architectural Design' ,'BSc',2,'5th'
),(33,'P4','Architecture' ,'Master',2,'5th'
),(34,'P5','software Engineering' ,'BSc',0,'5th'
),(35,'P6','software Engineering' ,'MSc',3,'5th'
),(36,'P10','Data Science','Master',5,'5th'
),(37,'P11','Software Design' ,'Diploma' ,0,'5th'
),(38,'P12','Hardware Design' ,'Diploma' ,1,'5th'
),(39,'P1','Mechanical Engineering' ,'BSc',0,'6th'
),(40,'P2','Mechanical Engineering' ,'MSc',0,'6th'
),(41,'P3','Architectural Design' ,'BSc',0,'6th'
),(42,'P4','Architecture' ,'Master',2,'6th'
),(43,'P5','software Engineering' ,'BSc',0,'6th'
),(44,'P6','software Engineering' ,'MSc',0,'6th'
),(45,'P7','Software Design' ,'Diploma' ,7,'6th'
),(46,'P8','Hardware Design' ,'Diploma' ,0,'6th'
),(47,'P9','General Programming' ,'Diploma' ,5,'6th'
),(48,'P10','Data Science','Master',1,'6th'
),(49,'P11','Building Information Modelling' ,'Diploma' ,5,'6th'
),(50,'P12','Education','Diploma' ,3,'6th'
),(51,'P13','Kinesiology','Diploma' ,0,'6th'
),(52,'P14','Accounting','Diploma' ,0,'6th'
),(53,'P15','Cyber Security','Diploma' ,0,'6th'
),(54,'P16','Art' ,'Diploma' ,0,'6th'
),(55,'P1','Mechanical Engineering' ,'BSc',2,'7th'
),(56,'P2','Mechanical Engineering' ,'MSc',0,'7th'
),(57,'P3','Architectural Design' ,'BSc',0,'7th'
),(58,'P4','Architecture' ,'Master',0,'7th'
),(59,'P5','software Engineering' ,'BSc',0,'7th'
),(60,'P6','software Engineering' ,'MSc',5,'7th'
),(61,'P7','Software Design' ,'Diploma' ,0,'7th'
),(62,'P8','Hardware Design' ,'Diploma' ,4,'7th'
),(63,'P9','General Programming' ,'Diploma' ,1,'7th'
),(64,'P10','Data Science','Master',1,'7th'
),(65,'P11','Building Information Modelling' ,'Diploma' ,1,'7th'
),(66,'P12','Education','Diploma' ,4,'7th'
),(67,'P13','Kinesiology','Diploma' ,0,'7th'
),(68,'P14','Accounting','Diploma' ,0,'7th'
),(69,'P15','Cyber Security','Diploma' ,0,'7th'
),(70,'P16','Art' ,'Diploma' ,3,'7th'
),(71,'P1','Mechanical Engineering' ,'BSc',2,'8th'
),(72,'P2','Mechanical Engineering' ,'MSc',2,'8th'
),(73,'P3','Architectural Design' ,'BSc',2,'8th'
),(74,'P4','Architecture' ,'Master',2,'8th'
),(75,'P5','software Engineering' ,'BSc',2,'8th'
),(76,'P6','software Engineering' ,'MSc',0,'8th'
),(77,'P7','Software Design' ,'Diploma' ,2,'8th'
),(78,'P8','Hardware Design' ,'Diploma' ,0,'8th'
),(79,'P9','General Programming' ,'Diploma' ,0,'8th'
),(80,'P10','Data Science','Master',0,'8th'
),(81,'P11','Building Information Modelling' ,'Diploma' ,0,'8th'
),(82,'P1','Mechanical Engineering' ,'BSc',3,'9th'
),(83,'P2','Mechanical Engineering' ,'MSc',0,'9th'
),(84,'P3','Architectural Design' ,'BSc',0,'9th'
),(85,'P4','Architecture' ,'Master',0,'9th'
),(86,'P5','software Engineering' ,'BSc',3,'9th'
),(87,'P6','software Engineering' ,'MSc',0,'9th'
),(88,'P7','Software Design' ,'Diploma' ,0,'9th'
),(89,'P8','Hardware Design' ,'Diploma' ,0,'9th'
),(90,'P9','General Programming' ,'Diploma' ,3,'9th'
),(91,'P10','Data Science','Master',0,'9th'
),(92,'P11','Building Information Modelling' ,'Diploma' ,0,'9th'
),(93,'P12','Education','Diploma' ,0,'9th'
),(94,'P13','Kinesiology','Diploma' ,2,'9th'
),(95,'P14','Accounting','Diploma' ,4,'9th'
),(96,'P15','Cyber Security','Diploma' ,0,'9th'
),(97,'P16','Art' ,'Diploma' ,0,'9th'
),(98,'P6','software Engineering' ,'MSc',1,'10th'
),(99,'P7','Software Design' ,'Diploma' ,0,'10th'
),(100,'P8','Hardware Design' ,'Diploma' ,6,'10th'
),(101,'P9','General Programming' ,'Diploma' ,7,'10th'
),(102,'P10','Data Science','Master',0,'10th'
),(103,'P11','Building Information Modelling' ,'Diploma' ,0,'10th'
),(104,'P12','Education','Diploma' ,0,'10th'
),(105,'P13','Kinesiology','Diploma' ,0,'10th'
),(106,'P14','Accounting','Diploma' ,6,'10th'
),(107,'P15','Cyber Security','Diploma' ,0,'10th'
),(108,'P16','Art' ,'Diploma' ,0,'10th')


-- Q6 --
SELECT  program_id, COUNT (*) 
FROM register
GROUP BY program_id
ORDER BY program_id;


-- Q7
SELECT program_id, SUM(student_amount) AS total_student FROM register
GROUP BY program_id;

P15 no student

    
insert into advertisement_budget
values
(301, 'F1', 137, 30),
(302,'F2',26,30),
(303,'F3',13,10),
(304,'F4',3,20),
(305,'F5',10,10),
(306,'F6',3,20)

-- where budget_id >0 and budget_id<1000;

-- 12

SELECT branch, SUM(student_amount) 
	AS total_student_01 
FROM register
GROUP BY  branch
ORDER BY branch ASC;

-- Q13
SELECT branch, SUM(student_amount) 
	AS total_student_01 
FROM register
GROUP BY  branch
ORDER BY branch ASC;

-- The following query did not work!!!
-- SELECT program, sum(student_amount) AS total_student_01 
-- FROM (SELECT DISTINCT program AS new_name from register )
-- FROM register
-- GROUP BY  program
-- HAVING branch = '9th' 
-- 	OR branch = '10th'
-- ORDER BY program ASC;

-- Q14


SELECT branch, program, student_amount, sum(DISTINCT program)
FROM register
GROUP BY branch, program, student_amount
HAVING branch = '9th' 
	OR branch = '10th';

select program_id, program, sum(*)
from register
group by program_id, program,branch
HAVING branch = '9th' OR branch = '10th';


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

create table students_program (
	student_id	int primary key,
	first_name	varchar(300),
	last_name	varchar(300),
	date_of_birth	int,
	gender	int,
	branch	varchar(300),
	program	varchar(300),
	degree_grade varchar(300)
)

-- Q15
SELECT student_id, first_name, last_name, gpa
FROM students_program
WHERE program LIKE '%Mechanical Engineering%'
    AND branch  ='8th'
ORDER BY 4 DESC;

SELECT student_id, first_name, last_name, program, branch, gpa
FROM students_program

WHERE (program LIKE '%Mechanical Engineering%')
    OR (branch  = '8th')
ORDER BY gpa ASC;

ALTER TABLE students_program
ADD gpa int;


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



