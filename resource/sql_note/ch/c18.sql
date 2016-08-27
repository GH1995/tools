-- 18 使用视图

-- 18.1 视图
-- 18.1.1 为什么使用视图
select 
	cust_name, 
	cust_contact
from Customers, Orders, OrderItems
where
	Customers.cust_id = Orders.cust_id
	and OrderItems.order_num = Orders.order_num
	and prod_id = 'RGAN01';

select 
	cust_name, 
	cust_contact
from ProductCustomers
where
	prod_id = 'RGAN01';

-- 18.1.2 视图的规则和限制
-- 删除更新
-- 禁止order by
-- 计算字段别名


-- 18.2 创建视图

-- 18.2.1 利用视图简化复杂的联结
create view ProductCustomers as
	select 
		cust_name, 
		cust_contact, 
		prod_id
	from Customers, Orders, OrderItems
	where Customers.cust_id = Orders.cust_id
		and OrderItems.order_num = Orders.order_num;

select 
	cust_name, 
	cust_contact
from ProductCustomers
where prod_id = 'RGAN01';


-- 18.2.2 用视图重新格式化检索出的数据
select rtrim(vend_name) + '(' + rtrim(vend_country) + ')'
as vned_title
from Vendors
order by vend_name;

select rtrim(vend_name) || '(' || rtrim(vend_country) || ')'
as vned_title
from Vendors
order by vend_name;

create view VendorLocations as
	select rtrim(vend_name) + '(' + rtrim(vend_country) + ')'
	as vned_title
	from Vendors;

create view VendorLocations as
	select rtrim(vend_name) || '(' || rtrim(vend_country) || ')'
	as vned_title
	from Vendors;

select *
from VendorLocations;

-- 18.2.3 用视图过滤不想要的数据
create view CustomerEMailList as 
	select 
		cust_id, 
		cust_name, 
		cust_email
	from Customers
	where cust_email is not null;

select *
from CustomerEMailList;

-- 18.2.4 使用视图与计算字段

select 
	prod_id, 
	quantity, 
	item_price, 
	quantity*item_price
as expanded_price
from OrderItems
where order_num = 20008;

create view OrderItemsExpanded as
	select 
		order_num, 
		prod_id, 
		quantity, 
		item_price, 
		quantity*item_price as expanded_price
	from OrderItems;

select *
from OrderItemsExpanded
where order_num = 20008;