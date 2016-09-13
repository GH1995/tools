-- 13 创建高级联结

-- 13.1 使用表别名

select 
	rtrim(vend_name) + '(' + rtrim(vend_country) + ')'
	as vend_title
from Vendors
order by vend_name;

select 
	cust_name, 
	cust_contact
from 
	Customers as C,
	Orders as O,
	OrderItems as OI,
where 
	C.cust_id = O.cust_id
	and OI.order_num = O.order_num
	and prod_id = 'RGAN01';

-- 13.2 使用不同类型的联结

-- 13.2.1 自联结
select 
	cust_id, 
	cust_name, 
	cust_contact
from Customers
where cust_name = 
(
	select cust_name
	from Customers
	where cust_contact = 'Jim Jones'
);

select	
	c1.cust_id, 
	c1.cust_name, 
	c1.cust_contact
from 	
	Customers as c1,
	Customers as c2
where 
	c1.cust_name = c2.cust_name
	and c2.cust_contact = 'Jim Jones';


-- 13.2.2 自然联结
select 
	C.*, 
	O.order_num, 
	O.order_date, 
	OI.prod_id, 
	OI.quantity, 
	OI.item_price
from
	Customers as c, 
	Orders as O,
	OrderItems as OI
where
	C.cust_id = O.order_num
	and OI.order_num = O.order_num
	and prod_id = 'RGAN01';


-- 13.2.3 外部联结
select 
	Customers.cust_id, 
	Orders.order_num
from Customers inner join Orders
on 
	Customers.cust_id = Orders.cust_id;

select 
	Customers.cust_id, 
	Orders.order_num
from Customers left outer join Orders
on 
	Customers.cust_id = Orders.cust_id;

select 
	Customers.cust_id, 
	Orders.order_num
from Customers right outer join Orders
on 
	Orders.cust_id = Customers.cust_id;

select 
	Customers.cust_id, 
	Orders.order_num
from Customers, Orders
where Customers.cust_id *= Orders.cust_id;

select 	Customers.cust_id, 
		Orders.order_num
from Customers, Orders
where Orders.cust_id =* Customers.cust_id;

select 	Customers.cust_id, 
		Orders.order_num
from Customers, Orders
where Customers.cust_id (+) = Orders.cust_id;

select 	Customers.cust_id, 
		Orders.order_num
from Orders full outer join Customers
on Orders.cust_id = Customers.cust_id;

-- 13.3 使用带聚集函数的联结
select 
	Customers.cust_id, 
	count(Orders.order_num) as num_ord
from Customers inner join Orders
on Customers.cust_id = Orders.cust_id
group by Customers.cust_id;

select 
	Customers.cust_id, 
	count(Orders.order_num) as num_ord
from Customers left outer join Orders
on Customers.cust_id = Orders.cust_id
group by Customers.cust_id;