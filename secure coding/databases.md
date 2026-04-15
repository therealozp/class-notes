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