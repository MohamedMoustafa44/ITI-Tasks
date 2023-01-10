#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

class base
{
	int x;
	public:
		base()
		{
			x = 0;
		}
		base(int data)
		{
			x = data;
		}
		void SetX(int data)
		{
			x = data;
		}
		int GetX()
		{
			return x;
		}
};
class derived1: public base
{
	int y;
	public:
		derived1(): base()
		{
			y = 0;
		}
		derived1(int x, int data): base(x)
		{
			y = data;
		}
		void SetY(int data)
		{
			y = data;
		}
		int GetY()
		{
			return y;
		}
};
class derived2: public base
{
	int z;
	public:
		derived2(): base()
		{
			z = 0;
		}
		derived2(int x, int data): base(x)
		{
			z = data;
		}
		void SetZ(int data)
		{
			z = data;
		}
		int GetY()
		{
			return z;
		}
};
class derived: public derived1, public derived2
{
	int data;
	public:
		derived(): derived1()
		{
			data = 0;
		}
		derived(int x, int y, int d): derived1(x, y)
		{
			data = d;
		}
		void SetD(int d)
		{
			data = d;
		}
		int GetD()
		{
			return data;
		}
};
