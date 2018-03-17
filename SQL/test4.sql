
select *
from takes join course on takes.course_id=course.course_id
where select count(*) from course


--1
begin transaction modify
save transaction savepoint1
insert into instructor		
select case  when id in(select id from instructor intersect select id from student) then reverse(id)
             else id
             end id
	 ,name,dept_name='拳脚学院',salary=40000
from student

--2
rollback transaction savepoint1;
--1.2
begin transaction
insert into instructor 
select id+100,name,'拳脚学院' dept_name,40000 salary
from student

delete from instructor
where id in(select id+100 from student)
commit;


--3
save transaction savepoint2

update instructor
set instructor.salary = vw_secid.salary
from instructor join vw_secid on instructor.id=vw_secid.id

create view vw_secid as
select instructor.id,count(sec_id)sum_secid,10000*count(sec_id) salary
from instructor left join teaches on instructor.id=teaches.id
group by instructor.id

select *
from vw_secid 
drop view vw_secid 
rollback transaction savepoint2;
--answer
update instructor set salary=(select count(*)from teaches where id=instructor.id)


--4
--包括grade为null的人
select student.id,name,count(*) 
from student join takes on student.id=takes.id
group by student.id,name,grade
having grade='F' or grade is null
--
with stu_fail as
(select id,course_id from takes where grade='F'
 except
 select id,course_id from takes where grade<>'F'
)
select s.id,s.name,count(*)F_cnt
from stu_fail t join student s on t.id=s.id
group by s.id,s.name

--5
select student.id,name,role='student'
from student left join takes on student.id=takes.id
where takes.id is null
union
select instructor.id,name,role='instructor'
from instructor left join teaches on instructor.id=teaches.id
where teaches.id is null






commit



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
