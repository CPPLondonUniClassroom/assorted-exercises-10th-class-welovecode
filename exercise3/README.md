
C++ London University Session 4
===============================

Exercise 3
----------

A [comma-separated value](https://en.wikipedia.org/wiki/Comma-separated_values)
(CSV) file is a file format used for interchanging tablular data,
particularly in programs like spreadsheets.

Your task for this exercise is to implement a simple CSV parser.

The tricky part is that CSVs can contain *quoted* values. Within a quoted value,
commas are ignored, and do not separate table elements.

For example, the CSV data

```csv
first,second,third
1,2,3
"4,5,6",7,8
```

Contains *three* elements on each line. You will need to work out how to handle
quoted values such as these!

