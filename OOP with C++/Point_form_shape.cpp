#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

class point
{
	int x;
	int y;
	public:
		point(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
		void SetX(int x)
		{
			this->x = x;
		}
		void SetY(int y)
		{
			this->y = y;
		}
		int GetX()
		{
			return x;
		}
		int GetY()
		{
			return y;
		}
		point operator =(point p)
		{
			this->x = p.x;
			this->y = p.y;
			return *this;
		}

};

class rectangle
{
	point p1;
	point p2;
	int GetLen(point p1, point p2)
	{
		return (abs(p1.GetY() - p2.GetY()));
	}
	int GetWidth(point p1, point p2)
	{
		return (abs(p1.GetX() - p2.GetX()));
	}
	public:

		rectangle(int x1, int y1, int x2, int y2):p1(x1,y1), p2(x2, y2)
		{}
		void SetP1(int x, int y)
		{
			p1.SetX(x);
			p1.SetY(y);
		}
		void SetP2(int x, int y)
		{
			p2.SetX(x);
			p2.SetY(y);
		}
		point GetP1()
		{
			return p1;
		}
		point GetP2()
		{
			return p2;
		}
		int GetArea()
		{
			return (this->GetLen(p1, p2) * this->GetWidth(p1, p2));
		}

};
class circle
{
	point *p1;
	point *p2;
	double GetR(point &fP, point &sP)
	{
		*p1 = fP;
		*p2 = sP;
		double radius = sqrt(pow(p1->GetX() - p2->GetX(), 2) + pow(p1->GetY() - p2->GetY() , 2));
		return radius;
	}
	public:
		circle(point *fP, point *sP)
		{
			p1 = fP;
			p2 = sP;
		}
		~circle()
		{
			delete(p1);
			delete(p2);
		}
		void SetP1(int x, int y)
		{
			p1->SetX(x);
			p1->SetY(y);
		}
		void SetP2(int x, int y)
		{
			p2->SetX(x);
			p2->SetY(y);
		}
		point GetP1()
		{
			return *p1;
		}
		point GetP2()
		{
			return *p2;
		}
		double GetArea()
		{
			return (3.14 * pow(this->GetR(*p1, *p2), 2));
		}
};

int main()
{

	rectangle rct(0,0,4,6);
	cout<<rct.GetArea()<<endl;
	point p1(0,0);
	point p2(5,0);
	circle c(&p1, &p2);
	cout<<c.GetArea();

	getch();
	clrscr();
	return 0;
}