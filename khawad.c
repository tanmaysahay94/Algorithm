#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int val;
	int level;
	struct tree *left;
	struct tree *right;
}tree;
int a[1000000],sorted[1000000];
int count=0;
int r=0;
int v=-1;
tree *try=NULL;
tree *insert(tree *t,int val){
	tree *temp;
	static int c=0;
	if(t==NULL){	
		t=(tree *)malloc(sizeof(tree));
		t->val=val;
		t->left=NULL;
		t->right=NULL;
		t->level=c;
		return t;
	}
	else{
		c++;
		if(val > t->val){
			t->right=insert(t->right,val);
			c--;
		}
		else if(val < t->val){
			t->left=insert(t->left,val);
			c--;
		}
	}
	return t;
}
void print(tree *t){
	if(t!=NULL){
		printf("%d %d\n",t->val,t->level);
		print(t->left);
		print(t->right);
	}
}
// checking the level 
int checker(tree *t,int n){
	if(t!=NULL){ 
		if(t->val==n){
			v=t->level;
			return v;
		}
		checker(t->left,n);
		checker(t->right,n);
	}
	else
		return v;
}
// forming the required array 
void array(tree *t,int lev){
	if(t!=NULL){
		array(t->left,lev);
		if(t->level==lev){
			a[count]=t->val;
			count++;
		}
		array(t->right,lev);
	}
}
void node(tree *t,int pos){
	if(t!=NULL){
		if(t->val==pos){
			try=t;
		}
		node(t->left,pos);
		node(t->right,pos);
	}
}
// final //
void final(tree *f){
	if(f!=NULL){
		final(f->left);
		sorted[r++]=f->val;
		final(f->right);
	}
}
int main(){
	int test,N,i,val,n,check,k,pos,c1;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&N);
		tree *t;
		tree *temp;
		t=NULL;
		temp=NULL;
		for(i=0;i<N;i++){
			scanf("%d",&val);
			t=insert(t,val);
		}
		scanf("%d%d",&n,&k);
		check=checker(t,n);
		if(check==-1){
			printf("$ $\n");
		}
		else{
			array(t,check);
			int flag=0;
			if(n==a[--count]){
				printf("$ $\n");
				flag=1;
			}
			else{
				for(i=0;i<count+1;i++){
					if(n==a[i]){
						pos=a[i+1];
						break;
					}
				}
				node(t,pos);
				final(try);
				if(k>r){
					printf("%d $\n",pos);
				}
				else{
					printf("%d %d\n",pos,sorted[k-1]);	
				}
			}
		}
		count=0;
		r=0;
		pos=0;
		try=NULL;
		v=-1;
	}
	return 0;
}

