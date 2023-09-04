#include <stdio.h>
#include <stdbool.h>

bool check_consecutive_ones(int n){
    return (n&(n>>1))!=0;
}
int main(){
    printf("%d",check_consecutive_ones(10));
}