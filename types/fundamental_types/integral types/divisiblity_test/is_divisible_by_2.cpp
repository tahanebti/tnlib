/*
*       Mathematics, Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*
*       Check number is_divisible_by_2 if last digit is even
*
*/
/*

Java’s convention is that equals() must be an equivalence relation.
It must be
■ Reflexive : x.equals(x) is true.

■ Symmetric : x.equals(y) is true if and only if y.equals(x).
■ Transitive : if x.equals(y) and y.equals(z) are true, then so is x.equals(z).
In addition, it must take an Object as argument and satisfy the following properties.
■ Consistent : multiple invocations of x.equals(y) consistently return the same
value, provided neither object is modified.
■ Not null : x.equals(null) returns false.

*/

//Check if the value x in range (1; 5):
if (x > 1 && x < 5) ...

//Check if the value x in range (-∞; 1]   [5; +∞):
if (x <= 1 || x >= 5) ...

//Check if the value of variables a, b, c are the same:
if (a == b && b == c)

//Check if triange with sides a, b, c is right:
if ((a * a + b * b == c * c) ||
    (a * a + c * c == b * b) ||
    (b * b + c * c == a * a))

//Check if there exists a non degenerate triangle with sides a, b, c:
if (a < b + c && b < a + c && c < a + b)





  // not equal to
  if (a != b)
    printf("a is not equal to b\n");
  else 
    printf("a is equal b\n");

