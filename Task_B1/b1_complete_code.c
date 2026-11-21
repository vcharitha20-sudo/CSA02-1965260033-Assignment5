#include <stdio.h>
long long calls=0;
long long power_linear(long long base,int exp) {
    calls++;if(exp==0)return 1;return base*power_linear(base,exp-1);
}
long long power_fast(long long base,int exp) {
    long long half;
    calls++;
    if(exp==0)return 1;
    half=power_fast(base,exp/2);
    return exp%2?half*half*base:half*half;
}
int main(void) {
    long long a,b;
    calls=0;a=power_linear(2,30);printf("linear: %lld in %lld calls\n",a,calls);
    calls=0;b=power_fast(2,30);printf("fast : %lld in %lld calls\n",b,calls);
    return 0;
}
