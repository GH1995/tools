-- 12 联结表

-- 供应商信息表Vendors
-- 产品信息 Products(包含V表的主键，id)
-- 分解数据为多个表能更好的存储处理

-- 12.1 联结（join）

-- 12.2 创建联结

-- 等值联结(又称内部联结)
select 
	vend_name, 
	prod_name, 
	prod_price
from Vendors, Products
where Vendors.vend_id = Products.vend_id;


-- 12.2.1 where 子句的重要性

-- 笛卡尔积（没有where联结条件）
select 	
	vend_name, 
	prod_name, 
	prod_price
from Vendors, Products;
-- 不能忘记where子句

-- 12.2.2 内部联结
select 
	vend_name, 
	prod_name, 
	prod_price
from Vendors inner join Products		-- 多了inner join，ANSI SQL推荐
on Vendors.vend_id = Products.vend_id;

-- 12.2.3 联结多个表
select 
	prod_name, 
	vend_name, 
	prod_price, 
	quantity
from OrderItems, Products, Vendors
where 
	Products.vend_id = Vendors.vend_id
	and OrderItems.prod_id = Products.prod_id
	and order_num = 20007;

-- 返回第11章的例子
select 
	cust_name, 
	cust_contact
from Customers
where cust_id in 
(
	select cust_id
	from Orders
	where order_num in 
	(
		select order_num
		from OrderItems
		where prod_id = 'RGAN01'
	)
);

-- 使用联结表查询
select 
	cust_name, 
	cust_contact
from Customers, Orders, OrderItems
where 
	Customers.cust_id = Orders.cust_id
	and OrderItems.order_num = Orders.order_num
	and prod_id = 'RGAN01';