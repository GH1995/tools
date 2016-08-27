SQL语法顺序
select [distinct]
from 
where
group by
having
union
order by


执行顺序是
from		--第一步执行
where		--不能在where使用select中设置的别名

group by
having

select		--在from和group之后执行
distinct
union

order by


-- 3、SQL语言的核心是对表的引用(table references)
-- from 语句输出的是一张联合表，笛卡尔积，两个表字段相连接


-- 4、灵活引用能使SQL语句变得更强大
join


-- 5、SQL语句中推荐使用表连接


-- 6、SQL语句中不同的连接操作
equi join
	inner join 
		join
	outer join
		left, right, full outer join

semi join
	in
	exisits

anti join

cross join

division


-- 7、SQL中如同变量的派生表


-- 8、SQL语句中group by是对表的引用进行的操作


-- 9、SQL语句中的select实质上是对关系的映射


-- 10、SQL语句中的几个简单的关键字：distinct, union, order by, offset

