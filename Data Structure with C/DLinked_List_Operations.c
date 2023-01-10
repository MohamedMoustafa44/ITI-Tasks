#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<alloc.h>
#include<string.h>

struct student
{
	int id;
	char name[20];
	int grades[3];
};

struct node
{
	struct student std;
	struct node *next, *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

struct student CreateStudent(void);
struct node* CreateNode(struct student s);
int AddNode(struct student s);
int InsertNode(struct student, int loc);
void SearchById(int id);
void SearchByName(char name[20]);
int DeleteNodeById(int id);
int UpdateStudent(int id);
void PrintAllNodes(void);
void PrintMenue(void);
void BubleSort(void);
struct student *ConvertNodesToArray();
void MergeSort(int LB, int UB);
void Merge(int low, int mid, int high);
void FreeList(void);

int main()
{
	int       row;
	int      flag;
	char       ch;
	int       loc;
	int        id;
	char Name[20];

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
					if(row == 10)
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
						row = 10;
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
					row=10;
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
							AddNode(CreateStudent());
							break;
						case 2:

							printf("Enter location you want to add to: ");
							scanf("%d",&loc);
							InsertNode(CreateStudent(),loc);
							break;
						case 3:
							printf("Enter id you want to search by: ");
							scanf("%d",&id);
							SearchById(id);
							break;
						case 4:
							printf("Enter the name you want to search by: ");
							scanf("%s",Name);
							SearchByName(Name);
							break;
						case 5:

							printf("Enter student id you want to delete: ");
							scanf("%d",&id);
							if(DeleteNodeById(id))
							{
								printf("Data is deleted");
								getch();
							}
							break;
						case 6:
							PrintAllNodes();
							break;
						case 7:

							FreeList();
							break;
						case 8:
							printf("Enter id you want to update: ");
							scanf("%d",&id);
							if(UpdateStudent(id)){
								printf("Data is updated!");
								getch();
							}
							break;
						case 9:

							BubleSort();
							getch();
							break;
						case 10:
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
	printf("1- Add node\n2- Insert node\n3- Search by id\n4- Search by name\n5- Delete node\n6- Print all\n7- Free list\n8- Update student\n9- Buble Sort\n10- Exit");
	gotoxy(1,1);
}

struct student CreateStudent()
{

	int i;
	struct student std;
	printf("Enter student id: ");
	scanf("%d",&std.id);
	printf("Enter student name: ");
	scanf("%s",std.name);
	for(i = 0;i < 3;i++)
	{
		printf("Enter grade %d: ", i+1);
		scanf("%d",&std.grades[i]);
	}
	return std;

}


struct node* CreateNode(struct student s)
{

	struct node *newNode = malloc(sizeof(struct node));
	newNode -> std = s;

