#include <stdio.h>
#include <limits.h>
unsigned digital_root(unsigned n) {unsigned sum;while(n>=10){sum=0;while(n){sum+=n%10;n/=10;}n=sum;}return n;}
unsigned long linear_calls(unsigned n) {return (unsigned long)n+1;}
unsigned long fast_calls(unsigned n) {unsigned long calls=1;while(n){calls++;n/=2;}return calls;}
int main(void) {unsigned ns[]={10,100,1000,10000};int i;
    printf("digital root 9875 = %u\n",digital_root(9875));
    for(i=0;i<4;i++)printf("n=%u linear=%lu fast=%lu\n",ns[i],linear_calls(ns[i]),fast_calls(ns[i]));
    puts("Counts use recurrences, not large overflowing power values.");return 0;
}
