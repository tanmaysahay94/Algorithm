#include<stdio.h>
#define m 1000000007
long long int tree[100000];
inline int getint()
{
    int n=0,c=getchar_unlocked();
    while(c<'0'||c>'9')
        c = getchar_unlocked();
    while(c>='0'&&c<='9')
        n=(n<<3)+(n<<1)+c-'0',c=getchar_unlocked();
    return n;
}
int main()
{
    int h,i,left,right;
    long long int tree[100000];
    double working[100000];
    while(h=(1<<getint())-1)
    {
        for(i=1;i<=h;i++)
            working[i]=tree[i]=getint();
        for(i=h/2;i>=1;i--)
        {
            left=2*i,right=2*i+1;
            if(working[left]>working[right])
                tree[i]*=tree[left],working[i]*=working[left];
            else
                tree[i]*=tree[right],working[i]*=working[right];
            tree[i]%=m;
        }
        printf("%lld\n",tree[1]);
    }
    return 0;
}
