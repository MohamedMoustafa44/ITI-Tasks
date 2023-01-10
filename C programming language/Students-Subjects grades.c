#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

int main()
{

	int   std_sub[4][3];
	int avg       = 0;
	int   gSum      = 0;
	int      col;
	int      row;




	for(col = 0;col < 4;col++)
	{

		for(row = 0;row < 3;row++)
		{
			printf("Enter subject %d grade for student %d: ",row+1,col+1);
			scanf("%d", &std_sub[col][row]);
		}

	}
	printf("      subj1\tsubj2\tsubj3\tstudent sum\n");

	for(col = 0;col < 4;col++)
	{
		printf("STD%d: ",col+1);
		for(row = 0;row < 3;row++)
		{
			printf("%d\t", std_sub[col][row]);
			gSum += std_sub[col][row];

		}

		printf("%d",gSum);
		printf("\n");
		gSum=0;
	}
	printf("AVG : ");
	for(col = 0;col < 4;col++)
	{
		for(row = 0;row < 3;row++)
		{
			avg += std_sub[col][row];
		}
		avg = avg/4;
		printf("%d\t",avg);
		avg = 0;
	}





	getch();
	clrscr();
	return 0;
}