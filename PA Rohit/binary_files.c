
/*There is a list of encrypted files of size n, each with a different value, and a list of n binary values. 
A value of 1 represents a file that has been decrypted, and 0 represents an encrypted file that is not yet decrypted. 
The value sum of the encrypted files is the sum of all values of the files where the corresponding value in the binary list is
1. In a single operation, a group of up to k encrypted files can be decrypted simultaneously.
The values of the encrypted files and the binary list are given, along with the maximum number of encrypted files 
that can be decrypted in a single operation. Find the maximum possible value sum of the decrypted files.
Note: A group, i.e., subarray is defined as any contiguous segment of the array.

Example 1
Given n = 4, k = 2, encrypted_file = [7, 4, 3, 5], and
binary = [1, 0, 0, 0].


Example 2
Given n = 6, k = 2, encrypted_file = [1 , 3, 5, 2 , 5 ,4], and
binary = [1,1, 0, 1, 0, 0].

Answer is 15*/
#define max(a,b) ((a>b)?a:b)
#include <stdio.h>
#include <math.h>

int maximum(int file[],int status[],int n,int k){
    int already_en=0;
    int i;
    for(i=0;i<n;i++){
        if(status[i]==1) already_en+=file[i];
    }
    
    int subarray=0;
    for(i=0;i<k;i++){
        if(status[i]==0) subarray+=file[i];
    }

    int max_sum=subarray;
    for(i=k;i<n;i++){
        if(status[i-k]==0) subarray-=file[i-k];
        if(status[i]==0) subarray+=file[i];
        max_sum=max(max_sum,subarray);
    }
    return max_sum+already_en;
}
int main(){
     int n = 6, k = 2;
     int file[] = {1 , 3, 5, 2 , 5 ,4};
     int status[]= {1,1, 0, 1, 0, 0};
     printf("%d\n",maximum(file,status,n,k));
}
