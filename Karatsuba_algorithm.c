// Fast multiplication
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int make_same_size(char** a,char** b){
    int len_a=strlen(*a);
    int len_b=strlen(*b);
    if(len_a<len_b){
        char* str_a=(char*)malloc((len_b+1)*sizeof(char));

        for(int i=0;i<(len_b-len_a);i++)
        str_a[i]='0';

        for(int i=(len_b-len_a);i<len_b;i++)
        str_a[i]=(*a)[i-(len_b-len_a)];

        str_a[len_b]='\0';
        *a=str_a;
    }
    else if(len_b<len_a){
        char* str_b=(char*)malloc((len_a+1)*sizeof(char));

        for(int i=0;i<(len_a-len_b);i++)
        str_b[i]='0';

        for(int i=(len_a-len_b);i<len_a;i++)
        str_b[i]=(*b)[i-(len_a-len_b)];

        str_b[len_a]='\0';
        *b=str_b;
    }
    return strlen(*a);

}

char* get_substring(char* str,int s,int e){
    char* substr=(char*)malloc((e-s+2)*sizeof(char));
    for(int i=s;i<=e;i++){
        substr[i-s]=str[i];
    }
    substr[e-s+1]='\0';
    return substr;
}

char* add_binary_string(char* a,char* b){
    int length=make_same_size(&a,&b);
    char* res=(char*)malloc((length+2)*sizeof(char));
    int carry=0;
    int bit_a,bit_b,temp;
    int n=length;
    while(n>0){
        bit_a=a[n-1]-'0';
        bit_b=b[n-1]-'0';
        temp=bit_a+bit_b+carry; //1,1,0     1,0,0   0,0,0    1,1,1     i.e. addition either 0,1,2,3 carry comes in 2 and 3
        if(temp>=2){
            carry=1;
            temp=temp%2;
        }
        else{
            carry=0;
        }

        res[n]=temp+'0';
        n--;
    }
    if(carry==1){
        res[0]='1';
    }
    else{
        for(int i=0;i<strlen(res)-1;i++)
            res[i]=res[i+1];
        res[strlen(res)-1]='\0';
    }
    return res;

}

long int fast_multiply(char* a,char* b){
       int length=make_same_size(&a,&b);

       if(length==0) return 0;
       if(length==1) return ((a[0]-'0')*(b[0]-'0'));
       int n_left_bits=length/2;
       int n_right_bits=length-n_left_bits;

       char* a_left=get_substring(a,0,n_left_bits-1);
       char* a_right=get_substring(a,n_left_bits,length-1);
       char* b_left=get_substring(b,0,n_left_bits-1);
       char* b_right=get_substring(b,n_left_bits,length-1);

       long int A=fast_multiply(a_left,b_left);
       long int B=fast_multiply(a_right,b_right);
       long int C=fast_multiply(add_binary_string(a_left,a_right),add_binary_string(b_left,b_right));

       return A*(1<<(2*n_right_bits))+(C-A-B)*(1<<n_right_bits)+B;


}

int main(){
   assert(fast_multiply("1100", "1010")==120); 
  assert(fast_multiply("110", "1010")==60); 
  assert(fast_multiply("11", "1010")==30); 
  assert(fast_multiply("1", "1010")==10); 
  assert(fast_multiply("0", "1010")==00); 
  assert(fast_multiply("111", "111")==49); 
  assert(fast_multiply("11", "11")==9);
  assert(fast_multiply("11", "101")==15); 
}
