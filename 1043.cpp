#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int cc, rc;
struct circle
{
    double x, y, r;
}c[100];
struct rect
{
    double l, r, d, u;
}r[100];
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
bool inc(int i, double x, double y)
{
    return dist(x, y, c[i].x, c[i].y) - c[i].r <= eps;
}
bool inr(int i, double x, double y)
{
    return (x >= r[i].l&&x <= r[i].r&&y >= r[i].d&&y <= r[i].u);
}
double solve(double l, double h)
{
    default_random_engine e(time(0));
    uniform_real_distribution<double> x(-l, l);
    uniform_real_distribution<double> y(-h, h);
    int ans = 0;
    for (int t = 0; t < 1000000; ++t)
    {
        bool f = 1;
        double xi = x(e), yi = y(e);
        for (int i = 0; i < cc && f; ++i)
            if (inc(i, xi, yi))
                f = 0;
        for (int i = 0; i < rc && f; ++i)
            if (inr(i, xi, yi))
                f = 0;
        if (f)
            ++ans;
    }
    double res = ans;
    res /= 10000;
    return res;
}
int main()
{
    double l, h;
    while (cin >> l >> h)
    {
        cin >> cc;
        for (int i = 0; i < cc; ++i)
            cin >> c[i].x >> c[i].y >> c[i].r;
        cin >> rc;
        for (int i = 0; i < rc; ++i)
            cin >> r[i].l >> r[i].r >> r[i].d >> r[i].u;
        cout << (int)solve(l, h) << "%" << endl;
    }
}