	return newNode;
}


int AddNode(struct student s)
{
	int retVal = 0;
	struct node *newNode = CreateNode(s);
	if(newNode)
	{
		retVal = 1;
		if(head) //There is a list
		{
			tail->next    = newNode;
			newNode->prev =    tail;
			tail          = newNode;
			tail->next = NULL;
		}
		else //There is empty list
		{
			head = tail = newNode;
			tail->next = NULL;
		}
	}
	return retVal;

}

int InsertNode(struct student s, int loc)
{
	int retVal = 0;
	int i;
	struct node *temp;
	struct node *newNode = CreateNode(s);
	if(newNode)
	{       retVal = 1;
		temp = head;
		if(head)
		{
			if(loc == 0)
			{
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			else
			{
				for(i = 0;i < loc && temp->next;i++)
				{
					temp = temp->next;
				}
				if(temp->next == NULL)
				{
					AddNode(s);
				}
				else
				{

					temp->next->prev = newNode;
					newNode->next = temp->next;
					newNode->prev = temp;
					temp->next = newNode;
				}
			}

		}
		else
		{
			head = tail = newNode;
			tail -> next =NULL;
		}
	}
	return retVal;
}

void SearchById(int id)
{
	int i;
	struct node *temp;
	if(head)
	{
		temp = head;
		for(i = 0; temp; i++)
		{
			if(temp->std.id == id)
			{
				printf("\nI found it ^_^\nhere is the whole student data:");
				printf("\n\tStudent id: %d",temp->std.id);
				printf("\n\tStudent name: %s",temp->std.name);
				printf("\n\tStudent grades:");
				for(i = 0; i < 3; i++)
				{
					printf("\n\t\t Grade %d: %d",(i+1),temp->std.grades[i]);
				}
				break;
			}
			temp = temp->next;
		}
		if(!temp)
		{
			printf("Data not found!");
		}
	}
	getch();

}

void SearchByName(char Name[20])
{
	int i;
	struct node *temp;
	if(head)
	{
		temp = head;
		for(i = 0; temp; i++)
		{
			if(!strcmp(temp->std.name,Name))
			{
				printf("\nI found it ^_^\nhere is the whole student data:");
				printf("\n\tStudent id: %d",temp->std.id);
				printf("\n\tStudent name: %s",temp->std.name);
				printf("\n\tStudent grades:");
				for(i = 0; i < 3; i++)
				{
					printf("\n\t\t Grade %d: %d",(i+1),temp->std.grades[i]);
				}
				break;
			}
			temp = temp->next;
		}
		if(!temp)
		{
			printf("Data not found!");
		}
	}
	getch();

}

int DeleteNodeById(int id)
{
	int retVal;
	int i;
	struct node *temp;
	retVal = 0;
	if(head)
	{
		if(head==tail)
		{
			FreeList();
		}
		else
		{
			temp = head;
			for(i = 0; temp; i++)
			{
				if(temp->std.id == id)
				{
					retVal = 1;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					break;
				}
				temp = temp->next;
			}
		}
		if(!temp)
		{
			printf("Data not found!");
		}
	}
	return retVal;
}

int UpdateStudent(int id)
{
	int retVal;
	int i;
	struct node *temp;
	retVal = 0;
	if(head)
	{


		temp = head;
		for(i = 0; temp; i++)
		{
			if(temp->std.id == id)
			{
				retVal = 1;
				printf("Enter new name: ");
				scanf("%s",temp->std.name);
				printf("Enter new grades: ");
				for(i = 0; i < 3; i++)
				{
					printf("\n\t\t Enter grade %d: ",(i+1));
					scanf("%d",&temp->std.grades[i]);
				}

				break;
			}
			temp = temp->next;
		}
		if(!temp)
		{
			printf("Data not found!");
		}
	}
	return retVal;
}

void PrintAllNodes()
{
	clrscr();

	if(head)
	{

		int i;
		struct node *cursor;


		cursor = head;

		while(cursor)
		{
			printf("Student number %d:\n\n\tStudent name : %s",cursor->std.id,cursor->std.name);

			for(i = 0; i < 3;i++)
			{
				printf("\n\tGrade %d: %d", i+1, cursor ->std.grades[i]);
			}

			printf("\n\n\n");

			cursor = cursor->next;
		}

	}

	getch();
}

void BubleSort()
{
	int i;
	struct student tempStd;
	int counter;
	struct node *temp;
	counter = 1;
	temp = head;    
	if(temp)
	{
		for(i = 0; temp; i++)
		{
			temp = temp->next;
			counter++;
		}

		for(i = 0;i<counter; i++)
		{
			temp = head;
			while(temp->next)
			{
				if(temp->std.id > temp->next->std.id)
				{
					tempStd = temp->std;
					temp->std = temp->next->std;
					temp->next->std = tempStd;
				}


				temp = temp->next;

			}
		}


	}
}
struct student *ConvertNodesToArray()
{
	int i;
	struct student *StdArr;
	struct student *cursor;
	int counter;
	struct node *temp;

	counter = 1;
	temp = head;

	if(temp)
	{
		for(i = 0; temp; i++)
		{
			temp = temp->next;
			counter++;
		}
		temp = head;


	}

	StdArr = malloc(counter * sizeof(struct student));
	cursor = StdArr;

	for(i = 0; i < counter && temp; i++)
	{
		cursor[i] = temp->std;
		temp = temp->next;
	}
	return StdArr;

}

void MergeSort(int LB, int UB)
{

	int middle;
	struct student *StdArr;
	if(head)
	{
		StdArr = ConvertNodesToArray();
		if(LB < UB)
		{
			middle = (LB+UB)/2;
			MergeSort(LB, middle);
			MergeSort(middle+1, UB);
			Merge(LB, middle, UB);
		}
	}


}

void Merge(int low, int mid, int high)
{

}

void FreeList()
{
	int i;
	struct node *temp;
	if(head)
	{
		temp = head;
		for(i = 0; temp; i++)
		{
			head = head->next;
			free(temp);
			temp = head;

		}
        	tail = NULL;

	}
}

