// Implement Pow(x,n) | X raised to the power N
// Problem Statement: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

//Leetcode:50   link:https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Handle INT_MIN

        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        double ans = 1.0;

        while (N > 0) {
            if (N & 1) {      // If power is odd
                ans *= x;
            }
            x *= x;           // Square the base
            N >>= 1;          // Divide power by 2
        }

        return ans;
    }
};

// > ### Binary Exponentiation (Exponentiation by Squaring)
// >
// > - If `n` is even:
// >   `xⁿ = (x²)ⁿᐟ²`
// >
// > - If `n` is odd:
// >   `xⁿ = x · xⁿ⁻¹`
// >
// > - For negative powers:
// >   `x⁻ⁿ = 1 / xⁿ`
// >
// > This reduces the time complexity from **O(n)** to **O(log n)** by repeatedly squaring the base and halving the exponent.
