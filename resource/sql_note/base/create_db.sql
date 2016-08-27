-- ex5：建立一个学生表Student
create table Student
(
	Sno		char(9)		primary key,		/*主键*/
	Sname	char(20)	unique,				/*唯一值*/
	Ssex	char(2),
	Sage	smallint,
	Sdept	char(20)
); 


-- ex6：建立一个课程表Course
create table Course
(
	Cno		char(4)		primary key,
	Cname	char(40),
	Cpno	char(4),			/*先修课*/
	Ccredit	smallint,

	foreign key (Cpno) references Course(Cno)
);

-- ex7：建立一个学生选课表SC
create table SC 
(
	Sno		char(9),
	Cno 	char(4),
	Grade	smallint,

	primary key (Sno, Cno),
	foreign key (Sno) references Student(Sno),
	foreign key (Cno) references Course(Cno)
);


-- 填充学生表Student
delete 
from Student

insert into 
	Student(Sno, Sname, Ssex, Sage, Sdept)
	values('200215121', '李勇', '男', 20, 'CS');

insert into 
	Student(Sno, Sname, Ssex, Sage, Sdept)
	values('200215122', '刘晨', '女', 19, 'CS');

insert into 
	Student(Sno, Sname, Ssex, Sage, Sdept)
	values('200215123', '王敏', '女', 18, 'MA');

insert into 
	Student(Sno, Sname, Ssex, Sage, Sdept)
	values('200215125', '张立', '男', 19, 'IS');




-- 填充Course表
delete 
from Course

insert into 
	Course (Cno, Cname, Ccredit)
	values('2', '数学', 2);

insert into 
	Course (Cno, Cname, Ccredit)
	values('6', '数据处理', 2);

insert into 
	Course (Cno, Cname, Cpno, Ccredit)
	values('4', '操作系统', '6', 3);

insert into 
	Course (Cno, Cname, Cpno, Ccredit)
	values('7', 'PASCAL语言', '6', 4);

insert into 
	Course (Cno, Cname, Cpno, Ccredit)
	values('5', '数据结构', '7', 4);

insert into 
	Course (Cno, Cname, Cpno, Ccredit)
	values('1', '数据库', '5', 4);

insert into 
	Course (Cno, Cname, Cpno, Ccredit)
	values('3', '信息系统', '1', 4);



-- 填充SC表
delete 
from SC 

insert into
	SC(Sno, Cno, Grade)
	values('200215121', '1', 92);

insert into
	SC(Sno, Cno, Grade)
	values('200215121', '2', 85);

insert into
	SC(Sno, Cno, Grade)
	values('200215121', '3', 88);

insert into
	SC(Sno, Cno, Grade)
	values('200215122', '2', 90);

insert into
	SC(Sno, Cno, Grade)
	values('200215122', '3', 80);


