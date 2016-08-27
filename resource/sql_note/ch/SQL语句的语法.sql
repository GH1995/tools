--SQL语句的语法

-- c.1 alter table 更新已存在表的结构
alter table tablename
(
	add | drop column datatype [null | not null] [constraints],
	add | drop column datatype [null | not null] [constraints],
	...
);



--c.2 commit 用来将事务处理写到数据库
commit [transaction];



--c.3 create index 用于在一个或多个列上创建索引
create index indexname
	on tablename (column, ...);



--c.4 create procedure 用于创建存储过程
create procedure procedurename [parameters] [options]
	as sql statement;

--c.5 create table 用于创建数据库表
create table tablename
(
	column datatype [null | not null] [constraints],
	column datatype [null | not null] [constraints],
	...
);



--c.6 create view 创建一个或多个表上的新视图
create view viewname as
	select columns, ...
	from tables, ...
	[where ...]
	[group by ...]
	[having ...];



--c.7 delete 删除一行或者多行
delete from tablename
	[where ...];



--c.8 drop 永久地删除数据库对象（表、视图、索引等）
drop index | procedure | table | view 	indexname | procedurename | tablename | viewname



--c.9 insert 给表增加行
insert into tablename [(columns, ...)] values (values, ...)



--c.10 insert select 插入select的结果到一个表
insert into tablename [(columns, ...)]
	select columns, ... from tablename, ...
	[where ...];



--c.11 rollback 撤销一个事务处理块
rollback [to savepointname];
--或
rollback transaction;



--c.12 select 从一个或多个表（视图）中检索数据
select columname, ...
from tablename, ...
[where ...]
[union ...]
[group by ...]
[having ...]
[order by ...]



--c.13 update 更新表中的一行或多行
update tablename
	set columname = values, ...
	[where ...];