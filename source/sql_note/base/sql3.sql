-- ex1:
insert into
	Student (Sno, Sname, Ssex, Sdept, Sage)
	values('200215128', '陈冬', '男', 'IS', 18);

-- ex2:
insert into
	values('200215126', '张成民', '男', 18, 'CS');

-- ex3:
insert into
	Dept_age(Sdept, Avg_age)
		select Sdept, avg(Sage)
		from Student
		group by Sdept;

-- ex5:
update Student
set Sage = 22
where Sno = '200215121';

-- ex6:
update Student
set Sage = Sage + 1;

-- ex7:
update SC 
set Grade = 0
where 'CS' = (
	select Sdept
	from Student
	where Student.Sno = SC.Sno
);