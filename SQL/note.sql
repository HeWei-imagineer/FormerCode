--sql2

select deptno--empno,ename,job,sal,comm,sal+isnull(comm,0)totalincome,'abcd' --select后面跟表达式,只是显示，不改变原表的值
from emp
--from核心目标：为后面语句提供一个表，对数据源进行聚合
--where len(ename)=6--ename like 'S%'--sal between 2500 and 5000--sal>=4000 or sal<=2500 --sal<4000 and sal>2500 --sal<2500 and comm is not null
--like执行效率极低
--通配符:%表示后可接0<=个字符, '_'代表一个字符, '\(可用任意符号表示)'转义字符 "\_%"escape'\'
--where依旧是跟一个表达式,不仅是列
group by deptno desc--asc(默认)


--9.22
--分组属性，原子值，
select deptno,avg(sal)avgsal--,ename--,mgr--+5--,ename--count(*),avg(),sum(),
from emp
group by deptno--,mgr--+5--,ename
--where 分组前过滤行，having 过滤分组后
having avg(sal)>1500
order by avgsal--avg(sal)

--,后的每一项都是一个默认独立的选项
select deptno,count(*)cnt
from emp
where sal>2000
group by deptno
order by cnt,deptno desc

--表的连接,直接生成连接结果,树形结构提高效率
select ename,dname,grade
from emp,dept
where emp.deptno=dept.deptno
group by deptno
order by cnt,deptno desc


--每一个关系运算的输入输出都是一个表
select ename,dname,grade
from emp join dept on emp.deptno=dept.deptno join salgrade on sal>=losal and sal <= hisal

select distinct deptno,dname
from emp

select ename,emp.deptno,dname
from emp join dept on emp.deptno=dept.deptno
--以上均为内连接,满足连接条件的连接

--左,右,全,外连接
select ename,dept.deptno,dname
from emp right join dept on emp.deptno=dept.deptno

select *--count(*)
from dept
from salgrade
from emp

--natrual join 把两个同名属性join在删除相同列
select ename
from emp as a join emp as b on a.empno=b.mgr
where b.ename="Scott"


select *--count(*)
from emp
from salgrade

--natrual join 把两个同名属性join再删除相同列
select a.ename
from emp as a join emp as b on a.empno=b.mgr
where b.ename='SCOTT'
--奇怪，""  '' 有啥区别呐~
--9.26
--出现表的地方都可以出现sql语句

select *
from emp
where deptno not in (10,20,null)--not in (null)导致结果为空
--where ** in  // and // union 

select * from emp where deptno = 10
union
select * from emp where deptno =20

select ename as 'edname' from emp 
union all
select dname from dept 

--并集union(自动去除重复行) 交集intersect 差集except

--子查询(2) subqury
select *
from emp
where deptno=(select deptno from dept where loc='NEW YORK')

select ename
from emp
where deptno in (select deptno from emp group by deptno having avg(sal) > 1500)

select min(avgsal)
from (select avg(sal) as avgsal from emp group by deptno having avg(sal) > 1500)a

select min(avgsal)
from(select avg(sal) as avgsal from emp group by deptno)a

--as生成临时示图，不相关子查询
with t as(
 select avg(sal) as avgsal from emp group by deptno
)
,t2 as()
-- +查询
--***每次执行sql语句的地方读可以放一张表，每次select的也都是一张表

--9.29
--聚集，连接消耗资源
--with生成的临时表必须被使用一次
with deptsal as
(
 select deptno,avg(sal)avgsal
 from emp
 group by deptno
)
,mindeptsal as
(
 select min(avgsal)minsal
 from deptsal
)
,t as
(
 select deptno
 from deptsal
 where avgsal=(select minsal from mindeptsal)
)

select *
from emp
where deptno = (select deptno from t)



--case 两种形式
select emp.*,case --deptno 
				when deptno=10 then 'good dept' 
				when deptno=20 then 'just so so' 
				--when 30 then 'poor dept' 
				--else 'poor dept'
				end destiation   --无对应返回null，可以和聚集函数结合使用
from emp

select emp.*,case
				when comm is null  then 'no comm' 
				else comm
				end comm   
