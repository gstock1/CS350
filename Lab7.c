#include <stdio.h>

int main()
{
    int b[4] = {2,4,2,8};
    int *p = &b[0];
    int *q = &b[1];
    int *r = &b[2];
    int a = 0;
    if(p<q && q<r){
        a = 1;
    }
    else{
        a = -1;
    }
    printf("A is: %d", a);
    
    int b1 = 0;
    if(p !=r && *p == *r){
        b1 = 1;
    }
    else{
        b1 = -1;
    }
    printf("\n1B is: %d", b1);
    
    int c = 0;
    if(q-b == &b[3] - &p[1]){
        c = 1;
    }
    else{
        c = -1;
    }
    
    printf("\nC is: %d", c);

    int d = 0;
    if(p[1] == r[-1]){
        d = 1;
    }
    else {
        d = -1;
    }
    printf("\nD is: %d", d);
    
    int e = 0;
    if(&r[-2] == &b[0]){
        e = 1;
    }
    else{
        e = -1;
    }
    printf("\nE is: %d", e);

    int f = 0;
    if(q-p+q-p == q+q-p-p){
        f = 1;
    }
    else{
        f = -1;
    }
    printf("F is: %d", f);
    return 0;
}