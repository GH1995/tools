-- 9 汇总数据

-- 9.1 聚集函数
avg()
count()
max()
min()
sum()

-- 9.1.1 avg()函数
select avg(prod_price)
as avg_price
from Products;

select avg(prod_price)
as avg_price
where vend_id = 'DLL01';

-- 9.1.2 count()函数
select count(*)
as num_cust
from Customers;

select count(cust_email)
as num_cust
from Customers;

-- 9.1.3 max函数
select max(prod_price)
as max_price
from Products;

-- 9.1.4 min()函数
select min(prod_price)
as min_price
from Products;

-- 9.1.5 sum函数
select sum(quantity)
as items_ordered
from OrderItems
where order_num = 2000;

select sum(item_price*quantity)
as total_price
from OrderItems
where order_num = 20005;

-- 9.2 聚集不同值
select avg(distinct prod_price)
as avg_price
from Products
where vend_id = 'DLL01';

-- 9.3 组合聚集函数
select	count(*) as num_items,
		min(prod_price) as price_min,
		max(prod_price) as price_max,
		avg(prod_price) as price_avg
from Products;

