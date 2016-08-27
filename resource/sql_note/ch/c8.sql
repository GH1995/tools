-- 8 使用数据处理函数

-- 8.1 函数

-- 8.2 使用函数

-- 8.2.1 文本处理函数
select vend_name, upper(vend_name)
as vend_name_upcase
from Vendors
order by vend_name;


-- soundex()	语音描述
select cust_name, cust_contact
from Customers
where soundex(cust_contact) = soundex('Michael Green');


-- 8.2.2 日期和时间处理函数

-- SQL Server
select order_num
from Orders
where datepart(yy, order_date) = 2004;

-- PostgreSQL
select order_num
from Orders
where date_part('year', order_date) = 2004;

--MySQL
select order_num
from Orders
where year(order_date) = 2004;

-- Oracle
select order_num
from Orders
where to_number(to_char(order_date, 'YY')) = 2004;

select order_num
from Orders
where order_date between to_date('01-JAN-2004') and to_date(31-DEC-2004);



-- 8.2.3 数值处理函数
abs()
cos()
exp()
pi()
sin()
sqrt()
tan()