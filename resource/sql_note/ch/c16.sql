-- 16 更新和删除数据

-- 16.1 更新数据
-- 更新表中特定行
-- 更新表中所有行

update Customers
	set cust_email = 'kim@thetoystore.com'
	where cust_id = '100000005';


update Customers
	set cust_contact = 'Sam Roberts',
	set cust_email = 'kim@thetoystore.com'
	where cust_id = '100000005';


-- 删除某个列的值
update Customers
	set cust_email = NULL
	where cust_id = '100000005';


-- 16.2 删除数据
-- 删除行
delete from Customers
	where cust_id = '100000006';


-- 16.3 更新和删除的原则
