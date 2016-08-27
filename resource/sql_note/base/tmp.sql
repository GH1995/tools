/*

1、	查询每个学生的学号、姓名、选修的课程名及成绩。
2、	查询与“刘晨”在同一个系学习的学生信息。
3、	求每门课程的选课人数。并按选课人数的降序排列。
4、	对每一个系，求学生的平均年龄，并把结果存入一个新的表avgAge中。
5、	将学生的学号及他的平均成绩定义为一个视图SG，并在SG视图中查询平均成绩在90分以上的学生学号和平均成绩。
6、	对每个同学求出他所获得最高成绩的信息。结果显示：学号、课程名、最高成绩。
7、	将计算机系的所有同学的数据库课程成绩提高5分。

*/

-- ex1
select Student.Sno, Student.Sname, SC.Cno, SC.Grade
from SC, Student
where Student.Sno = SC.Sno;

-- ex2
select *
from Student
where Sdept in (
	select Sdept
	from Student
	where Student.Sname = '刘晨'
) and Sname != '刘晨';

-- ex3
select Cno, count(*) as num
from SC
group by Cno
order by num;

-- ex4
-- 对每一个系，求学生的平均年龄，并把结果存入一个新的表avgAge中

create table avgAge 
(
	Sdept char(20),
	avgage smallint
);

insert into 
	avgAge(Sdept, avgage)
	select Sdept, avg(Sage) as avg_age
	from Student
	group by Sdept;

-- ex5将学生的学号及他的平均成绩定义为一个视图SG，并在SG视图中查询平均成绩在90分以上的学生学号和平均成绩。
create view SG 
();
