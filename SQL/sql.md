
- 创建数据库  `create database dbname`

- 删除数据库  `drop database dbname`

- 创建新表 `create table tablename(col1 type1[primary key], col2 type2)`

- 根据已有的表创建新表   create table tablenew like table old
/create table tablenew as select col1,col2 from tableold definition only

- 增加列 `alter table tablename add column coltype`

- 增加主键 `alter table tablename add primary key(col)`

- 删除主键 `alter table tablename drop primary key(col)`

- 创建视图 `create view viewname as select statement`

- 删除视图 `drop view viewname`

- 选择 `select *from table1 where...`

- 范围插入  `insert into table1(field1, field2)`

- 删除 `delete from table1 where ...`

- 范围更新 `update table1 set field1 = 1 where...`

- 范围查找 `select * from table1 where field1 like...`.

- 排序 `select * from table1 order by field1,field2[desc]`

- 总数 `select count * as totalcount from table1`

- 求和 `select sum(field1) as sum from table1`

- 平均 `select avg(field1) as avg from table1`

- 最大 `select max(field1) as max from table1`

- 最小 `select min(field1) as min from table1`

