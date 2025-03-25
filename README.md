# Calculating Fibonacci numbers efficiently using matrix multiplication in O(log n) time

## Overview

This C++ program provides an efficient algorithm to count how many Fibonacci sequence elements are smaller than a given integer. The Fibonacci sequence is generated using matrix exponentiation, which allows the program to calculate Fibonacci numbers efficiently even for large indices.

The algorithm relies on the matrix exponentiation property of Fibonacci numbers, which is as follows:

$$
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}^n =
\begin{bmatrix}
F_{n+1} & F_n \\
F_n & F_{n-1}
\end{bmatrix}
$$

Where $$F_n$$ represents the $$n$$-th Fibonacci number.

### Key Features:
- The program uses matrix exponentiation to calculate Fibonacci numbers in **logarithmic time** $$O(\log n)$$.
- The program employs **binary search** to efficiently find the count of Fibonacci numbers smaller than the given input number.
- The algorithm is **constant time** with respect to the Fibonacci index for practical input values, as it uses a **LIMIT** to restrict the Fibonacci sequence to a manageable range.

## How It Works

### Key Components

1. **Matrix Multiplication**:  
   The algorithm multiplies 2x2 matrices to simulate the Fibonacci recurrence relation. The matrix exponentiation method is used to find the Fibonacci number for any given index.

2. **Binary Search**:  
   Given an integer, the program uses binary search to find how many Fibonacci numbers are smaller than the input number. This reduces the complexity of the search from linear to logarithmic.

3. **Fast Modular Exponentiation**:  
   The matrix exponentiation leverages the fast exponentiation algorithm (also known as **exponentiation by squaring**) to compute powers of matrices efficiently.

4. **LIMIT Constant**:  
   The program operates with a **LIMIT** constant, which defines the maximum Fibonacci index that will be computed. In this case, the **LIMIT** is set to 93, as the 93rd Fibonacci number is the largest Fibonacci number that can fit in an **unsigned long long** variable. The algorithm is designed to efficiently work within this limit, making the complexity effectively constant when considering practical input values (since the search will always be bounded by this constant).

### Steps

1. **Read Input**:  
   The user is prompted to enter an integer.

2. **Matrix Exponentiation**:  
   The Fibonacci numbers are computed using the matrix exponentiation technique, which allows us to efficiently compute Fibonacci numbers for large indices.

3. **Binary Search**:  
   The program uses binary search on the Fibonacci sequence to find the largest Fibonacci number that is smaller than the given integer.

4. **Print Result**:  
   The number of Fibonacci numbers smaller than the input integer is printed.

### Time Complexity

- **Matrix Exponentiation**: The matrix exponentiation operation has a time complexity of \(O(\log n)\), where \(n\) is the index of the Fibonacci number.
- **Binary Search**: The binary search operation is performed on a fixed range (from 1 to **LIMIT**), which ensures that the binary search operation is **constant time** (\(O(1)\)) when the **LIMIT** is considered.
- Thus, the overall complexity of the algorithm is **constant** for practical inputs due to the fixed **LIMIT** (93), making the program highly efficient for typical use cases.

## How to Use

1. Compile and run the C++ program.
2. When prompted, enter an integer.
3. The program will output the number of Fibonacci numbers smaller than the given integer.

### Example 1
Type in an integer: **21**

The number of Fibonacci elements smaller than this integer is **8**

Explanation:
The Fibonacci numbers smaller than 21 are: 
`1, 1, 2, 3, 5, 8, 13, 21`.
Thus, there are 8 Fibonacci numbers smaller than 21.

### Example 2
Type in an integer: **100000**

The number of Fibonacci elements smaller than this integer is **25**

Explanation:
The Fibonacci numbers smaller than 100,000 are: `1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393`.
Thus, there are 25 Fibonacci numbers smaller than 100,000.
