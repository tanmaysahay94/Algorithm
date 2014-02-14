#include<stdio.h>
#include<stdlib.h>
 
long long int comparison_count=0;
void quicksort(long int *a,long int s,long int n){
	long int pivot,length=n+1-s,k=1,l=1,i,*b,*c;
	if(length<=1){
		return;
	}
	else{
		b=(long int *)malloc((length+1)*sizeof(long int));
		c=(long int *)malloc((length+1)*sizeof(long int));
		pivot=a[(s+n)/2];
		for(i=s;i<=n;i++){
			comparison_count++;
			if(a[i]<=pivot&&i!=(s+n)/2){
				b[k]=a[i];
				k++;
			}
			else if(a[i]>pivot){
				c[l]=a[i];
				l++;
			}
		}
		quicksort(b,1,k-1);
		free(b);
		quicksort(c,1,l-1);
		free(c);
		return;
	}
}
 
int main(){
	long int n,a[100001],i;
	scanf("%ld",&n);
	for(i=1;i<=n;i++){
		scanf("%ld",&a[i]);
	}
	quicksort(a,1,n);
	printf("%lld",comparison_count);
	return 0;
}
