#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct word
{
	char data[13];
	struct word *next;
}word;
word* insert_sort(word *l,char input[])
{
	word *temp=(word*)malloc(sizeof(word));
	word *traverse;
	traverse=l;
	strcpy(temp->data,input);
	temp->next=NULL;
	if(l==NULL)
		return temp;
	else if(strcmp(input,l->data)<=0)
	{
		temp->next=l;
		return temp;
	}
	else
	{
		while((traverse->next!=NULL)&&strcmp(input,traverse->next->data)>=0)
			traverse=traverse->next;
		temp->next=traverse->next;
		traverse->next=temp;
		return l;
	}
}
word* delete_word(word *l,char to_delete[])
{
	word *temp;
	temp=l;
	if(!strcmp(l->data,to_delete))
		return l->next;
	while(temp->next!=NULL)
	{
		if(!strcmp(to_delete,temp->next->data))
		{
			temp->next=temp->next->next;
			break;
		}
		temp=temp->next;
	}
	return l;
}
void print_list(word *l)
{
	while(l!=NULL)
	{
		printf("%s\n",l->data);
		l=l->next;
	}
}
int main()
{
	int n,i,q,q_type;
	word *w[26];
	char c[13],k;
	for(i=0;i<26;i++)
		w[i]=NULL;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",c);
		k=c[0];
		w[k-'a']=insert_sort(w[k-'a'],c);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %s",&q_type,c);
		k=c[0];
		if(q_type==1)
			w[k-'a']=insert_sort(w[k-'a'],c);
		else if(q_type==2)
			w[k-'a']=delete_word(w[k-'a'],c);
		else if(q_type==3)
		{
			if(w[k-'a']==NULL)
				printf("\n");
			else
				print_list(w[k-'a']);
		}
	}
	return 0;
}
