
--有些题每一小问都做了显示
--1
create view vw_course as
select course_id from section 
where semester='Spring' and year='2010'
intersect
select course_id from section
group by course_id
having count(distinct year)>=2

select distinct section.course_id,section.sec_id,title
from section join course on section.course_id=course.course_id
     join vw_course on section.course_id=vw_course.course_id


select sum(cast(end_hr as int)*60+cast(end_min as int)-cast(start_hr as int)*60-cast(start_min as int)) total_credit
from section join time_slot on section.time_slot_id=time_slot.time_slot_id
join vw_course on section.course_id=vw_course.course_id

select count(distinct id)number
from  section join teaches on section.course_id=teaches.course_id and section.sec_id=teaches.sec_id 
      and section.semester=teaches.semester and section.year=teaches.year
      join vw_course on section.course_id=vw_course.course_id
--2
select name,sec_id,year,semester,title 
from student full join takes on student.id=takes.id
     full join course on takes.course_id=course.course_id

--3
select name,dept_name--,year,semester,title 
from student full join takes on student.id=takes.id
     full join course on takes.course_id=course.course_id

create view vw_pass_time as 
select student.id,name,dept_name,sec_id,year,semester,course_id,
       (select count(*)-1 from takes
		where id=student.id and course_id=a.course_id 
        )fail_for_pass_time
from student full join takes as a on student.id=a.id

select*
from vw_pass_time

select dept_name,sum(fail_for_pass_time)total_fail_for_pass_time-- dept_name
from vw_pass_time
group by dept_name,fail_for_pass_time
having fail_for_pass_time>-1



select *
from student join takes on student.id=takes.id 

--4
select name,student.id,takes.course_id,takes.sec_id,grade
from student join takes on student.id=takes.id
where student.id in(
select distinct id
from takes as a
where
exists(
select course_id
from course
where dept_name='拳脚学院'
intersect 
select course_id
from takes
where id=a.id
)
and
exists(
select course_id
from course
where dept_name='拳脚学院'
except
select course_id
from takes
where id=a.id
)
)

select count(distinct course_id)numberCourse
from takes
where course_id in(
select course_id
from course
where dept_name='拳脚学院'
)

--5

--以下只是显示没有老师教的课程
select *
from section
where 
exists(
select distinct course_id,sec_id,semester,year
from section
except
--select distinct course_id,sec_id,semester,year
--from takes
select distinct course_id,sec_id,semester,year
from teaches
)
--以下只是显示没有学生选的课程

select course.course_id,sec_id,semester,year,title,credits
from
(select distinct course_id,sec_id,semester,year
from section
except
--select distinct course_id,sec_id,semester,year
--from takes
select distinct course_id,sec_id,semester,year
from takes )a
join course on a.course_id=course.course_id



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

