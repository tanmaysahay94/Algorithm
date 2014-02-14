//Program Created by Nisarg Jhaveri on 05/11/2013
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int sort_by=0;
struct std{
	char name[11];
	struct mark* std_mark;
};
struct mark{
	int marks[10];
	char del;
	struct std* std_name;
};
int mbinsearch(struct mark* all_mark[],int N,int que,int sub){
	int start=0;
	int end=N-1;
	int half;
	while(end>=start){
		half=(start+end)/2;
		if(all_mark[half]->marks[sub]==que)break;
		else if(all_mark[half]->marks[sub]>que){
			if(all_mark[half-1]->marks[sub]<que){
				half=-1;
				break;
			}
			end=half-1;
		}
		else{
			if(all_mark[half+1]->marks[sub]>que){
				half=-1;
				break;
			}
			start=half+1;
		}
	}
	if(all_mark[half]->marks[sub]!=que)return -1;
	else return half;
}
int binsearch(struct std* all_name[],int N,char que[]){
	int start=0;
	int end=N-1;
	int half;
	while(end>=start){
		half=(start+end)/2;
		if(strcmp(all_name[half]->name,que)==0)break;
		else if(strcmp(all_name[half]->name,que)>0){
			if(strcmp(all_name[half-1]->name,que)<0){
				half=-1;
				break;
			}
			end=half-1;
		}
		else{
			if(strcmp(all_name[half+1]->name,que)>0){
				half=-1;
				break;
			}
			start=half+1;
		}
	}
	if(strcmp(all_name[half]->name,que)!=0)return -1;
	else return half;
}
int sortcmp(const void *a,const void *b){
	return strcmp((*(struct std**)a)->name,(*(struct std**)b)->name);
}
int sortf(const void *a,const void *b){
	return (*(struct mark**)a)->marks[sort_by],(*(struct mark**)b)->marks[sort_by];
}
int main(){
	int N,K,Q,i,j,op;
	char std_id[11];
	scanf("%d %d %d",&N,&K,&Q);
	struct std* all_name[N],*res;
	struct mark* all_mark[N];
	struct mark** sort_marks[K];
	for(i=0;i<N;i++){
		all_name[i]=(struct std*)malloc(sizeof(struct std));
		scanf("%s",all_name[i]->name);
		all_name[i]->std_mark=(struct mark*)malloc(sizeof(struct mark));
		all_mark[i]=all_name[i]->std_mark;
		all_mark[i]->del=0;
		for(j=0;j<K;j++){
			scanf("%d",&(all_name[i]->std_mark->marks[j]));
			all_name[i]->std_mark->std_name=all_name[i];
		}
	}
	long int size=N*sizeof(struct mark*);
	for(i=0;i<K;i++){
		sort_by=i;
		sort_marks[i]=(struct mark**)malloc(size);
		memcpy(sort_marks[i],all_mark,size);
		qsort(sort_marks[i],N,sizeof(struct mark*),sortf);
	}
	qsort(all_name,N,sizeof(struct std*),sortcmp);
	while(Q--){
		scanf("%d %s",&op,std_id);
		res=all_name[binsearch(all_name,N,std_id)];
		if(op==1){
			printf("%s",res->name);
			for(i=0;i<K;i++){
				printf(" %d",res->std_mark->marks[i]);
			}
			printf("\n");
		}
		else if(op==2){
			res->std_mark->del=1;
			printf("done\n");
		}
		else if(op==3){
			int sub;
			int tmp;
			char nexp[5];
			int flag=0;
			struct mark *tmpMark,*ans;
			scanf("%d %s",&sub,nexp);
			sub--;
			int sea=res->std_mark->marks[sub];
			int markFound=mbinsearch(sort_marks[sub],N,sea,sub);
			if(nexp[0]=='n'){
				markFound--;
				while(markFound>=0 && sort_marks[sub][markFound]->del==1)markFound--;
				if(markFound>=0)
					printf("%s %d\n",sort_marks[sub][markFound]->std_name->name,sort_marks[sub][markFound]->marks[sub]);
				else printf("last\n");
			}
			else {
				markFound++;
				while(markFound<N && sort_marks[sub][markFound]->del==1)markFound++;
				if(markFound<N)
					printf("%s %d\n",sort_marks[sub][markFound]->std_name->name,sort_marks[sub][markFound]->marks[sub]);
				else printf("first\n");
			}
		}
	}
	/*for(i=0;i<N;i++){
		printf("%s\n",all_name[i]->name);
	}*/
	return 0;
}
