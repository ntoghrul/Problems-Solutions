#include <stdio.h>
long long  Digit(long long n)
{
    if (n == 0)
        return 0;
    return 1+Digit(n / 10);
}
int main(void){
    long long n;
    scanf("%lld",&n);
    if(n==0)
        printf("1");
    else
    printf("%lld\n",Digit(n));
}
