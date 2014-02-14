#include<stdio.h>
#include<math.h>
int quadraticCollisions=0,linearCollisions=0;
int sizeOf(int a[])
{
	int i;
	while(a[++i]);
	return i;
}
void linearInsert(int a[],int val,int size)
{
	int k=size,location=val%k,i,inserted=0;
	for(i=location;i<k;i++)
	{
		if(!a[i])
		{
			a[i]=val;
			inserted=1;
			break;
		}
		linearCollisions++;
	}
	if(!inserted)
		for(i=0;i<location;i++)
		{
			if(!a[i])
			{
				a[i]=val;
				inserted=1;
				break;
			}
			linearCollisions++;
		}
}
void quadraticInsert(int a[],int val,int size)
{
	int loc,k=size,quad=0;
	while(k--)
	{
		loc=((val%size)+((int)pow(quad,2)))%size;
		if(!a[loc])
		{
			a[loc]=val;
			break;
		}
		quadraticCollisions++;
		quad++;
	}
}
int linearSearch(int a[],int val,int size)
{
	int i,k=size,expectedLoc=val%k,found=0;
	for(i=expectedLoc;i<k;i++)
		if(a[i]==val)
		{
			found=1;
			return i;
		}
	if(!found)
	{
		for(i=0;i<expectedLoc;i++)
			if(a[i]==val)
			{
				found=1;
				return i;
			}
	}
	if(!found)
		return -1;
}
int quadraticSearch(int a[],int val,int size)
{
	int expectedLoc,k=size,quad,i,found=0;
	for(i=0;i<k;i++)
	{
		expectedLoc=((val%k)+((int)pow(i,2)))%k;
		if(a[expectedLoc]==val)
		{
			found=1;
			return expectedLoc;
		}
	}
	if(!found)
		return -1;
}
int main()
{
	int k,i,toInput;
	printf("Table Size: ");
	scanf("%d",&k);
	int linearProbe[k],quadraticProbe[k];
	for(i=0;i<k;i++)
		linearProbe[i]=quadraticProbe[i]=0;
	for(i=0;i<k;i++)
	{
		scanf("%d",&toInput);
		linearInsert(linearProbe,toInput,k);
		quadraticInsert(quadraticProbe,toInput,k);
	}
	printf("Linear Collisions: %d    Quadratic Collisions: %d\n",linearCollisions,quadraticCollisions);
	printf("Search value: ");
	scanf("%d",&toInput);
	printf("If -1 is printed, it means value has not been found\n");
	printf("Value at location %d in LinearArr and at location %d in QuadraticArr\n",linearSearch(linearProbe,toInput,k),quadraticSearch(quadraticProbe,toInput,k));
	return 0;
}
