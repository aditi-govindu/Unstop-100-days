#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
Description: Marco is fond of algorithms, especially of trees. One day he wonders that for a particular number of nodes, how many trees can be constructed such that they are unique in the structure and satisfy these conditions:

Left child value of the root should be smaller than the root value.
Right child value of the root should be larger than the root value.
The nodes values are from [1,N] and the values should not be repeated more than once.
*/

// Calculate Catalan number for given input
int fact(int n)
{
    if(n <= 1)
        return 1;
    int res = 0;
    for(int i = 0; i < n; i++)
        res += fact(i) * fact(n - i - 1);
    return res;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int num;
    scanf("%d",&num);

    // Display results to user
    int result = fact(num);
    printf("%d",result);
    return 0;
}