from emp

select ename,sal,isnull(cast(comm as char),'无补助')
from emp

with t as
(
select 10 deptno,'good'dingwei
union
select 20,'normal'
union
select 30,'poor'
)
select emp.*,t.dingwei
from t join emp on t.deptno=emp.deptno

/* any
   all
   some
*/
select * 
from emp
where sal > all(select sal from emp where deptno=30)
select * 
from emp
where sal = any(select sal from emp where deptno=30)--相当于in
select * 
from emp
where sal > some(select sal from emp where deptno=30)


--相关子查询(是否能独立运行),先查外层再适应内层，下例每一行执行一次内部子查询
select dname
from dept
where (select count(*)from emp
		where deptno=dept.deptno)>2

select dname
from dept
where (select count(*)from emp
		where deptno=dept.deptno)=0

select dname
from emp right join dept on dept.deptno=emp.deptno
where emp.deptno is null

--并集union(自动去除重复行) 交集itersect 差集except
select deptno
from dept
except
select deptno
from emp


select dname
from dept
where not exists(select*
           from emp
           where deptno=dept.deptno)

--找到选修了全部课程的学生
--avgsal>2500的职位的部门
with a as
(
select job
from emp
group by job
having avg(sal)>2500
)
,b as
(
select deptno
from emp
where job in (select* from a)
)
select dname
from dept
where deptno in (select* from b )

select *
from emp
where deptno = 10
order by sal desc
union 


--order by 也是一个select子句

order by case when deptno=10 then 1 
			  when deptno=20 then 3
			  when deptno=30 then 2 
              end, sal desc
--select + select(保证只返回一个值) scalar select

create view vw_avgsal as
with a as(select deptno,avg(sal)avgsalDEP
from emp
group by deptno),
b as(select job,avg(sal)avgsalJOB
from emp
group by job)
select ename,sal,avgsalDEP,avgsalJOB
from a join emp on emp.deptno = a.deptno join b on emp.job = b.job

select *
from emp

select ename,sal
		,(select avg(sal)from emp where deptno=t.deptno)avgsalDEP
		,(select avg(sal)from emp where job=t.job)avgsalJOB
from emp t



select dname,deptno
from dept
where not exists(
		select job from emp group by job having avg(sal) > 4500
		except
		select job from emp where deptno=dept.deptno
)

--视图：1.;2.安全管理
select *
from vw_avgsal 

update vw_avgsal
set sal=sal-100

create view vw_emtsal as
select ename,sal from emp
where sal>2500 with check option--限制不可修改

select *
from vw_emtsal

select *
from emp

update vw_emtsal
set sal=sal+100

--创建外键，延迟检查，事务trancaction*****把一个操作序列定义为原子操作
set constrain FK_**   defferable
--defferable申明外键延迟检查
begin transaction
update dept
set deptno=15
where deptno=10

update emp
set deptno=15
where deptno=10
--commit
rollback;


--10.12
--any attrbute that is present in the having clause without being aggregated must appear in the group by clause


begin transaction

update emp set sal=sal*1.5

 
delete from emp
where empno in
(
)
select empno,sal,(select avg(sal)from emp where job=t.job)avgJOBsal
from emp as t 
where sal<(select avg(sal)from emp where job=t.job)
--delete 

select *
from emp as t
where sal>(select avg(sal)from emp where job=t.job)

with avgsal as
( select empno,ename,sal,(select avg(sal)from emp where job=t.job)avgsal
  from emp as t
),
select

--插入表内容
--1
create table emp_sinple(emptno int,ename varchar(30));
insert into emp_sinple select--values()
--2
select -- into emp_sinple(sql server专用)

grant select on emp to xx;     --授予查询权限
revoke select on emp from xx;  --

select *
from emp

--关系代数relation algebra,形式化查询语言，1.不可直接执行；2.需知道步骤
--无子查询
--基础运算：select:(where);  PROJECT:选择列(select); union; setdifference(except); cartestion product(xx,xx); rename
--集合交运算

--连接操作消耗资源多

--10.17
--关系代数运算，像集，除法
--1.半连接
--2.除法
--ER图

--10.22
--update **  set * from 