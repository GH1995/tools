-- 17 创建和操纵表

-- 17.1 创建表

-- 17.1.1 表创建基础
create table Products
(
	prod_id		char(10)	not null,
	vend_id		char(10)	not null,
	prod_name	char(10)	not null,
	prod_price	char(10)	not null,
	prod_desc	varchar(1000)	null
);

-- 17.1.2 使用NULL值
create table Orders
(
	order_num		integer		not null,
	order_date		datetime	not null,
	cust_id			char(10)	not null
);

create table Vendors
(
	vend_id			char(10)	not null,
	vend_name		char(50)	not null,
	vend_address 	char(50)	,
	vend_city		char(50)	,
	vend_state		char(10)	,
	vend_zip		char(10)	,
	vend_country	char(50)
);

-- 17.1.3 指定默认值
create table OrderItems
(
	order_num		integer			not null,
	order_item		integer 		not null,
	prod_id			char(10)		not null,
	quantity		integer 		not null 	default 1,
	item_price		decimal(8, 2)	not null
);

-- 获取系统日期
getdate()		-- SQL server 
current_date()	-- mysql
sysdate() 		-- oracle

-- 17.2 更新表（针对列）

-- 给已知的表增加列
alter table Vendors
add vend_phone char(20);

-- 更改或删除列，增加约束或增加键
alter table Vendors
drop column vend_phone;

-- 17.3 删除表
drop table CustCopy;

-- 17.4 重命名表
