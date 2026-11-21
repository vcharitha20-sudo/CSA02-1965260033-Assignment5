#include <stdio.h>
#include <string.h>
typedef struct {int id, age; char name[40], group[4];} Donor;
typedef struct {int count, youngest_id;} Result;
Result eligible(const Donor *a, int n, const char *group) {
    Result r={0,-1}; int i, youngest=1000;
    for(i=0;i<n;i++) if(strcmp(a[i].group,group)==0 && a[i].age>=18 && a[i].age<=65) {
        r.count++; if(a[i].age<youngest) {youngest=a[i].age;r.youngest_id=a[i].id;}
    }
    return r;
}
int main(void) {
    Donor a[]={{101,25,"Arun","O+"},{102,19,"Devi","O+"},{103,17,"Mira","O+"},{104,30,"Sam","A+"}};
    Result r=eligible(a,4,"O+");
    printf("Eligible O+ donors: %d; youngest ID: %d\n",r.count,r.youngest_id);
    return 0;
}
