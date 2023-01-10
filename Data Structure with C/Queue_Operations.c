#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<alloc.h>
#include<string.h>


int arr[5];
int index = 0;

void PrintMenue(void);
void PrintAll(void);

int InQueue(int num);
int DeQueue(void);

int main()
{

	int    row;
	int   flag;
	char    ch;
	int    num;
	int   temp;

	row  = 1;
	flag = 1;

	PrintMenue();

	do
	{
	    if(flag == 2)
	    {
		PrintMenue();
		flag = 1;
	    }
	    else if(flag == 1)
	    {

		ch = getch();

		if(ch == 0)
		{
			ch = getch();
			switch(ch)
			{
				case 80:
					if(row == 4)
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
						row = 4;
					}
					else
					{
						row--;
					}
					break;
				case 75:
					row=1;
					break;
				case 77:
					row=4;
					break;


			}
			gotoxy(1,row);

		}

		else
		{
			switch(ch)
			{
				case 13:
					flag = 2;
					clrscr();
					switch(row)
					{
						case 1:
							printf("Enter Number you want to add: ");
							scanf("%d", &num);
							if(InQueue(num))
							{
								printf("The Node added");
							}
							else
							{
								printf("There is something wrong!");
							}
							getch();
							break;
						case 2:

						       temp = DeQueue();
						       if(temp)
						       {
								printf("The value deleted is %d", temp);
						       }
						       else
						       {
								printf("The queue is empty!");
						       }
						       getch();
						       break;

						case 3:
							PrintAll();
							break;
						case 4:
							flag = 0;
							break;
					}
			}
	    }
		}

	}while(flag);

	return 0;
}

void PrintMenue()
{
	clrscr();
	printf("1- Add value in the queue\n2- Dequeue\n3- Print all values in the queue\n4- Exit");
	gotoxy(1,1);
}


int InQueue(int num)
{
	int retVal = 0;
	if(index < 5)
	{
		arr[index] = num;
		index++;
		retVal = 1;
	}
	else
	{
		if(index == 5)
		{
			printf("The Queue is Full");
		}
	}
	return retVal;
}

int DeQueue()
{
	int temp = 0;
	int cursor1 = 0;
	int cursor2 = 1;
	if(index > 0) // there are more than one value in the list
	{
		temp = arr[0];
		for(cursor1 = 0; cursor2 < index; cursor1++)
		{
			arr[cursor1] = arr[cursor2];
			cursor2++;
		}
		index--;

	}
	return temp;

}

void PrintAll()
{       int i;

	clrscr();

	for(i = 0; i < index;i++)
	{
		printf("%d\n", arr[i]);
	}


	getch();
}