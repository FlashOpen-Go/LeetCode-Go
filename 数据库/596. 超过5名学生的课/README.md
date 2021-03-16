# 596. 超过5名学生的课

## 题目描述
有一个courses 表 ，有: student (学生) 和 class (课程)。

请列出所有超过或等于5名学生的课。



例如：
```
+---------+------------+
| student | class      |
+---------+------------+
| A       | Math       |
| B       | English    |
| C       | Math       |
| D       | Biology    |
| E       | Math       |
| F       | Computer   |
| G       | Math       |
| H       | Math       |
| I       | Math       |
+---------+------------+
```
运行你所编写的更新语句之后，将会得到以下表:
```
+---------+
| class   |
+---------+
| Math    |
+---------+
```

提示
- 学生在每个课中不应被重复计算。




## 代码实现
#### SQL
```Mysql
select t.class from (select  a.class,count(1) ctt from (select distinct class,student from courses) a group by class having ctt>=5) t;
```