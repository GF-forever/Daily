create table ultimate
(
    id varchar(20) not null primary key,
    stu_name varchar(8) not null,
    age int(4),
    class_name varchar(20),
    profession varchar(40),
    address varchar(50)
);

insert into ultimate values ('202205620239','易',20,'计算机2班','老师','北京市石景山');

SELECT * FROM ultimate;
