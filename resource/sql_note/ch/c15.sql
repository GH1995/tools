-- 15 插入数据

-- 15.1 数据插入

-- 15.1.1 插入完整的行

insert into Customers
values
(
	'100000006',
	'Toy Land',
	'123 Any Street',
	'New York',
	'NY',
	'11111',
	'USA',
	NULL,
	NULL
);

insert into Customers
(
	cust_id,
	cust_name,
	cust_address,
	cust_city,
	cust_state,
	cust_zip,
	cust_country,
	cust_contact,
	cust_email
)
values
(
	'100000006',
	'Toy Land',
	'123 Any Street',
	'New York',
	'NY',
	'11111',
	'USA',
	NULL,
	NULL
);

insert into Customers
(
	cust_id,
	cust_email,
	cust_name,
	cust_address,
	cust_city,
	cust_state,
	cust_zip
)
values
(
	'100000006',
	'Toy Land',
	'123 Any Street',
	'New York',
	'NY',
	'11111',
	'USA',
	NULL,
	NULL
);

-- 15.1.2 插入部分行
insert into Customers
(
	cust_id,
	cust_name,
	cust_city,
	cust_state,
	cust_zip,
	cust_country
)
values
(
	'100000006',
	'123 Any Street',
	'New York',
	'NY',
	'11111',
	'USA'
);

insert into Customers
(
	cust_id,
	cust_contact,
	cust_email,
	cust_address,
	cust_city,
	cust_state,
	cust_zip,
	cust_contact
)
select 
	cust_id,
	cust_email,
	cust_name,
	cust_address,
	cust_city,
	cust_state,
	cust_zip,
	cust_country
from CustNew;


-- 15.2 从一个表复制到另一个表
select *
insert into CustCopy
from Customers;

create table CustCopy as
	select * 
	from Customers;