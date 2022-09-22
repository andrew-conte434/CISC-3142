##Andrew Conte - CISC 3142 - Lab 3 Exercises
###Exercise 2.1
- **short**: integer value with a width of 2^16^
- **int**: integer with a minimum width of 2^16^, can also be 2^32^
- **long**: integer with a minimum width of 2^32^, can also be 2^64^
- **long long**: integer with a minimum width of 2^64^
- **float**: decimal value with 6 figures of precision
- **double**: decimal value with 10 figures of precision
- **unsigned**: variables which cannot be negative (i.e. int between 0 and 2^32^ - 1)
- **signed**: variables which can be negative (i.e. int between -2^16^ and 2^16^ - 1)

###Exercise 2.2
- **rate**: float since this is a percentage which won't need more than 6 sig figures.
- **principal**: unsigned int since this is a nonnegative integer
- **payment**: double since this requires a decimal point and a higher degree of precision

###Exercise 2.3
*Output:*
32
4294967264
32
-32
0
0

###Exercise 2.10
- **global_int**: 0
- **local_int**: undefined
- **global_string**: empty string
- **local_string**: empty string

###Exercise 2.12
**Invalid names:** int catch-22, int 1\_or\_2 = 1

###Exercise 2.13
j = 100

###Exercise 2.14
The program is ==not== legal because int i is being defined in the same scope

###Exercise 2.17
*Output:*
10 10
This is because ri references i, and hence its value is bound to i

###Exercise 2.27
**Legal initializations:** 
`int *const p2 = &i2 //p2 will always point to i2`
`const int *p1 = &i2`
`const int *const p3 = &i2 //constant pointer to a constant reference`
`const int i2 = i, &r = i; //constant value i2 is not being modified`

###Exercise 2.28
`int i, *const cp;` illegal because constant variables must be initialized
`int *p1, *const p2;` illegal because const must be initialized
