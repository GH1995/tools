--5.1 组合where子句

--5.1.1 and操作符
select prod_id, prod_price, prod_name
from Products
where vend_id = 'DLL01' and prod_price <= 4;

--5.1.2 or操作符
select prod_name, prod_price
from Products
where vend_id = 'DLL01' or vend_id = 'BRS01';

--5.1.3 计算次序（and比or高）
select prod_name, prod_price
from Products
where (vend_id = 'DLL01' or vend_id = 'BRS01') and prod_price >= 10;

--5.2 in操作符
select prod_name, prod_price
from Products
where vend_id in ('DLL01', 'BRS01')
order by prod_name;

--5.3 not 操作符
select prod_name
from Products
where not vend_id = 'DLL01'
order by prod_name;

select prod_name
from Products
where not vend_id <> 'DLL01'
order by prod_name;