-- 14 组合查询

-- 14.1 组合查询

-- 在单个查询中从不同的表类似返回结构数据
-- 对单个表执行多个查询，按单个查询返回数据

-- 14.2 创建组合查询
-- 14.2.1 使用union
select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_state in ('IL', 'IN', 'MI');

select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_name = 'Fun4All';

select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_state in ('IL', 'IN', 'MI');
union
select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_name = 'Fun4All';

select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_state in ('IL', 'IN', 'MI')
	or cust_name = 'Fun4All';

-- 14.2.2 union规则

-- 14.2.3 包含或取消重复的行
select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_state in ('IL', 'IN', 'MI');
union all
select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_name = 'Fun4All';

-- 不取消重复行

-- 14.2.4 对组合查询结果排序
select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_state in ('IL', 'IN', 'MI');
union
select 
	cust_name, 
	cust_contact, 
	cust_email
from Customers
where cust_name = 'Fun4All';
order by cust_name, cust_contact;