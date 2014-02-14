#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	srand(time(NULL));
	int i,j,s,temp;
	s=1000000;
	int a[s];
	for(i=0;i<s;i++)
		a[i]=rand()%1000;
	for(i=1;i<s;i++){
		temp=a[i];
		j=i-1;
		while((temp<a[j])&&(j>=0)){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
	return 0;
}
