#include <iostream>

using namespace std;

struct point
{
	double x,y;
};

struct segment
{
	point s,t;
};

double cross(point o, point a, point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

double in(double a, double b, double c)
{
    return c >= a && c <= b;
}

int onLine(segment a, point c)
{
    static double minx, maxx, miny, maxy;
    minx = min(a.s.x, a.t.x);
    maxx = max(a.s.x, a.t.x);
    miny = min(a.s.y, a.t.y);
    maxy = max(a.s.y, a.t.y);
    if(in(minx, maxx, c.x) != 0 && in(miny, maxy, c.y) != 0) {
        if((a.s.x-a.t.x)*(c.y-a.s.y) == (a.s.y-a.t.y)*(c.x-a.s.x)) {
            return 1;
        }
    }
    return 0;
}

int intersection(segment a, segment b)
{
    if(onLine(a, b.s) || onLine(a, b.t) || onLine(b, a.s) || onLine(b, a.t))
        return 1;
    if(cross(a.s, a.t, b.s)*cross(a.s, a.t, b.t) < 0 &&
       cross(a.t, a.s, b.s)*cross(a.t, a.s, b.t) < 0 &&
       cross(b.s, b.t, a.s)*cross(b.s, b.t, a.t) < 0 &&
       cross(b.t, b.s, a.s)*cross(b.t, b.s, a.t) < 0
       )
        return 1;
    return 0;
}

int main()
{
	int t;
    segment line, edge;
    double xl, yt, xr, yb, tmp;
    cin >> t;
    while(t--)
	{
        cin >> line.s.x >> line.s.y;
        cin >> line.t.x >> line.t.y;
        cin >> xl >> yt >> xr >> yb;
        if(xl > xr)
            tmp = xl, xl = xr, xr = tmp;
        if(yt < yb)
            tmp = yt, yt = yb, yb = tmp;
        if(in(xl, xr, line.s.x) && in(yb, yt, line.s.y))
            cout << 'T';
        else if(in(xl, xr, line.t.x) && in(yb, yt, line.t.y))
            cout << 'T';
        else {
            int flag = 0;
            edge.s.x = xl, edge.s.y = yt, edge.t.x = xl, edge.t.y = yb;
            flag |= intersection(edge, line);
            edge.s.x = xr, edge.s.y = yt, edge.t.x = xr, edge.t.y = yb;
            flag |= intersection(edge, line);
            edge.s.x = xl, edge.s.y = yb, edge.t.x = xr, edge.t.y = yb;
            flag |= intersection(edge, line);
            edge.s.x = xl, edge.s.y = yt, edge.t.x = xr, edge.t.y = yt;
            flag |= intersection(edge, line);
            if(flag)
                cout << 'T';
            else
                cout << 'F';
        }
        cout << endl;
    }
    return 0;
}
