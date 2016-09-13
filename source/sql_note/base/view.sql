-- ex1:
create view IS_Student as
	select Sno, Sname, Sage
	from Student 
	where Sdept = 'IS';

-- ex3:
create view CS_S1(Sno, Sname, Grade) as
	select Student.Sno, Sname, Grade
	from Student, SC 
	where Sdept = 'CS' and Student.Sno = SC.Sno and SC.Cno = '1';

-- ex4:
create view IS_S2 as
	select Sno, Sname, Grade
	from CS_S1
	where Grade >= 90;

-- ex5:
create view BT_S(Sno, Sname, Sbirth) as
	select Sno, Sname, 2000 - Sage
	from Student;

-- ex6:
create view S_G(Sno, Gavg) as
	select Sno, avg(Grade)
	from SC
	group by Sno;

