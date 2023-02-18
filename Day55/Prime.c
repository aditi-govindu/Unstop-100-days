#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Description: Utkarsh Gupta taught about Prime Numbers to his students. He taught various ways to his students to find whether a number is prime or not. For testing the level of understanding Utkarsh sir gave the task to every student to find the number of primes which are strictly less than n.
You, being the student of Utkarsh Gupta, calculate the count of primes strictly less than n.
Note: 1 is not a prime number.
*/

int sieveOfEratosthenes(int n)
{
    bool primes[n+1];
    int count = 0;
    memset(primes, true, sizeof(primes));

    for(int i = 2; i * i <= n; i++)
    {
        // If number is a multiple of i, set it to false
        if(primes[i] == true)
        {
            for(int j = i*i; j <= n; j+=i)
                primes[j] = false;
        }
    }

    for(int i = 2; i <= n; i++)
    {
        // Display all prime numbers in range of 2 to given number
        if(primes[i])
            count++;
    }
    return count;
}

int main() 
{
    int num;
    scanf("%d",&num);

    // Find all prime numbers less than number given
    printf("%d",sieveOfEratosthenes(num-1)); 
    return 0;
}