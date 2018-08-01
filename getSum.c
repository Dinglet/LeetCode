/*
371. Sum of Two Integers
https://leetcode.com/problems/sum-of-two-integers/description/
*/
int getSum(int a, int b)
{
    int sum_without_carry = a^b,
        carry_current = a&b;
    while(carry_current <<= 1)
    {
        a = sum_without_carry;
        
        // b = carry_current;
        // sum_without_carry = a^b,
        // carry_current = a&b;
        sum_without_carry = a^carry_current,
        carry_current = a&carry_current;
    }
    return sum_without_carry;
}
