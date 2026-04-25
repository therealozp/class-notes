lingo:
- databases: organized collections of data
- DBMS: database management systems. interacts with DB and app to define and manipulate the DB
- relational DB:
	- data is organized into tables (relations)
	- unique key for each row
	- managed by the RDBMS
- SQL: structured query languages. used for relational databases
- NoSQL for non-relational databases
- XML: extensible markup language
- XML DB: document oriented database

every relation in the database has a schema. 
- logical schema: defines types and names
- physical schema: defines data layout with data structures. deals with the low-level details enough to worry about caching
- tables encode entities (objects) and relationships (between identities)

![[Pasted image 20260413162014.png]]

logical schema: Inventory/**SKU: string**,Name:string,Price:float,Brand:string. SQL is case insensitive.

SQL is a DDL (data definition language) and a DML (data manipulation language)

DDL:
```sql
-- creating a table
CREATE TABLE Inventory(SKU varchar(255),
					   Name:varchar(255),
					   Price:float,
					   Brand:varchar(255));

-- deleting a table   
DROP TABLE Inventory;

-- modifying a table
ALTER TABLE Inventory ADD NewCol Type;
ALTER TABLE Inventory DROP COLUMN col;
ALTER TABLE Inventory ALTER COLUMN colName newType;
ALTER TABLE Inventory RENAME oldName newName; 
```

DML:
consider table:

| SKU | Name   | Price | Brand |
| --- | ------ | ----- | ----- |
| 1   | shirt  | 20    | X     |
| 2   | pencil | 2     | X     |
| 3   | shirt  | 30    | Y     |
standard results match the structure of the table.

```sql
-- SQL strings start and end with single apostrophes
INSERT INTO Inventory VALUES('1','Shirt',20,'X');
INSERT INTO Inventory(SKU,Price) VALUES('1',20);

-- deletion
DELETE FROM Inventory; -- delete all rows from table, still retains table
DELETE FROM Inventory WHERE SKU='1'; -- delete all rows that SKU=1

-- price greater than 5, SKU is not '1', and pattern match where
-- shirt is a substring
-- % is a wildcard matching any number of chars
-- _ is a wc matching 1 char
WHERE price > 5 AND SKU <> '1' AND Name LIKE '%shirt%';

-- update clauses
UPDATE Inventory SET price=25 WHERE SKU='1';
```

```SQL
SELECT Name FROM Inventory -- returns all attributes, duplicate included
/*
+ Name +
|shirt |
|pencil|
|shirt |
+ ---- + 
*/
```

```sql
SELECT DISTINCT Name FROM Inventory -- only returns the unique ones
/*
+ Name +
|shirt |
|pencil|
+ ---- + 
*/

-- only returns the unique ones, sorted by alphabetical order
SELECT DISTINCT Name FROM Inventory ORDER BY Name
/*
+ Name +
|penicl|
|shirt |
+ ---- + 
*/


-- returns 2 columns, all rows, sorted by descending price
SELECT DISTINCT Price,Brand FROM Inventory ORDER BY Price DESC 
/*
+ Name +
|shirt |
|pencil|
+ ---- + 
*/

-- only returns 2 rows
SELECT DISTINCT Price,Brand FROM Inventory ORDER BY Price DESC LIMIT 2

-- returns 2 rows, skip 1 rows 
SELECT DISTINCT Price,Brand FROM Inventory ORDER BY Price DESC LIMIT 2 OFFSET 1

-- 
SELECT * FROM Inventory WHERE Name = 'pencil' OR SKU = 1
/*
+ --- + ---- + ----- + ----- +
| SKU | Name | Price | Brand |
| --- | ---- | ----- | ----- |
|  1  | shirt | 20 | X |
|  2  | pencil | 30 | X |
+ --- + ---- + ----- + ----- +
*/

--  unexpected behavior, the numeric value of SKU is aggregated
SELECT count(SKU),Brand FROM Inventory
/*
+ ---------- + ----- +
| count(SKU) | Brand |
| ---------- | ----- |
|     3      |   X   |
+ ---------- + ----- +
*/

SELECT count(SKU),Brand FROM Inventory GROUP BY Brand ORDER BY count(SKU)
/*
+ ---------- + ----- +
| count(SKU) | Brand |
| ---------- | ----- |
|     2      |   X   |
|     1      |   Y   |
+ ---------- + ----- +
*/

-- aliasing a column with AS:
SELECT count(SKU) AS n,Brand FROM Inventory GROUP BY Brand ORDER BY n
/*
+ - + ----- +
| n | Brand |
| - | ----- |
| 2 |   X   |
| 1 |   Y   |
+ - + ----- +
*/

-- set unions, returns only the Name
-- if UNION ALL is used, then duplicated are also included
SELECT Name FROM Inventory where price = 20 UNION
SELECT Name FROM Inventory where price = 30

```

