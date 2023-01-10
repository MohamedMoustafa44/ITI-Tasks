#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

class person
{
	int id;
	char name[20];
	public:
		person()
		{
			id = 0;
			strcpy(name, "No name");
		}
		person(int i, char n[])
		{
			id = i;
			strcpy(name, n);
		}
		void SetId(int i)
		{
			id = i;
		}
		int GetId()
		{
			return id;
		}
		void SetName(char n[])
		{
			strcpy(name, n);
		}
		char* GetName()
		{
			return name;
		}
};

class emp: public person
{
	double salary;
	public:
		emp(int id, char name[], double slry): person(id, name)
		{
			salary = slry;
		}
		void SetSal(double sal)
		{
			salary = sal;
		}
		double GetSal()
		{
			return salary;
		}

};
class cust: public person
{
	char phone[12];
	public:
		cust(int id, char name[], char mob[]): person(id, name)
		{
			strcpy(phone, mob);
		}
		void SetPhone(char mob[])
		{
			strcpy(phone, mob);
		}
		char* GetPhone()
		{
			return phone;
		}
};