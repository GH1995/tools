--4.1 使用where子句
select prod_name, prod_price
from Products
where prod_price = 3.49;

--4.2 where子句操作符
select prod_name, prod_price
from Products
where prod_price < 10;

select prod_name, prod_price
from Products
where prod_price <= 10;

--不匹配检查
select vend_id, prod_name
from Products
where prod_price <= 10;

select vend_id, prod_name
from Products
where vend_id != 'DLL01';

--范围值检查
select prod_name, prod_price
from Products
where prod_price between 5 and 10;

--空值检查
select prod_name
from Products
where prod_price is null;

select vend_id
from Vendors
where vend_state is null;