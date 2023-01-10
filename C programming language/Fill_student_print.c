#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>


struct student
{
	int id;
	int i;
	char name[20];
	int grades[3];
};
struct student FillStd(void);
void PrintStd(struct student std);

int main()
{

	int i;
	int size;
	struct student *StdPtr, *cursor;

	printf("Enter number of students you want to add: ");
	scanf("%d",&size);


	StdPtr = (struct student*) malloc(size * sizeof(struct student));
	cursor = StdPtr;

	for(i = 0;i < size; i++)
	{
		*cursor = FillStd();
                cursor++;
	}
	cursor = StdPtr;
	for(i = 0;i < size;i++)
	{
		PrintStd(*cursor);
		cursor++;
	}

	getch();
	clrscr();
	return 0;
}

struct student FillStd()
{
	int i;
	struct student std;
	printf("Enter Student id: ");
	scanf("%d",&std.id);

	printf("Enter Student name: ");
	scanf("%s",std.name);

	for(i = 0;i < 3;i++)
	{
		printf("Enter grade %d for student %d: ",i+1,std.id);
		scanf("%d",&std.grades[i]);
	}
        printf("\n");


	return std;
}

void PrintStd(struct student std)
{
	int i;
	printf("\nStudent id: %d\nStudent name: %s\nStudent grades: \n\n",std.id,std.name);
	for(i = 0; i < 3;i++)
	{
		printf("\tGrade %d: %d\n",i+1,std.grades[i]);
	}


}