#include <stdio.h>

int main() {
    // printf("Size of char: %zu byte(s)\n", sizeof(char));
    // printf("Size of short: %zu byte(s)\n", sizeof(short));
    // printf("Size of int: %zu byte(s)\n", sizeof(int));
    // printf("Size of long: %zu byte(s)\n", sizeof(long));
    // printf("Size of long long: %zu byte(s)\n", sizeof(long long));
    // printf("Size of float: %zu byte(s)\n", sizeof(float));
    // printf("Size of double: %zu byte(s)\n", sizeof(double));
    // printf("%d",~2);
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++) printf("%d ",j+1);
        for(int j=0;j<2*i;j++) printf("%s ","*");
        for(int j=n-i;j>0;j--) printf("%d ",j);
        printf("\n");
    }

    return 0;
}