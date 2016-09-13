/*
1、	查询每个学生的学号、姓名、选修的课程名及成绩。
2、	查询与“刘晨”在同一个系学习的学生信息。
3、	求每门课程的选课人数。并按选课人数的降序排列。
4、	对每一个系，求学生的平均年龄，并把结果存入一个新的表avgAge中。
5、	将学生的学号及他的平均成绩定义为一个视图SG，并在SG视图中查询平均成绩在90分以上的学生学号和平均成绩。
6、	对每个同学求出他所获得最高成绩的信息。结果显示：学号、课程名、最高成绩。
7、	将计算机系的所有同学的数据库课程成绩提高5分。
*/

-- 1 查询每个学生的学号、姓名、选修的课程名及成绩。
select S.Sno, S.Sname, C.Cname, SC.Grade
from S, C, SC
where S.Sno = SC.Sno and C.Cno = SC.Cno;

-- 2 查询与“刘晨”在同一个系学习的学生信息。
select S1.*
from S as S1, S S2
where S1.Sdept = S2.Sdept and S2.Sname = '刘晨'
	and S1.Sname != '刘晨';

-- 3 求每门课程的选课人数。并按选课人数的降序排列。
select SC.Cno, count(*) as Number
from SC
group by Cno
order by Number desc;

-- 4 对每一个系，求学生的平均年龄，并把结果存入一个新的表avgAge中。
drop table avgAge;
create table avgAge                           --创建表avgAge
(
	Sdept varchar(10),
	avgAge smallint
);

insert into
	avgAge(Sdept, avgAge)
		select Sdept, avg(Sage)
		from S
		group by Sdept


-- 5 将学生的学号及他的平均成绩定义为一个视图SG，并在SG视图中查询平均成绩在90分以上的学生学号和平均成绩。
-- drop view SG;
create view SG as
	select Sno, avg(Grade) as avg_grade
	from SC
	group by Sno;

select Sno, avg_grade
from SG
where avg_grade > 90;


-- 6 对每个同学求出他所获得最高成绩的信息。结果显示：学号、课程名、最高成绩。
select SC.Sno, C.Cname, max(SC.Grade) as max_grade
from SC, C
where C.Cno = SC.Cno
group by SC.Sno

select 

SELECT Sno, MAX(Grade) FROM SC GROUP BY Sno

create view SCM as
	select Sno, max(Grade) as max_grade
	from SC
	group by Sno;

select SC.Sno, C.Cname, SCM.max_grade
from SCM, SC, C
where C.Cno = SC.Cno and SCM.Sno = SC.Sno; 

create view as SCM
	select Sno, Cno, max(Grade) as max_grade
	from SC
	group by Sno;
select SCM.Sno, C.Cno, SCM.max_grade
from SCM, C
where SCM.Cno = C.Cno;

where SC.Cno = C.Cno

Create view SM(Sno,Smax)            --创建视图SM
as
select S.Sno,MAX(SC.Grade)
from S,C,SC
where S.Sno=SC.Sno and SC.Cno=C.Cno
group by S.Sno;                    --根据Sno分组求最高成绩
go
 select S.Sno,C.Cname,SC.Grade
from S,C,SC,SM
where S.Sno=SM.Sno and S.Sno=SC.Sno and SC.Cno=C.Cno and SC.Grade=SM.Smax;

-- 最后的方法，有瑕疵
create view SM(Sno, Smax) as
	select Sno, max(Grade)
	from SC
	group by Sno;
select SM.Sno, C.Cname, SC.Grade
from C, SC, SM
where SC.Cno = C.Cno and SC.Grade = SM.Smax;

SELECT Sno, Cname, Grade 
FROM SC Y, C
WHERE (C.Cno = Y.Cno) 
	AND Y.Grade IN (
		SELECT MAX(Grade) 
		FROM SC 
		WHERE Sno = Y.Sno 
		GROUP BY Sno
		)

		

-- 7 将计算机系的所有同学的数据库课程成绩提高5分。
update SC
set Grade += 5
where 'CS' = (
	select Sdept
	from S
	where S.Sno = SC.Sno
) and '数据库' = (
	select Cname
	from C
	where C.Cno = SC.Cno
);