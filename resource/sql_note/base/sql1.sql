/*
    数据查询
        单表查询
        连接查询
        嵌套查询
        集合查询

    数据更新
        插入数据
        修改数据
        删除数据

    视图
        定义视图
        查询视图
        更新视图
*/



/*
    单表查询
*/
-- 选择表中的若干列

-- ex1
select
    Sno,
    Sname
from
    Student;

-- ex2
select
    Sname,
    Sno,
    Sdept
from
    Student;

-- ex3
select *
from Student;

-- ex4
select
    Sname,
    2004 - Sage
from
    Student;

-- ex5
select 
    Sname               as Name,
    'Year of Birth:'    as Birth,
    2004 - Sage         as Birthday,
    lower(Sdept)        as department
from
    Student;

-- 选择表中的若干元组
-- ex6
select
    distinct Sno
from
    SC;

-- ex7
select Sname
from Student
where Sdept = 'CS';


-- ex8:查询所有年龄在20岁以下的学生姓名及其年龄
select Sname, Sno
from Student
where Sage < 20;

-- ex9:查询考试成绩有不及格的学生的学号
select distinct Sno
from SC
where Grade < 60;

-- ex:查询年龄在20~23之间的学生的姓名、系别和年龄
select Sname, Sdept, Sage
from Student
where Sage between 20 and 23;

-- ex12:
select Sname, Sage, Sdept
from Student
where Sdept in ('CS', 'MA', 'IS');

-- ex17:
select Sname, Sno
from Student
where Sname like '_晨%'; /*  SQL Server用一个下划线代替一个汉字  */

-- ex19:
select Cno, Ccredit
from Course
where Cname like ' DB\_Design' escape '\';  /*转义字符*/'

-- ex26:
select count(*)
from Student;

-- ex27:
select count(distinct Sno)
from SC;


/*
    聚集函数不仅可以用于group by语句中
*/
-- ex28:
select avg(Grade)
from SC
where Cno = '1';

-- ex30:
select sum(Ccredit)
from SC, Course
where Sno = '200215121' and SC.Cno = Course.Cno;

-- ex31:
select Cno, count(Sno)
from SC
group by Cno;

-- ex32:
select Sno
from SC
group by Sno
having count(*) >= 3;

/*
    连接运算
    嵌套循环法(NESTED-LOOP)
    首先在表1中找到第一个元组，然后从头开始扫描表2，逐一查找满足连接件的元组，找到后就将表1中的第一个元组与该元组拼接起来，形成结果表中一个元组。
    表2全部查找完后，再找表1中第二个元组，然后再从头开始扫描表2，逐一查找满足连接条件的元组，找到后就将表1中的第二个元组与该元组拼接起来，形成结果表中一个元组。
    重复上述操作，直到表1中的全部元组都处理完毕 

*/

/*
    等值于非等值查询
*/

-- ex33:
select Student.*, SC.*
from Student, SC
where Student.Sno = SC.Sno;

-- ex34:
select Student.Sno, Sname, Ssex, Sage, Sdept, Cno, Grade
from Student, SC
where Student.Sno = SC.Sno;

/*
    自身连接
*/
-- ex35:
select first.Cno, second.Cpno
from Course as first, Course as second
where first.Cpno = second.Cno;

/*
    外连接
*/
-- ex37:
select Student.Sno, Sname
from Student, SC
where Student.Sno = SC.Sno
    and SC.Cno = '2'
    and SC.Grade >= 90;


-- ex38:
select Student.Sno, Sname, Cname, Grade
from Student, SC, Course
where Student.Sno = SC.Sno
    and SC.Cno = Course.Cno;

/*
    嵌套查询
    不相关子查询：
    子查询的查询条件不依赖于父查询
    由里向外 逐层处理。即每个子查询在上一级查询处理之前求解，子查询的结果用于建立其父查询的查找条件。
    相关子查询：子查询的查询条件依赖于父查询
    首先取外层查询中表的第一个元组，根据它与内层查询相关的属性值处理内层查询，若WHERE子句返回值为真，则取此元组放入结果表
    然后再取外层表的下一个元组
    重复这一过程，直至外层表全部检查完为止

*/
-- ex39:
select Sno, Sname, Sdept
from Student
where Sdept in (
    select Sdept
    from Student
    where Sname = '刘晨'
);


select S1.Sno, S1.Sname, S1.Sdept
from Student as S1, Student as S2
where S1.Sdept = S2.Sdept
    and S2.Sname = '刘晨';

select Sno, Sname, Sdept
from Student as S1
where exists (
    select *
    from Student as S2
    where S2.Sdept = S1.Sdept
        and S2.Sname = '刘晨'
);


/*  相关子查询   */
-- ex41:
select Sno, Cno
from SC as x
where Grade >= (
    select avg(Grade)
    from SC y 
    where y.Sno = x.Sno
);



/*
    any\all
*/
-- ex42:
select Sname, Sage
from Student
where 
    Sage < any (
        select Sage
        from Student
        where Sdept = 'CS'
        ) and Sdept != 'CS';

select Sname, Sage
from Student
where Sage < (
    select max(Sage)
    from Student
    where Sdept = 'CS'
) and Sdept != 'CS';

-- ex43:
select Sname, Sage
from Student
where 
    Sage < all (
    select Sage
    from Student
    where Sdept = 'CS'
) and Sdept != 'CS';

/*
    exist
*/
-- ex44:查询所有选修了一号课程的学生姓名
select Sname
from Student
where exists (
    select *
    from SC
    where Sno = Student.Sno and Cno = '1'
    );

select Sname
from Student, SC
where Student.Sno = SC.Sno and SC.Cno = '1';


-- ex46:查询选修了全部课程的学生姓名
select Sname
from Student
where not exists (
    select *
    from Course
    where not exists (
        select *
        from SC
        where Sno = Student.Sno and Cno = Course.Cno
        )
);

-- ex47:
select distinct Sno
from SC as A 
where not exists (
    select *
    from SC as B
    where B.Sno = '200215122' and not exists (
        select *
        from SC as Z
        where Z.Sno = A.Sno and Z.Cno = B.Cno
    )
);


/*
    集合查询
*/
-- ex49:
select *
from Student
where Sdept = 'CS'
union
select *
from Student
where Sage <= 19;

-- ex50:
select *
from Student
where Sdept = 'CS'
intersect
select *
from Student
where Sage <= 19;

-- ex52:
select *
from Student
where Sdept = 'CS'
except
select *
from Student
where Sage <= 19;