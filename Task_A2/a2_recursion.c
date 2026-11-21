#include <stdio.h>
unsigned digit_sum(unsigned n) {return n<10?n:n%10+digit_sum(n/10);}
unsigned digital_root(unsigned n) {return n<10?n:digital_root(digit_sum(n));}
long long power_fast(long long base,unsigned exp) {
    long long half;
    if(exp==0) return 1;
    half=power_fast(base,exp/2);
    return exp%2?half*half*base:half*half;
}
int main(void) {printf("Digital root of 9875: %u\n",digital_root(9875));printf("3^5: %lld\n",power_fast(3,5));return 0;}
