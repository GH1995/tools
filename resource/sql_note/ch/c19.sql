-- 19 使用存储过程

-- 19.1 存储过程
execute AddNewProduct(
	'JTS01',
	'Stuffed Eiffel',
	6.49,
	'Plush stuffed toy with the text La Tour Eiffel in red white and blue'
)

-- 19.2为什么要使用存储过程

-- 19.3 执行存储过程

-- 19.4 创建存储过程

-- Oracle
create PROCEDURE MailingListCount
(ListCount OUT NUMBER)
is
BEGIN
	select *
	from Customers
	where not cust_email is null;
	ListCount := SQL%ROWCOUNT;
END;

-- SQL Server
create PROCEDURE MailingListCount
as 
	declare @cnt integer
	select @cnt = count(*)
	from Customers
	where not cust_email is null;
	return @cnt;

-- SQL Server
create PROCEDURE NewOrder @cust_id char(10)
as
-- declare variable for order number
declare @order_num integer
-- get current highest order number
select @order_num = max(order_num)
from Orders
-- determine next order next
select @order_num @order_num + 1
-- insert new order
insert into Orders(
	order_num,
	order_date,
	cust_id,
)
values
(
	@order_num,
	getdate(),
	@cust_id
)
-- return order number
return @order_num;

create PROCEDURE NewOrder @cust_id char(10)
as
-- insert new order
insert into Orders(cust_id)
values(@cust_id)
-- return order number
select order_num = @@IDENTITY;