#include <stdio.h>
#include <stdbool.h>

bool check_palindrome(int n){
    if(n<0) return false;

    int original=n;
    int reversed=0;

    while(n>0){
        reversed=reversed<<1;
        reversed= reversed| (n&1);
        n=n>>1;
    }
    return original==reversed;
}
int main(){
    printf("%d",check_palindrome(11));
}