#include<stdio.h>
#include<conio.h>
#include<math.h>
double add(double fNo,double sNo);
double sub(double fNo,double sNo);
double multiply(double fNo, double sNo);
double div(double fNo, double sNo);

int main()
{

	int    row;
	int   flag;
	char    ch;
	double result;
	double    fNo;
	double    sNo;

	flag = 1;
	row  = 1;
	printf("1- Add\n2- Subtract\n3- Multiply\n4- Divide\n5- Exit");
	gotoxy(1,row);

	do
	{
		ch = getch();
		if(ch == 0)
		{
			ch = getch();
			switch(ch)
			{
				case 80:
					if(row == 5)
					{
						row = 1;
					}
					else
					{
						row++;
					}
					break;
				case 72:
					if(row == 1)
					{
						row = 5;
					}
					else
					{
						row--;
					}
					break;
				case 75:
					row = 1;
					break;
				case 77:
					row = 5;
					break;
			}
			gotoxy(1,row);

		}
		else
		{
			switch(ch)
			{
				case 13:
					if(row == 5)
					{
						flag = 0;
					}
					else
					{
						clrscr();
						printf("Enter first number: ");
						scanf("%lf",&fNo);
						printf("Enter second number: ");
						scanf("%lf",&sNo);

						if(row == 1)
						{
							result = add(fNo,sNo);

						}
						else if(row == 2)
						{
							result = sub(fNo,sNo);
						}
						else if(row == 3)
						{
							result = multiply(fNo,sNo);
						}
						else if(row == 4)
						{
							result = div(fNo,sNo);
						}

						printf("The result is %lf",result);
						getch();
						clrscr();
						printf("1- Add\n2- Subtract\n3- Multiply\n4- Divide\n5- Exit");
						gotoxy(1,row);

					}
					break;
				case 27:
					flag = 0;

			}
		}
	}while(flag == 1);

	clrscr();
	return 0;
}


double add(double fNo, double sNo)
{
	double result;
	result = fNo + sNo;
	return result;
}


double sub(double fNo,double sNo)
{
	double result;
	result = fNo - sNo;
	return result;
}

double multiply(double fNo, double sNo)
{
	double result;
	result = fNo * sNo;
	return result;
}

double div(double fNo, double sNo)
{
	double result;
	result = fNo/sNo;
	return result;
}






