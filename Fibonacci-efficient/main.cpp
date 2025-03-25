//An efficient algorithm that gives the count of Fibonacci sequence elements smaller than a given number
/*
* Important property:
            n
    [ 1 1 ]		=	[ Fib n-1	Fib n	]
    [ 0 1 ]			[ Fib n		Fib n+1 ]
*/

#include <iostream>
#include <cmath>

using namespace std;

//The 93th Fibonacci number is the last one that
//fits in unsigned long long is 12200160415121876738
const int LIMIT = 93;

void read(unsigned long long& number)
{
    cout << "Type in an integer: ";
    cin >> number;
}

//Multiplies matrices A and B, the result will be in aux
void matrix_multiply(unsigned long long A[2][2], unsigned long long B[2][2], unsigned long long aux[2][2])
{
    unsigned long long first, second, third, fourth;
    first = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    second = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    third = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    fourth = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    aux[0][0] = first;
    aux[0][1] = second;
    aux[1][0] = third;
    aux[1][1] = fourth;
}

unsigned long long fast_modular_exponentiation(unsigned long long A[2][2], unsigned long long exponent, unsigned long long result[2][2])
{
    unsigned long long B[2][2] = { { 1, 1 }, { 1, 0 } };

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            unsigned long long aux[2][2];
            matrix_multiply(result, B, aux);
            //Copy
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    result[i][j] = aux[i][j];
                }
            }
        }
        unsigned long long aux[2][2];
        //I perform this multiplication either way so
        //  if exponent is even, then matrix * matrix gets executed
        //  if exponent is odd, then matrix * matrix * matrix gets executed
        matrix_multiply(B, B, aux);
        //Copy
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                B[i][j] = aux[i][j];
            }
        }
        exponent /= 2;
    }

    //Returns n-th Fibonacci number
    return result[0][1];
}

//I call it for an imaginary array, where the elements are: 1, 2, 3, 4, ..., LIMIT
//meaning its n-th element = n
void binary_search(int& first, int& last, unsigned long long number)
{
    while (first <= last)
    {
        int middle = (first + last) / 2;

        //Initialize
        unsigned long long A[2][2] = { { 1, 1}, { 1 , 0 } };

        //I initialize with the identity matrix, so the multiplication will be correct
        unsigned long long result[2][2] = { { 1, 0 }, { 0, 1 } };
        unsigned long long current_fibonacci = fast_modular_exponentiation(A, middle, result);
        if (current_fibonacci > number) last = middle - 1;
        else first = middle + 1;
    }
}

void print(int last)
{
    cout << "The number of Fibonacci elements smaller than this integer is " << last << endl;
}

int main()
{
    unsigned long long number;
    read(number);

    int first = 1, last = LIMIT;
    binary_search(first, last, number);
    print(last);

    return 0;
}