#include <cmath>
#include<stdio.h>
#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#define Max 10000001
typedef long long ll;


using namespace std;

int i,j;

long long arr[Max];
long long dp[51][51];

vector<int> vec;
map<long long,long long> m;
int IsPrime(int n)
{
  for (int i = 2; i <= sqrt(1.0*n); i++)
    if (n % i == 0) return 0;
  return 1;
}

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>=b) return gcd(a%b, b);
    return gcd(a,b%a);
}


int lcm(int a, int b){
   return  a*b/gcd(a,b);
}
unsigned long long  exp(unsigned long long  x, unsigned long long  n)
{
  if (n == 0) return 1;
  if (n % 2 == 0) return exp((x * x), n / 2);
  return (x * exp(x, n - 1));
}
long long ust(long long x, long long n, long long m){
    if(n==0) return 1;
    if(n%2==0) return ust((x%m*x%m)%m,n/2,m)%m;
    return (x%m*ust(x%m,n-1,m)%m)%m;
}

long long fact(long long n){
    if(n==0) return 1;
    return fact(n-1)*n;

}

int sumofd(int n){
    if(n<0) n=-n;
    if(n/10==0) return n%10;

    return sumofd(n/10)+n%10;
}

int numofd(int n){
    if(n<10) return 1;
    return numofd(n/10)+1;
}

long long fib(long long n){
    if(n==0) return 1;
    if(n==1) return 1;
    if(arr[n]!=-1) return arr[n];
    return arr[n]=fib(n-1)+fib(n-2);
}

int cnk(int n,int k){
    if(n==k) return 1;
    if(k==0) return 1;
    return cnk(n-1,k-1)+cnk(n-1,k);
}
long long three(long n){
    if(n==1) return 2;
    if(n==2) return 4;
    if(n==3) return 7;
    if(arr[n]!=-1)
        return arr[n];

     return arr[n]=(three(n-1)%12345+three(n-2)%12345+three(n-3)%12345)%12345;

}
int honeycomb(int n){
    if(n==1) return 1;
    if(n==2) return 1;
    if(n==3) return 1 ;
    if(arr[n]!=-1) return arr[n];

    if(n%2!=0) return arr[n]=honeycomb(n-2)+honeycomb(n-3);




    else return arr[n]=honeycomb(n-1);
}
string letfib(int n){
    if(n==0) return "a";
    if(n==1) return "b";

    return letfib(n-1)+letfib(n-2);
}
void sieve(){
    for(i=0;i<1000001;i++)
        arr[i]=1;
    arr[0] = arr[1] = 0;

    for(i=2;i*i<1000001;i++)
        for(j=i*i;j<1000001;j+=i) arr[j]=0;

}
long long fuck(long long  n,long long p, long long q){
    if(n==0) return 1;
    if(m[n]>0) return m[n];
    return m[n]=fuck((n/p),p,q)+fuck((int)(n/q),p,q);
}

long long evens(long long n){
    long long big=1;
    while(n!=0){
        if((n%10)%2==0) big*=n%10;
        n/=10;


    }
    return big;

}
long long fu(long long n){
    return 0;

    }






int main() {
    int i,j,n;
    int a,b,c,d;
    int me;
   
    cin>>a>>b>>c>>d;

    if(a>b){
        me=a;
        a=b;
        b=me;
    }
    if(c>d){
        me=c;
        c=d;
        d=me;
    }


    for(i=a;i<=b;i++){
        for(j=c;j<=d;j++){
            me=i*j;
            if(count(vec.begin(),vec.end(),me)==0) vec.push_back(me);
        }
    }
  
cout<<vec.size()<<endl;
}
