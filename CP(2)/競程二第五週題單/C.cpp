#include <iostream>
#include <cmath>

using namespace std;

struct point
{
	double x,y;
	
	point (){}
	
	point (double a,double b)
	{
		x = a;
		y = b;
	}
	
	point operator + (point b)
	{
		point re;
		re.x = x+b.x;
		re.y = y+b.y;
		return re;
	}
	point operator - (point b)
	{
		point re;
		re.x = x-b.x;
		re.y = y-b.y;
		return re;
	}
	point operator / (double p) 
	{
    	return point (x / p, y / p);
	}
	point operator * (double p) 
	{
    	return point (x * p, y * p);
	}
};
double maxx = -1e9,minn = 1e9;

double dot(point a,point b)
{
	return a.x * b.x + a.y * b.y;
}

double cross(point A,point B)
{
    return A.x * B.y - A.y * B.x;
}

double length(point a) //as vector
{
	return sqrt(dot(a,a));
}

int dcmp(double x) 
{
    if (fabs (x) < (1e-10)) return 0;
    else    return x < 0 ? -1 : 1;
}

bool operator == (point a, point b)
{
    return dcmp (a.x - b.x) == 0 && dcmp (a.y - b.y) == 0;
}

double dis_to_seg(point p, point a, point b)
{
    if (a.x == b.x && a.y == b.y)
		return length (p - a);
    point V1 = b - a, V2 = p - a, V3 = p - b;
    
    if (dcmp (dot (V1, V2)) < 0)    return length (V2);
    else if (dcmp (dot (V1, V3)) > 0)   return length (V3);
    else    return fabs (cross (V1, V2)) / length (V1);
}

void updata(point p, point a, point b)
{
    minn = min (minn, dis_to_seg (p, a, b));
    maxx = max (maxx, max (length (p - a), length (p - b)));
}

point A[51],B[51];

int main()
{
	int I,kase = 1;
	cin >> I;
	while(I--)
	{
		int A_s,B_s;
		cin >> A_s >> B_s;
		
		for(int i=0;i<A_s;i++)
			cin >> A[i].x >> A[i].y;
		for(int i=0;i<B_s;i++)
			cin >> B[i].x >> B[i].y;
		
		double lena=0,lenb=0;
		for(int i=0;i<A_s-1;i++)
			lena += length(A[i+1] - A[i]);
		for(int i=0;i<B_s-1;i++)
			lenb += length(B[i+1] - B[i]);
		
		int sa=0,sb=0;
		point pa = A[0],pb = B[0];
		
		while (sa < A_s - 1 && sb < B_s - 1)  {
            double la = length (A[sa+1] - pa);
            double lb = length (B[sb+1] - pb);
            double tim = min (la / lena, lb / lenb);
            point Va = (A[sa+1] - pa) / la * tim * lena;
            point Vb = (B[sb+1] - pb) / lb * tim * lenb;
            updata (pa, pb, pb + Vb - Va);
            pa = pa + Va;
            pb = pb + Vb;
            if (pa == A[sa+1])
				sa++;
            if (pb == B[sb+1])
				sb++;
        }
		
		printf ("Case %d: %.0f\n", kase++, maxx - minn);
		maxx = -1e9;minn = 1e9;
	}
}
