Parser constructs a language with the following grammar rules:
Prog := Sl
Sl := SC { Sl } | Stmt SC { Sl }
Stmt := PrintStmt | PrintlnStmt | RepeatStmt | Expr
PrintStmt := PRINT Expr
PrintlnStmt := PRINTLN Expr
RepeatStmt:= Repeat Expr BEGIN Stmt END
Expr := Sum { EQ Sum }
Sum := Prod { (PLUS | MINUS) Prod }
Prod := Primary { (STAR | SLASH) Primary }
Primary := IDENT | ICONST | SCONST | LPAREN Expr RPAREN

Description of language:

1.The language contains two types: integer and string.
2.The PLUS MINUS STAR and SLASH operators are left associative.
3.The EQ operator is right associative.
4.A Repeat statement evaluates the Expr. The Expr must evaluate to an integer. If theinteger is nonzero, then the Stmt is executed, otherwise it is not.
5.A PrintStmt evaluates the Expr and prints its value.
6.A PrintlnStmt evaluates the Expr and prints its value, followed by a newline character.
7.The type of an IDENT is the type of the value assigned to it.
8.The EQ operator assigns values to variables. It evaluates the Expr on the right hand sideand saves its value in memory associated with the left hand side (an IDENT). If theIDENT does not exist, it is created. If the IDENT already exists, its value is replaced.
9.The PLUS and MINUS operators in Expr represent addition and subtraction.
10.The STAR and SLASH operators in Prod represent multiplication and division.
11.It is an error if a variable is used before a value is assigned to it.
12.Addition is defined between two integers (the result being the sum) or two strings (theresult being the concatenation).
13.Subtraction is defined between two integers (the result being the difference) or twostrings (the result being removal of the first instance of the second string from the firststring, if any).
14.Multiplication is defined between two integers (the result being the product) or for aninteger and a string (the result being the string repeated integer times).
15.Division is defined between two integers.
16.Performing an operation with incorrect types or type combinations is an error.
17.Multiplying a string by a negative integer is an error.
18.A Repeat statement whose Expr is not integer typed is an error

This repository does not specify the exact error messages that should be printed out by the parse; however the format of the message should be the line number, followed by a colon and aspace, followed by some descriptive text. Suggested messages might include “No statements inprogram”, “Missing semicolon”, “Missing END”, etc.

If a parse tree has been generated, it should be traversed to perform various tests.
1.Make sure that a variable has been assigned to (using EQ) before it is used. If you find a variable that was not assigned to, print UNDECLARED VARIABLE followed by a space and the variable name
2.Number of + operators (output format is PLUS COUNT: N, where N is the count of + nodes in the tree)
3.Number of = operators (output format is EQ COUNT: N, where N is the count of = nodes in the tree)
4.Max depth of tree (Format is MAX DEPTH: N, where N is the maximum depth of the tree; the root of the tree is at depth 1)
