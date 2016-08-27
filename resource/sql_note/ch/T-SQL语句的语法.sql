-- T-SQL语句的语法

c.1 begin transaction
begin transaction;

c.2 alter table
alter table tablename
(
	add		column		datatype		[null | not null]		[constraints],
	alter	column columns	datatype 	[null | not null]		[constraints],
	drop	column,
	...
);

c.3 commit transaction
commit transaction;

c.4 create index
create index indexname
	on tablename (column [asc | desc], ...);

c.5 create login
create login loginname;

c.6 create procedure
create procedure procedurename
	[parameters]
	as
	begin
	...
	end;

c.7 create table
create table tablename
(
	column 		datatype		[null | not null]		[constraints],
	column 		datatype		[null | not null]		[constraints],
	...
);

c.8 create view
create view viewname
	as
	select ...;

c.9 delete
delete from tablename
	where ...;

c.10 drop
drop database | index | login | procedure | table | view
itemname;

c.11 insert
insert into tablename [(columns, ...)]
	values(values, ...);

c.12 insert select
insert into tablename [(columns, ...)]
	select columns, ... from tablename, ...
	[where ...];

c.13 rollback transaction
rollback [savepointname];

c.14 save transaction
save transaction sp1;

c.15 select
select columnname, ...
from tablename, ...
[where ...]
[union ...]
[group by ...]
[having ...]
[order by ...]

c.16 update
update tablename
	set columnname = values, ...
	[where ...];