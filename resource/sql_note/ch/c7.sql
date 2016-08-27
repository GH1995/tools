--7 创建计算字段

--7.1 计算字段

--7.2 拼接字段
select vend_name + '(' + vned_country + ')'		-- Access、SQL Server
from Vendors
order by vend_name; 

select vend_name || '(' || vned_country || ')'	-- Oracle、PostgreSQL
from Vendors
order by vend_name;

select concat(vend_name, '(', 'vned_country', ')') -- MySQL

-- 去掉空格
select rtrim(vend_name) + '(' + rtrim(vned_country) + ')'
from Vendors
order by vend_name;

select rtrim(vend_name) || '(' + rtrim(vned_country) || ')'
from Vendors
order by vend_name;

-- rtrim()去掉右边的空格
-- ltrim()去掉左边的空格
-- trim()去掉两边的空格

-- 别名
select rtrim(vend_name) + '(' + rtrim(vned_country) + ')'
as vend_title
from Vendors
order by vend_name;

select rtrim(vend_name) || '(' + rtrim(vned_country) || ')'
as vend_title
from Vendors
order by vend_name;

-- 执行算术计算
select prod_id, quantity, item_price
from OrderItem
where order_num = 20008;

select prod_id, quantity, item_price, quantity*item_price
as expanded_price
from OrderItem
where order_num = 20008;