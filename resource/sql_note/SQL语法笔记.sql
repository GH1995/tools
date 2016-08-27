-- SQL语法笔记

学生表:Student(Sno, Sname, Ssex, Sage, Sdept)
课程表：Course(Cno, Cname, Cpno, Ccredit)
学生选课表：SC(Sno, Cno, Grade)


-- 一些语法

数据查询：select
数据定义：create、drop、alter
数据操纵：insert、update、delete
数据控制：grant、revoke


-- 3.1 模式的定义与删除

-- 一、定义模式

create schema <模式名> authorization <用户名>

-- 二、删除模式
drop schema <模式名> <cascade | restrict>
-- cascade 级联
-- restrict限制

-- 3.2 基本表的定义与删除

-- 一、定义基本表
create table <> 
(
	<列名>, <数据类型>, [列级完整性约束条件],
	<列名>, <数据类型>, [列级完整性约束条件],
	<列名>, <数据类型>, [列级完整性约束条件],
	<列名>, <数据类型>, [列级完整性约束条件],
	...
	[表级完整性约束条件]
);

create table Student
(
	Sno		char(9)		primary key,
	Sname 	char(20) 	unique,
	Ssex	char(2),
	Sage 	smallint,
	Sdept 	char(20)
);


create table Course
(
	Cno 	char(4)		primary key,
	Cname 	char(40),
	Cpno 	char(4),
	Ccredit smallint,
	foreign key Cpno references Course(Cno)
);


create table SC 
(
	Sno		char(9),
	Cno 	char(4),
	Grade 	smallint,

	primary key (Sno, Cno),
	foreign key (Sno) references Student (Sno),
	foreign key (Cno) references Course (CnoC)
);


-- 二、数据类型

char(n)
varchar(n)
int =
smallint
numeric(p, d)	/*p位数字， d位小数*/
real 
double precision 
float(n)
date
time

-- 三、模式与表

-- 显示当前搜索路径
show search_path;

-- dba设置搜索路径
set search_path to "S-T", public;

-- 然后定义表

-- 四、修改表

alter table <表名>
[add 	<新列名>	<数据类型>	[完整性约束]]
[drop 	<完整性约束名>]
[alter 	column 		<列名> 		<数据类型>]

alter table Student
	add S-entrance date;

alter table Student
	alter column Sage int;

alter table Course
	add unique(Cname);

-- 五、删除基本表

drop table <表名>	[restrict | cascade];

drop table Student cascade;


-- 索引的建立与删除
-- 一、建立索引
create [unique] [cluster] index <索引名>
		on <表名> (<列名> [次序]);

create cluster index Stuname
	on Student(Sname);

create unique index Stusno
	on Student(Sno);

create unique index Course
	on Course(Cno);

create unique index SCno 
	on SC(Sno, Cno desc);



-- 二、删除索引
drop index <索引名>;

drop index Stuname;















-- 3.4 数据查询

-- 3.4.2 连接查询
-- 一、等值与非等值连接查询

-- ex 33:
select 
	Student.*, 
	SC.*
from 
	Student, 
	SC
where 
	Student.Sno = SC.Sno;


-- 自然连接
select Student.Sno, Sname.Ssex, Sage, Sdept, Cno, Grade
from Student, SC
where Student.Sno = SC.Sno;

-- 二、自身连接
select 
	First.Cno, 
	Second.Cpno
from 
	Course as First,
	Course as Second
where
	First.Cpno = Second.Cno;


-- 三、外连接
select 
	Student.Sno, 
	Sname, 
	Ssex, 
	Sage, 
	Sdept, 
	Cno, 
	Grade
from
	Student left join SC on (Student.Sno = SC.Sno);

-- 四、复合条件连接
select 
	Student.Sno, 
	Sname
from 
	Student, 
	SC
where
	Student.Sno = SC.Sno 	/*这个条件必须加上*/
	and SC.Cno = '2'
	and SC.Grade > 90;

-- 多表连接
select 
	Student.Sno, 
	Sname, 
	Cname, 
	Grade
from 
	Student, 
	SC, 
	Course
where 
	Student.Sno = SC.Sno 
	and SC.Cno = Course.Cno;

-- 3.4.3 嵌套查询
select 
	Sname
from 
	Student
where 
	Sno in 
	(
		select Sno
		from SC
		where Cno = '2'
	);

-- 一、带有in谓词的子查询
select 
	Sno,
	Sname,
	Sdept
from
	Student
where Sdept in
	(
		select Sdept
		from Student
		where Sname = '刘晨'
	);

select 
	S1.Sno,
	S1.Sname,
	S1.Sdept
from
	Student as S1,
	Student as S2
where
