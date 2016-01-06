.load ./lib/libsqlite3_regex.so
CREATE TABLE events(srcport INTEGER, dstport INTEGER, rawmsg STRING, meta_ts DATETIME);
INSERT INTO events values(1851, 443, 'this is a test', '2016-01-03T20:00:00.000Z');
INSERT INTO events values(1123, 80, 'this is another test', '2016-01-03T20:00:00.000Z');
INSERT INTO events values(2232, 8080, 'what test is this?', '2016-01-03T20:00:00.000Z');
SELECT * from events where rawmsg REGEXP 'test\s';
