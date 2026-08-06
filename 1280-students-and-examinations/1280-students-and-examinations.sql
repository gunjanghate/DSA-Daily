# Write your MySQL query statement below

select s.student_id, s.student_name, b.subject_name, Count(e.student_id) as attended_exams
from  Students s CROSS JOIN Subjects b Left JOIN Examinations e on
s.student_id = e.student_id and b.subject_name = e.subject_name
group by s.student_id, b.subject_name order by s.student_id;