Whereas in the structural modelling we use explicit names of gates such as `xor`, `nand`, etc, dataflow modelling means using the `assign` operation to make the boolean operations directly. 

```verilog
module sum(a, b, cin, sum, cout); 
	input a, b, cin; 
	output sum, cout; 
	assign sum = a ^ b ^ cin;
	assign cout = a | b & a ^ b | cin;
endmodule;
```

