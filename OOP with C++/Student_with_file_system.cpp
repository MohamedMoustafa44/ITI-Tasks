#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>


class student
{
	private:
		int id;
		char *name;
		int gpa;
		static int count;
		static char schoolName[50];
	public:
		student()
		{
			this->id = 0;
			this->gpa = 0;
			this->name = new char[8];
			strcpy(name,"Mohamed");
			count++;
		}

		student(int id, char *n, int gpa)
		{
			this->id = id;
			this->gpa = gpa;
			this->name =  new char[strlen(n) + 2];
			strcpy(name, n);
			count++;
		}
		~student()
		{
			delete(name);
			count--;
		}
		student(student &rstd)
		{
			id = rstd.id;
			name = new char[strlen(rstd.name) + 1];
			strcpy(name, rstd.name);
			gpa = rstd.gpa;
			count++;
		}
		void SetId(int i);
		void SetName(char *n);
		void SetGpa(int gpa);
		static int GetCount()
		{
			return count;
		}
		static void SetSchoolName(char name[])
		{
			strcpy(schoolName, name);
		}
		static char* GetSchoolName()
		{
			return schoolName;
		}
		int GetId();
		char * GetName();
		int GetGpa();
		student operator =(student std);
		student operator +(student std);
		student operator +(int bouns);
		student operator +(char *n);
		operator char*();
		operator int();
		friend student operator +(int bouns, student std);
		friend student operator +(char *n, student std);
		friend istream& operator >>(istream& in, student& std);
		friend ostream& operator <<(ostream& out, student std);
};
int student::count = 0;
char student::schoolName [50]= "ITI";
void student::SetId(int i)
{
	id = i;
}

void student::SetName(char *n)
{
	delete(name);
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}
void student::SetGpa(int gpa)
{
	this->gpa = gpa;
}
int student::GetId()
{
	return id;
}
char * student::GetName()
{
	return name;
}
int student::GetGpa()
{
	return gpa;
}
student student::operator =(student std)
{
	this->id = std.id;
	delete(name);
	name = new char[strlen(std.name)+1];
	strcpy(this->name, std.name);
	this->gpa = std.gpa;
	return std;
}
student student::operator +(student std)
{
	this->gpa = this->gpa + std.gpa;
	return *this;
}
student student::operator +(int bouns)
{
	this->gpa = this->gpa + bouns;

	return *this;
}
student student::operator +(char *n)
{
	int fNameLen = strlen(name);
	char *fName;
	fName = new char[fNameLen + 1];
	strcpy(fName, name);
	delete(name);
	name = new char[fNameLen + strlen(n) + 1];
	strcpy(name, fName);
	strcat(name, " ");
	strcat(name, n);
	delete(fName);
	return *this;
}
student::operator char*()
{
	return this->name;
}
student::operator int()
{
	return this->gpa;
}
student operator +(int bouns, student std)
{
	return std + bouns;
}
student operator +(char *n, student std)
{
	int fNameLen = strlen(n);
	int lNameLen = strlen(std.name);
	char *fName, *lName;
	fName = new char[fNameLen+ 1];
	lName = new char[lNameLen+ 1];
	strcpy(fName, n);
	strcpy(lName, std.name);
	delete(std.name);
	std.name = new char[fNameLen + lNameLen + 2];
	strcpy(std.name, fName);
	strcat(std.name, " ");
	strcat(std.name, lName);
	delete(fName);
	delete(lName);
	return std;
}
istream& operator >>(istream& in, student& std)
{
	cout<<"Enter student id: ";
	in>>std.id;
	cout<<"Enter student name: ";
	in>>std.name;
	cout<<"Enter student gpa: ";
	in>>std.gpa;
	return in;
}
ostream& operator <<(ostream& out, student std)
{
	out<<std.id<<endl;
	out<<std.name<<endl;
	out<<std.gpa<<endl;
	return out;
}
student FillStudent()
{
	int id;
	char *name;
	int gpa;
	cout<<"Enter student id: ";
	cin>>id;
	cout<<"Enter student name: ";
	cin>>name;
	cout<<"Enter student gpa: ";
	cin>>gpa;
	student std(id, name, gpa);
	return std;
}
void PrintStudent(student std)
{
	printf("Student id: %d\n",std.GetId());
	printf("Student name: %s\n",std.GetName());
	printf("Student gpa: %d\n", std.GetGpa());
}

int main()
{
	student s1, s2, s3;
	cin>>s1;
	cout<<endl<<"S1:"<<endl<<s1;

	fstream file;
	file.open("student.txt", ios::out);
	file<<s1;
	file.close();

	file.open("student.txt", ios::in);
	file>>s2;
	cout<<endl<<"S2:"<<endl<<s2;
	file.close();

	file.open("binary.txt", ios::out|ios::binary);
	file.write((char*)&s1, sizeof(s1));
	file.close();

	file.open("binary.txt", ios::in|ios::binary);
	file.read((char*)&s3, sizeof(s3));
	cout<<endl<<"S3:"<<endl<<s3;
	file.close();


	getch();
	clrscr();
	return 0;
}

