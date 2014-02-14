#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t,amount,cost,min_w,wrappers,total,more;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&amount,&cost,&min_w);
        total=wrappers=amount/cost;
        while(wrappers>=min_w)
        {
            more=wrappers/min_w;
            total+=more;
            wrappers%=min_w;
            wrappers+=more;
        }
        printf("%d\n",total);
    }
    return 0;
}
