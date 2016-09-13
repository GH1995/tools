-- 11 使用子查询

-- 11.1 子查询

-- 11.2 利用子查询进行过滤

-- 需要列出订购物品RGAN01的所有客户
-- 第一步，检索包含物品RGAN01的所有订单的编号；
-- 第二步，检索具有前一步骤列出的订单编号的所有客户的id；
-- 第三步，检索前一步骤返回的所有用户id的客户信息；

-- 第一步，检索包含物品RGAN01的所有订单的编号；
select order_num
from OrderItems
where prod_id = 'RGAN01';

-- 第二步，检索具有前一步骤列出的订单编号的所有客户的id；
select cust_id
from Orders
where order_num in (20007, 20008)

-- 组合
select cust_id
from Orders
where order_num in 
(
	select order_num
	from OrderItems
	where prod_id = 'RGAN01'
);

-- 第三步，检索前一步骤返回的所有用户id的客户信息；
select cust_name, cust_contact
from Customers
where cust_id in ('1000000004', '1000000005');

-- 组合
select cust_name, cust_contact
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

-- 只能是单列，子查询和性能

-- 11.3 作为计算字段使用子查询
-- 需要显示Customers表中每个客户的订单总数
-- 第一步，从Customers表中检索客户列表
-- 第二步，对于检索出的每个客户，统计其在Orders表中的订单数目

-- 第二步，统计1000000001在Orders表中的订单数目
select  count(*)
as orders
from Orders
where cust_id = '1000000001';


select 	cust_name, 
		cust_state, 
		(
			select count(*)
			from Orders
			where Orders.cust_id = Customers.cust_id
		)
		as orders
from Customers
order by cust_name;