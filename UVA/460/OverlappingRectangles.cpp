#include <cstring>
#include <cstdio>
#include <cmath>

int main()
{
	int n, x1, y1, x2, y2, x3, y3, x4, y4;
	while (~scanf("%d",&n))
	while (n --) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
		
		x1 = x1>x3?x1:x3;
		y1 = y1>y3?y1:y3;
		
		x2 = x2<x4?x2:x4;
		y2 = y2<y4?y2:y4;
		
		if (x1 < x2 && y1 < y2)
			printf("%d %d %d %d\n",x1,y1,x2,y2);
		else printf("No Overlap\n");
		if (n) printf("\n");
	}
	
    return 0;
}
