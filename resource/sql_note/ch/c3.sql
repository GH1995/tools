--3.1 排序数据
select prod_name
from Products;

select prod_name
from Products;
order by prod_name;

--3.2 按多个列排序
select prod_id, prod_price, prod_name
from Products;
order by prod_price, prod_name;

--3.3 按列位置排序
select prod_id, prod_price, prod_name
from Products;
order by 2, 3;

--3.4 指定排序方向
select prod_id, prod_price, prod_name
from Products;
order by prod_price desc;

select prod_id, prod_price, prod_name
from Products;
order by prod_price desc, prod_name; 		-- descending