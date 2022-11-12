#include <iostream>
#include <cmath>
using namespace std;

 
int main() {
	double h,l;
	cin>>h>>l;
	printf("%.13lf",fabs((h*h-l*l)/(2*h)));
	return 0;
}
