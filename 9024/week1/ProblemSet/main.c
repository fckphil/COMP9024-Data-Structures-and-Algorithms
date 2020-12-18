#include <stdio.h>
int question1();
int question2();
int question3a();
int question3b();
int main() {
//    printf("Question1:\n");
//    printf("%d\n",question1());
//    printf("Question2:\n");
//    question2();
    question3b();
}
int question1(){
    int i = 10000;
    int a,b,c,d,e;
    for(i=10000;i<25000;i++){
        a=(i/10000)%10;
        b=(i/1000)%10;
        c=(i/100)%10;
        d=(i/10)%10;
        e=i%10;
        if(4*i==e*10000+d*1000+c*100+b*10+a)    return i;
    }
}

int question2(){
    char catdog[] = { 'a','c','d','g','o','t' };
    int count = 0;
    int i, j, k, l, m, n;
    for (i=0; i<6; i++)
    for (j=0; j<6; j++)
    for (k=0; k<6; k++)
    for (l=0; l<6; l++)
    for (m=0; m<6; m++)
    for (n=0; n<6; n++)
    if (i!=j && i!=k && i!=l && i!=m && i!=n &&
    j!=k && j!=l && j!=m && j!=n &&
    k!=l && k!=m && k!=n &&
    l!=m && l!=n && m!=n) {
        printf("%c%c%c%c%c%c\n", catdog[i], catdog[j],
        catdog[k], catdog[l],
        catdog[m], catdog[n]);
        count++;
    }
    printf("%d\n", count);
    return 0;
}

int question3a(int n){
    while(n!=1){
        if(n%2==0){//n is even
            printf("%d\n",n);
            n=n/2;
        }
        else{//n is odd
            printf("%d\n",n);
            n=3*n+1;
        }
    }
    printf("%d\n",n);
}

int question3b(){
    int Fib[10];
    int i;
    for(i=0;i<10;i++){
        if(i<2) Fib[i]=1;
        else    Fib[i] = Fib[i-1]+Fib[i-2];
        printf("Fib[%d] = %d\n",i+1,Fib[i]);
        question3a(Fib[i]);
    }
}