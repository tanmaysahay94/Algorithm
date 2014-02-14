#include<stdio.h>
int main()
{
	int N,l,b,i,r,t,output[999];
	scanf("%d",&N);  //N is number of inputs
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&l,&b);  //l and b are the inputs
		if((l==0)||(b==0))
			output[i]=0;          //output[i] stores the ouptut
		else
		{
			if(l<b)             //switching values if length is shorter than breadth
			{
				t=l;
				l=b;
				b=t;
			}
			while(b!=0)
			{
				r=l%b;
				l=b;
				b=r;
			}
			output[i]=l;
		}
	}
	for(i=0;i<N;i++)
		printf("%d\n",output[i]);   //loop to print the output
	return 0;
}
