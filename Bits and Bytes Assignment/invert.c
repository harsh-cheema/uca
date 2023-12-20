#include <stdio.h>

int invert(int x,int n,int p){
    int mask=1<<n;
    mask=mask-1;
    mask=mask<<p;
    return x^mask;
    
}
