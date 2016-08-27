-- 10 分组数据

-- 10.1 数据分组
select 
	count(*) as num_prods
from Products
where vend_id = 'DLL01';

-- 10.2 创建分组
select 	vend_id, 
		count(*) as num_prods
from Products
group by vend_id;

-- 10.3 过滤分组
select 	cust_id, 
		count(*) as orders
from Orders
group by cust_id
having count(*) >= 2;


select 	vend_id,
		count(*) as num_prods
from Products
where prod_price >= 4
group by vend_id
having count(*) >= 2;

select 	vend_id,
		count(*) as num_prods
from Products
group by vend_id
having count(*) >= 2;

-- 10.4 分组和排序
select 	order_num,
		count(*) as items,
from OrderItems
group by order_num
having count(*) >= 3;

select 	order_num,
		count(*) as items
from OrderItems
group by order_num
having count(*) >= 3;