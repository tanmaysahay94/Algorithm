#include<stdio.h>
unsigned long long int youngCount=0,oldCount=0,young[150000],old[150000];
int main()
{
    unsigned long long int n,i,new,youngRating=0,oldRating=0,oldOfSmall,smallOfOld;
    scanf("%llu%llu",&n,&young[youngCount++]);
    youngRating+=young[0];  
    printf("%llu\n",youngRating);
    for(i=1;i<n;i++)
    {
        scanf("%llu",&new);
        if(i&1) //add to old team
        {
        }
        else    //add to young team
        {
        }
    }
    return 0;
}
