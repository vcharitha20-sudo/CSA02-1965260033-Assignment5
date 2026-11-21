#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct {int id;int days_until_eligible;char group[4];} Donor;
int main(void) {
    const int n=100000;Donor *a;int i,eligible=0;clock_t start=clock();
    a=malloc((size_t)n*sizeof *a);if(!a){perror("malloc");return 1;}
    for(i=0;i<n;i++){a[i].id=700000+i;a[i].days_until_eligible=i%90;strcpy(a[i].group,"O+");}
    for(i=0;i<n;i++)if(a[i].days_until_eligible<=7)eligible++;
    printf("Simulated donors: %d\nEligible in next 7 days (demo): %d\n",n,eligible);
    printf("Allocated donor array: %lu bytes\n",(unsigned long)((size_t)n*sizeof *a));
    printf("Elapsed CPU time: %.4f seconds\n",(double)(clock()-start)/CLOCKS_PER_SEC);
    puts("Demo data only: actual donor eligibility requires verified dates and medical criteria.");
    free(a);return 0;
}
