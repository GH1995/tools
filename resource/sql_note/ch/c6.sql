--6.1 like操作符

--6.1.1 百分号(%)通配符_*
select prod_id, prod_name
from Products
where prod_name like 'Fish%';

select prod_id, prod_name
from Products
where prod_name like '%bean bag%';

select prod_name
from Products
where prod_name like 'F%y';

--6.1.2 下划线(_)通配符_?
select prod_id, prod_name
from Products
where prod_name like '__ inch teddy bear';

select prod_id, prod_name
from Products
where prod_name like '% inch teddy bear';

--6.1.3 方括号([])通配符 	指定一个字符集
select cust_contact
from Customer
where cust_contact like '[JM]%'
order by cust_contact;

select cust_contact
from Customer
where cust_contact like '[^JM]%'
order by cust_contact;