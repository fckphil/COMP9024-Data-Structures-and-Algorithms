#include <stdio.h>
#include <stdbool.h>
#include<string.h>
bool isPalindrome(char A[], int len){
    int i=0, j=len-1;
    for(i=0,j=len-1;i<=j;i++,j--){
        if(A[i]!=A[j])  return false;
    }
    return true;
}
int main() {
    int i=0;
    char a[100];
    char item;
    int len;
    printf("Enter a word: ");
    while((item=getchar())!='\n') {
        a[i++] = item;
    }
    a[i]='\0';
    len = strlen(a);
    if (isPalindrome(a,len)) printf("yes");
    else printf("no");
}

