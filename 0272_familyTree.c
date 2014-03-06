#include<stdio.h>
int main(){long long int t,n,a,b;scanf("%lld",&t);while(t--){scanf("%lld%lld%lld",&n,&a,&b);while(a!=b){if(a>b)a>>=1;else b>>=1;}printf("%lld\n",a);}return 0;}
