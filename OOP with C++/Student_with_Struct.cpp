#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>

struct student
{
	int id;
	char name[20];
};

struct student FillStudent();
void PrintStudent(struct student std);


int main()
{
	struct student s1;
	printf("Enter Student no 1:");
	s1 = FillStudent();
	PrintStudent(s1);
	getch();
	struct student stds[3];
	for(int i = 0; i < 3; i++)
	{
		printf("\nEnter Student no %d",i+2);
		stds[i] = FillStudent() ;
	}

	for(i = 0; i < 3;i++)
	{
		printf("\nStudent you added before is:\n\tStudent no %d\n\t\tStudent id: %d\n\t\tStudent name: %s\n\n", i+2, stds[i].id, stds[i].name);
	}

	getch();
	clrscr();
	return 0;
}

struct student FillStudent()
{
	struct student std;
	char n[20];
	cout<<"\n\tEnter Student id: ";
	cin>>std.id;
	printf("\n\tEnter student name: ");
	scanf("%s", n);
	strcpy(std.name, n);

	return std;
}

void PrintStudent(struct student std)
{
	printf("\tStudent id: %d\n\tStudent name: %s", std.id, std.name);
}