#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double eps = 1e-6;

typedef struct _point
{
	double x, y;
}point;
point M, P1, P2;

point new_point(double x, double y)
{
	point ans;
	ans.x = x;
	ans.y = y;
	return ans;
}

double distance(point p, point q)
{
	return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

point foot_point(point m, point p, point q) // Ax + by + C = 0
{
	double A1 = p.x-q.x, B1 = p.y-q.y, C1 = (q.y-p.y)*m.y+(q.x-p.x)*m.x;
	double A2 = q.y-p.y, B2 = p.x-q.x, C2 = (q.x-p.x)*p.y+(p.y-q.y)*p.x;
	double x = (C2*B1-C1*B2)/(A1*B2-A2*B1);  
   	double y = (C2*A1-C1*A2)/(A2*B1-A1*B2);
	return new_point(x, y);
}

bool on_line(point m, point p, point q)
{
	return (p.x-m.x)*(q.x-m.x) <= eps && (p.y-m.y)*(q.y-m.y) <= eps;
}

point closest_point_on_segement(point m, point p, point q)
{
	point ans = foot_point(m, p, q);
	if (!on_line(ans, p, q)) {
		if (distance(m, p) - distance(m, q) > eps) {
			return q;
		}else {
			return p;
		}
	}else {
		return ans;
	}
}

int main()
{
	int n;
	while (~scanf("%lf%lf", &M.x, &M.y)) {
		scanf("%d%lf%lf", &n, &P1.x, &P1.y);
		point  ans = P1;
		double min_dist = distance(M, P1);
		while (n --) {
			scanf("%lf%lf", &P2.x, &P2.y);
			point Q = closest_point_on_segement(M, P1, P2);
			if (distance(M, ans) - distance(M, Q) > eps) {
				ans = Q;
			}
			P1 = P2;
		}
		printf("%.4lf\n%.4lf\n", ans.x, ans.y);
	}
	
	return 0;
}
