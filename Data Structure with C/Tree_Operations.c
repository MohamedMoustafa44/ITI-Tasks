#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<alloc.h>
#include<string.h>


struct node
{
	int data;
	struct node *left, *right;
};

void PrintMenue(void);
struct node *CreateNode(int data);
struct node *AddNode(struct node *root, int data);
void PreOrder(struct node *root);
void InOrder(struct node *root);
void PostOrder(struct node *root);
int CountNodes(struct node *root);
int SumNodes(struct node *root);



int main()
{
	int       row;
	int      flag;
	char       ch;
	int data;

	struct node *root = NULL;


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
					if(row == 7)
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
						row = 7;
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
					row=7;
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
							printf("Enter data you want to add: ");
							scanf("%d", &data);
							if(!root)
							{
								root = AddNode(root, data);
							}
							else
							{
								AddNode(root, data);
							}
							break;
						case 2:

							PreOrder(root);
							getch();
							break;
						case 3:
							InOrder(root);
							getch();
							break;
						case 4:
							PostOrder(root);
							getch();
							break;
						case 5:
							printf("The number of nodes in tree is %d", CountNodes(root));
							getch();
							break;
						case 6:
							printf("The sum of all nodes is %d", SumNodes(root));
							getch();
							break;

						case 7:
							flag=0;
							break ;
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
	printf("1- Add Node\n2- PreOrder printing\n3- InOrder printing\n4- PostOrder printing\n5- Count nodes\n6- Sum of all nodes\n7- Exit");
	gotoxy(1,1);
}

struct node *CreateNode(int data)
{
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));
	if(ptr)
	{
		ptr->data = data;
		ptr->left = ptr->right = NULL;
	}
	return ptr;
}

struct node *AddNode(struct node *root, int data)
{
	if(!root)
	{
		root = CreateNode(data);
	}
	else if(root->data >= data)
	{
		root->left = AddNode(root->left, data);
	}
	else
	{
		root->right = AddNode(root->right, data);
	}
	return root;

}

void PreOrder(struct node *root)
{
	if(root)
	{
		printf("%d->", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(struct node *root)
{
	if(root)
	{
		InOrder(root->left);
		printf("%d->", root->data);
		InOrder(root->right);
	}

}

void PostOrder(struct node *root)
{
	if(root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d->", root->data);
	}

}
int SumNodes(struct node *root)
{

	int sum = 0;
	if(root)
	{
		sum += root->data;
		sum += SumNodes(root->left);
		sum += SumNodes(root->right);
		return sum;
	}
	else
	{
		return 0;
	}
}
int CountNodes(struct node *root)
{

	if(root)
	{
		return (1 + CountNodes(root->left) + CountNodes(root->right));
	}
	else
	{
		return 0;
	}
}

