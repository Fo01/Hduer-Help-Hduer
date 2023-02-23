create database poll;

use poll;

create table poll_results (
  id int not null primary key auto_increment, 
  candidate varchar(30),
  num_votes int
);

insert into poll_results (candidate, num_votes) values
  ('John Smith', 0),
  ('Mary Jones', 0),
  ('Fred Bloggs', 0)
;

grant all privileges
on poll.*
to poll@localhost
identified by 'poll';
