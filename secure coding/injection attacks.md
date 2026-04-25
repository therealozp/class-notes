a typical server requests goes: 
client -> data -> app -> db
db -> app -> generates a page -> client

using the JDBC (java database connectivity) API

```java
String login = req.getattribute("login");
String pw = req.getattribute("pw");
String pin = req.getattribute("pin");

Connection conn = createConnection();
String q = "SELECT * FROM AcctInfo WHERE login='" + login + "' AND pw='" + pw + "'AND pin=" + pin;

ResultSet rs = conn.execute(q) 
```

we are generating a program (SQL) taking some untrusted input, to generate a new program (the application). when this happens, be very careful. an expected, well-behaved SQL string:

```sql
SELECT * FROM AcctInfo WHERE login='admin' AND pw='abc'AND pin=1234
```

>[!WARNING]
>underline characters where the untrusted input in the SQL query

but, if the `login` variable is something like `"'OR 1=1 -- "`, then the string becomes: 
```sql
SELECT * FROM AcctInfo WHERE login='' OR 1=1 -- AND pw='abc'AND pin=1234
```
and the entire table is compromised.