#include<stdio.h>
typedef struct student
{
	char name[100];
	long int roll;
}s;
int main()
{
	int no_of_students,i;
	printf("Number of students:");
	scanf("%d",&no_of_students);
	s stud[no_of_students];
	for(i=0;i<no_of_students;i++)
	{
		printf("Name of student %d:\n",i+1);
		scanf("%s",stud[i].name);
		printf("Roll No of student %d:\n",i+1);
		scanf("%ld",&stud[i].roll);
	}
	printf("The following is a list contains the details of all students:\n");
	for(i=0;i<no_of_students;i++)
		printf("Name:%s|Roll Number:%ld\n",stud[i].name,stud[i].roll);
	return 0;
}
