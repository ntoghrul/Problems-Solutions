#include <cmath>
#include <stdio.h>
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

 long long sumofarr (long long arr[]){
   long long sum=0;
   for(i=0;i<sizeof(arr)/sizeof(long long);i++){
     sum+=arr[i];
   }
   return sum;
 }
int strength(int n){
    int ct=0;
    while(n!=1){
        if(n%2==0) n/=2;
        
        
        else n=3*n+1;
        
        ct++;
    }
    return ct;
}




class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* Find(TreeNode *tree, int element){
    if(tree == NULL) return NULL;
    if(tree->val == element) return tree;
         Find(tree ->left,element);
    if (tree->val > element) return Find (tree ->left, element);
    else return Find(tree->right, element);
    
    
        return NULL;
}

TreeNode * Minimum(TreeNode *tree){
    if(tree == NULL) return NULL;
    while(tree->right!=NULL) tree = tree->right;
    return tree;
}

int minDepth(TreeNode *tree){
    int minD=0;
    if(tree == NULL) return 0;
    else
        minD = min(minDepth(tree->left), minDepth(tree->right))+1;
    
    return minD;
    
}

string NumtoRoman(int n){
    string RoN;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    while(n>0)
    {
      int div = n/num[i];
      n = n % num[i];
      while(div--)
          RoN+=sym[i];
    
      i--;
    }
    return RoN;
}

int RomantoNum(string s){
    int numN=0;
    int i=0;
    int uzun = s.length();
//    char sym[] = {'I','V','X','L','C','D','M'};
    string syn = "IVXLCDM";
    int  nums[] = {1,5,10,50,100,500,1000};
    switch(s[uzun-1]){
        case 'I': numN+=1;
            break;
        case 'V': numN+=5;
            break;
        case 'X': numN+=10;
            break;
        case 'L': numN+=50;
            break;
        case 'C': numN+=100;
            break;
        case 'D': numN+=500;
            break;
        case 'M': numN+=1000;
            break;
    }

    for(i=uzun-2;i>=0;i--){
        if(syn.find(s[i])<syn.find(s[i+1])){
//            cout<<nums[syn.find(s[i])]<<endl;
            numN=numN-nums[syn.find(s[i])];
//            cout<<numN<<endl;
        }
        else{
//            cout<<nums[syn.find(s[i])]<<"-"<<numN<<endl;
            numN+=nums[syn.find(s[i])];
          
        }
//        cout<<nums[syn.find(s[i])]<<endl;
 
    }
    return numN;
    
}

int main() {
    string sum;
    string num1;
    string num2;
    cin>>sum;
    char del = '+';
    int delPos = sum.find(del);
    if(delPos!=-1){
     num1 = sum.substr(0, delPos);
     num2 = sum.substr(delPos+1);
    }
    int eded1 = RomantoNum(num1);
    int eded2 = RomantoNum(num2);
    int cem = eded1+eded2;
    cout<<NumtoRoman(cem)<<endl;
    
        
    
    }

