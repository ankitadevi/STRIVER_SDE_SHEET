//Question:Find the repeating and missing numbers
//Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] 
//both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. 
//The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

//GFG: link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
//Alternative 0n leetcode:
//Leetcode:268   link:https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        long long n = nums.size();

        long long actualSum = 0, actualSqSum = 0;
        for (int x : nums) {
            actualSum += x;
            actualSqSum += 1LL * x * x;
        }

        long long expectedSum = n * (n + 1) / 2;
        long long expectedSqSum = n * (n + 1) * (2 * n + 1) / 6;

        long long diff = actualSum - expectedSum; // A - B
        long long sqDiff = actualSqSum - expectedSqSum; // A² - B²

        long long sumAB = sqDiff / diff; // A + B

        int A = (diff + sumAB) / 2;
        int B = (sumAB - diff) / 2;

        return {A, B};
    }
};

// tc:0(n)
// sc:0(1)

// ## Approach

// Let:

// - `A` = Repeating number
// - `B` = Missing number

// ### Step 1: Compute the difference of sums

// ```
// diff = sum(nums) - sum(1...n)
//      = A - B
// ```

// ### Step 2: Compute the difference of squares

// ```
// sqDiff = sum(nums²) - sum((1...n)²)
//        = A² - B²
// ```

// Using the identity:

// ```
// A² - B² = (A - B)(A + B)
// ```

// we get:

// ```
// A + B = sqDiff / diff
// ```

// ### Step 3: Solve the two equations

// We now have:

// ```
// A - B = diff
// A + B = sqDiff / diff
// ```

// Adding both equations:
// A = ((A + B) + (A - B)) / 2

// Subtracting the equations:
// B = ((A + B) - (A - B)) / 2



