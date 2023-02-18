#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
Description: One day, Chris arrived at the entrance of Adventure-land. There is an n × n magic grid on the entrance, which is filled with only 1s. Any person gets the entry when they count the sum of the diagonal integers right. Chris is working on the count the sum. Can you help him to solve it fast.
*/

int main()
{
    int n;
    scanf("%d",&n);
    if(n%2 == 0)
        printf("%d",(2 * n));
    // If n is odd, 1 number in the diagonal will be repeated, subtract it
    else
        printf("%d",((2 * n) - 1)); 
    return 0;
}