# MySQL基本用法

```
# 登陆数据库
MySQL -uroot -p

# 查看数据库
show databases;

# 选择数据库
use xx;

# 查询数据库中的表
show tables;

---------------------------------
# MySQL基本操作创建表
create table test_table
(
	tid 	int(10) 		not null,
	name 	varchar(100) 	not null,
	date 	datetime 		not null 	default '0000-00-00',
	primary key 			(tid)
);
---------------------------------

# 查看表结构
desc test_table;

# 添加列
alter table test_table 
add (age int(3));

# 修改原表结构
alter table test_table 
modify age int(5) not null;

# 修改列的默认值
alter table test_table 
alter age set default '0';

# 去掉列的默认值
alter table test_table 
alter age drop default;

# 删除列
alter table test_table 
drop column age;

# 插入数据
insert into test_table (tid, name, tdate) 
value(1,'yangjuqi','2008-03-21');

# 查询数据
select * 
from test_table;

# 模糊查询
select * 
from test_table 
where name like '%杨%';

# 修改数据
update test_table 
set name = '张三' 
where tid = '2';

# MySQL基本操作删除数据
delete from test_table 
where tid = '2';

# 删除表
drop table test_table;

# 重命名表
alter table test_table 
rename test_tablebak;

# 分页查询(limit 起始行，取多少行)
select * 
from test_tablebak 
limit 2,1;

# 刷新数据库
flush privileges;

# 显示数据库版本
select version();

# 显示当前时间
select current_date;

# 修改用户密码
MySQLadmin -uroot -p  password 

# 将查询出的数据写入文件
select * 
from test_tablebak 
into outfile "test_table.txt" 
fields terminated by ",";

# 查看数据库状态
status;

MySQL基本操作查看所有编码
show variables like 'character_set_%';

# 导入sql文件命令
source MySQL.sql;
