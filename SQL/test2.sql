
--1
select *--id,name
from student 
where student.dept_name like '%功%'

--2
select id,name,tot_cred
from student
where tot_cred > 50 and student.dept_name = '邪门学院' or student.dept_name = '兵器学院'
--answer
select s.id,s.name,sum(credits)tot_credits
from student s join takes t on s.id=t.id
               join course c on t.course_id=c.course_id
where s.dept_name in ('邪门学院','兵器学院')
      and t.grade is not null and t.grade <> 'F'
group by s.id,s.name
having sum(c.credits)>50

--3
select distinct teaches.course_id,course.title
from teaches join course on teaches.course_id = course.course_id
where id = 83821

--4
select sum(credits)tot_credits
from teaches join course on teaches.course_id = course.course_id
where id=83821

--5
select id,sum(credits)tot_credits
from teaches join course on teaches.course_id = course.course_id
group by id
--即使老师没有上课
select s.id,isnull(sum(credits),0)tot_credits
from teaches t right join instructor s on t.id = s.id
               join course c on t.course_id = c.course_id
group by s.id

--为什么重复选择了
select *--salary,name,course.course_id,title
from instructor join teaches on instructor.id = teaches.id 
                join course on teaches.course_id = course.course_id
where instructor.dept_name = '内功学院'
order by salary


--6 考查相关子查询
--一种理解  没有考虑同一门课有两个部门老师授课情况
--黄老邪cn2
select *--course_id,avg(salary)avgsal
from (select *
from instructor
where instructor.dept_name = '内功学院')a join teaches on a.id = teaches.id
group by course_id
order by avgsal


--另一种理解
--为什么选出来的表要加表名 这个是正确的，先计算了每门课老师的平均工资，在选择出被内功学院老师教授的课，但是啰嗦，换相关子查询
select course_id,avgsal
from(select course_id,avg(salary)avgsal
from instructor join teaches on instructor.id = teaches.id
group by course_id)a
where course_id in(select course_id
from instructor join teaches on instructor.id = teaches.id
where instructor.dept_name = '内功学院')
order by avgsal
--answer 为什么这里的相关子查询用s,t会报错
select t.course_id,avg(salary)avgsal,title
from instructor s join teaches t on s.id = t.id
			      join course c on t.course_id = c.course_id
where t.course_id in(select course_id
					 from instructor join teaches on instructor.id = teaches.id
					 where instructor.dept_name='内功学院')
group by t.course_id,title
order by avgsal






where not exists(
	
select id
from teaches
where course_id=instructor.id
except
select id
from instructor
where dept_name = '内功学院'
  
)
group by course_id
order by avgsal


--7
select distinct course.course_id, title
from section join course  on section.course_id = course.course_id
where building = '南疆雨林'

--8
select *
from student 
where id not in(select id from takes )

--9 what are you thinking about? 
select course_id,title
from course
where course_id in(select a.course_id
from takes as a join takes as b on a.id = b.id
where b.grade is null )
--answer
select c.course_id,title
from course c join takes t on c.course_id = t.course_id
where grade is null


--10
select prereq.course_id,a.title as course_title,prereq_id, b.title as prerep_title
from prereq join course as a on prereq.course_id = a.course_id 
            join course as b on prereq.prereq_id = b.course_id

select *
from department
select *
from teaches
select *
from course
select *
from instructor
select *
from student
select *
from advisor
select *
from prereq
select *
from takes
select *
from time_slot
select *
from section
