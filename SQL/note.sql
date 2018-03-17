--sql2

select deptno--empno,ename,job,sal,comm,sal+isnull(comm,0)totalincome,'abcd' --select��������ʽ,ֻ����ʾ�����ı�ԭ���ֵ
from emp
--from����Ŀ�꣺Ϊ��������ṩһ����������Դ���оۺ�
--where len(ename)=6--ename like 'S%'--sal between 2500 and 5000--sal>=4000 or sal<=2500 --sal<4000 and sal>2500 --sal<2500 and comm is not null
--likeִ��Ч�ʼ���
--ͨ���:%��ʾ��ɽ�0<=���ַ�, '_'����һ���ַ�, '\(����������ű�ʾ)'ת���ַ� "\_%"escape'\'
--where�����Ǹ�һ�����ʽ,��������
group by deptno desc--asc(Ĭ��)


--9.22
--�������ԣ�ԭ��ֵ��
select deptno,avg(sal)avgsal--,ename--,mgr--+5--,ename--count(*),avg(),sum(),
from emp
group by deptno--,mgr--+5--,ename
--where ����ǰ�����У�having ���˷����
having avg(sal)>1500
order by avgsal--avg(sal)

--,���ÿһ���һ��Ĭ�϶�����ѡ��
select deptno,count(*)cnt
from emp
where sal>2000
group by deptno
order by cnt,deptno desc

--�������,ֱ���������ӽ��,���νṹ���Ч��
select ename,dname,grade
from emp,dept
where emp.deptno=dept.deptno
group by deptno
order by cnt,deptno desc


--ÿһ����ϵ����������������һ����
select ename,dname,grade
from emp join dept on emp.deptno=dept.deptno join salgrade on sal>=losal and sal <= hisal

select distinct deptno,dname
from emp

select ename,emp.deptno,dname
from emp join dept on emp.deptno=dept.deptno
--���Ͼ�Ϊ������,������������������

--��,��,ȫ,������
select ename,dept.deptno,dname
from emp right join dept on emp.deptno=dept.deptno

select *--count(*)
from dept
from salgrade
from emp

--natrual join ������ͬ������join��ɾ����ͬ��
select ename
from emp as a join emp as b on a.empno=b.mgr
where b.ename="Scott"


select *--count(*)
from emp
from salgrade

--natrual join ������ͬ������join��ɾ����ͬ��
select a.ename
from emp as a join emp as b on a.empno=b.mgr
where b.ename='SCOTT'
--��֣�""  '' ��ɶ������~
--9.26
--���ֱ�ĵط������Գ���sql���

select *
from emp
where deptno not in (10,20,null)--not in (null)���½��Ϊ��
--where ** in  // and // union 

select * from emp where deptno = 10
union
select * from emp where deptno =20

select ename as 'edname' from emp 
union all
select dname from dept 

--����union(�Զ�ȥ���ظ���) ����intersect �except

--�Ӳ�ѯ(2) subqury
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

--as������ʱʾͼ��������Ӳ�ѯ
with t as(
 select avg(sal) as avgsal from emp group by deptno
)
,t2 as()
-- +��ѯ
--***ÿ��ִ��sql���ĵط������Է�һ�ű�ÿ��select��Ҳ����һ�ű�

--9.29
--�ۼ�������������Դ
--with���ɵ���ʱ����뱻ʹ��һ��
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



--case ������ʽ
select emp.*,case --deptno 
				when deptno=10 then 'good dept' 
				when deptno=20 then 'just so so' 
				--when 30 then 'poor dept' 
				--else 'poor dept'
				end destiation   --�޶�Ӧ����null�����Ժ;ۼ��������ʹ��
from emp

select emp.*,case
				when comm is null  then 'no comm' 
				else comm
				end comm   
from emp

select ename,sal,isnull(cast(comm as char),'�޲���')
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
where sal = any(select sal from emp where deptno=30)--�൱��in
select * 
from emp
where sal > some(select sal from emp where deptno=30)


--����Ӳ�ѯ(�Ƿ��ܶ�������),�Ȳ��������Ӧ�ڲ㣬����ÿһ��ִ��һ���ڲ��Ӳ�ѯ
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

--����union(�Զ�ȥ���ظ���) ����itersect �except
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

--�ҵ�ѡ����ȫ���γ̵�ѧ��
--avgsal>2500��ְλ�Ĳ���
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


--order by Ҳ��һ��select�Ӿ�

order by case when deptno=10 then 1 
			  when deptno=20 then 3
			  when deptno=30 then 2 
              end, sal desc
--select + select(��ֻ֤����һ��ֵ) scalar select

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

--��ͼ��1.;2.��ȫ����
select *
from vw_avgsal 

update vw_avgsal
set sal=sal-100

create view vw_emtsal as
select ename,sal from emp
where sal>2500 with check option--���Ʋ����޸�

select *
from vw_emtsal

select *
from emp

update vw_emtsal
set sal=sal+100

--����������ӳټ�飬����trancaction*****��һ���������ж���Ϊԭ�Ӳ���
set constrain FK_**   defferable
--defferable��������ӳټ��
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

--���������
--1
create table emp_sinple(emptno int,ename varchar(30));
insert into emp_sinple select--values()
--2
select -- into emp_sinple(sql serverר��)

grant select on emp to xx;     --�����ѯȨ��
revoke select on emp from xx;  --

select *
from emp

--��ϵ����relation algebra,��ʽ����ѯ���ԣ�1.����ֱ��ִ�У�2.��֪������
--���Ӳ�ѯ
--�������㣺select:(where);  PROJECT:ѡ����(select); union; setdifference(except); cartestion product(xx,xx); rename
--���Ͻ�����

--���Ӳ���������Դ��

--10.17
--��ϵ�������㣬�񼯣�����
--1.������
--2.����
--ERͼ

--10.22
--update **  set * from 