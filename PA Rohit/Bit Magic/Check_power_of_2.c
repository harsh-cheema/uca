#include <stdio.h>
#include <stdbool.h>

bool power_of_2(int n){
    if(n==0) return true;
    return (n & (n-1))==0;
}
int main(){
    printf("%d",power_of_2(8));
}