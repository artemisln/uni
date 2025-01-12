Each shift to the left doubles the number, therefore each left shift multiplies the original number by 2. 

Shifting right by n bits on a two's complement signed binary number has the effect of dividing it by 2^n, but it always rounds down (towards negative infinity).

So each shift to the right divides the original number by 2. 

1. The & (bitwise AND) in C takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.  
2. The | (bitwise OR) in C takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1. 
3. The ^ (bitwise XOR) in C takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. 
4. The << (left shift) in C takes two numbers, the left shifts the bits of the first operand, and the second operand decides the number of places to shift. 
5. The >> (right shift) in C takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift. 
6. The ~ (bitwise NOT) in C takes one number and inverts all bits of it.

// C Program to demonstrate use of bitwise operators

```c
#include <stdio.h>
int main()
{
    // a = 5 (00000101), b = 9 (00001001)
    unsigned int a = 5, b = 9;

    // The result of the and is 00000001
    printf("a = %u, b = %u\n", a, b);
    printf("a&b = %u\n", a & b);

    // The result of the bitwise OR is 00001101
    printf("a|b = %u\n", a | b);

    // The result from the bitwise xor is 00001100
    printf("a^b = %u\n", a ^ b);

    // The result of the bitwise NOT is 11111111111111111111111111111010
    // (assuming 32-bit unsigned int)
    printf("~a = %u\n", a = ~a);

    // The result when we shift b to the left one time is 00010010
    printf("b<<1 = %u\n", b << 1);

    // The result when we shift b to the right one time is 00000100
    printf("b>>1 = %u\n", b >> 1);

    return 0;
}
```

[Resource](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)