create table ultimate
(
    id varchar(20) not null primary key,
    stu_name varchar(8) not null,
    age int(4),
    class_name varchar(20),
    profession varchar(40),
    address varchar(50)
);

insert into ultimate values ('202205620244','郭勇志',20,'22级计应2班','学生','河南省平顶山市');

SELECT * FROM ultimate;
