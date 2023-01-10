#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<alloc.h>
#include<string.h>

struct node
{
	int num;
	struct node *next;
};

struct node *tail;

void PrintMenue(void);
void PrintAllNodes(void);
int PushNode(int num);
struct node* PopNode(void);

int main()
{

	int           row;
	int          flag;
	char           ch;
	int           num;
	struct node *temp;

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
							if(PushNode(num))
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

						       temp = PopNode();
						       if(temp)
						       {
								printf("The value deleted is %d", temp->num);
						       }
						       else
						       {
								printf("The stack is empty!");
						       }
						       getch();
						       break;

						case 3:
							PrintAllNodes();
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
	printf("1- Add node in the stack\n2- Pop node from the stack\n3- Print all nodes in the stack\n4- Exit");
	gotoxy(1,1);
}

struct node* CreateNode(int num)
{

	struct node *newNode;
	newNode = (struct node *) malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;


	return newNode;
}

int PushNode(int num)
{
	int retVal = 0;
	struct node *newNode;
	newNode = CreateNode(num);
	if(tail == NULL)
	{
		tail = newNode;
		retVal = 1;
	}
	else
	{
		newNode->next = tail;
		tail = newNode;
		retVal = 1;
	}
	return retVal;
}

struct node* PopNode()
{
	int i;
	struct node *temp;
	temp = NULL;
	if(tail)
	{
		temp = tail;
		tail = tail->next;
	}
	return temp;

}

void PrintAllNodes()
{
	clrscr();

	if(tail)
	{
		int i = 1;
		struct node *cursor;

		cursor = tail;

		while(cursor != NULL)
		{
			printf("Node no %d:\n\tValue: %d\n\n", i, cursor->num);
			cursor = cursor->next;
			i++;
		}

	}
	else
	{
		printf("There is no nodes in the stack...");
	}


	getch();
}