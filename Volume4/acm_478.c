/* @JUDGE_ID:50418EN 478 C */
#include <stdio.h>
#include <math.h>

struct Figure
{
	char tag;
	double number[6];
}fig[11];

int num_fig=1, num_points=1;
double x, y;

void read_fig()
{
	char tag;
	while(1){
		scanf("%c", &tag);
		if(tag == '*')
			break;
		else if(tag == 'r'){
			fig[num_fig].tag = 'r';
			scanf("%lf %lf %lf %lf", &fig[num_fig].number[0], &fig[num_fig].number[1], &fig[num_fig].number[2], &fig[num_fig].number[3]);
			num_fig++;
		}
		else if(tag == 'c'){
			fig[num_fig].tag = 'c';
			scanf("%lf %lf %lf", &fig[num_fig].number[0], &fig[num_fig].number[1], &fig[num_fig].number[2]);
			num_fig++;
		}
		else if(tag == 't'){
			fig[num_fig].tag = 't';
			scanf("%lf %lf %lf %lf %lf %lf", &fig[num_fig].number[0], &fig[num_fig].number[1], &fig[num_fig].number[2], &fig[num_fig].number[3], &fig[num_fig].number[4], &fig[num_fig].number[5]);
			num_fig++;
		}
	}
}

int read_point()
{
	scanf("%lf %lf", &x, &y);
	if(x == 9999.9 && y == 9999.9)
		return 0;
	else
		return 1;
}

double tri_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double temp;
	temp = fabs( (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3) ) / 2;
	return temp;
}

void test_point()
{
	int i, check_in=0;
	double temp;
	for(i=1 ; i<num_fig ; i++){
		if(fig[i].tag == 'r'){
			if( ((x - fig[i].number[0]) * (x - fig[i].number[2]) < 0) && ((y - fig[i].number[1]) * (y - fig[i].number[3])) < 0 ){
				printf("Point %d is contained in figure %d\n", num_points, i);
				check_in = 1;
			}
		}
		else if(fig[i].tag == 'c'){
			if( (x - fig[i].number[0]) * (x - fig[i].number[0]) + (y - fig[i].number[1]) * (y - fig[i].number[1]) - fig[i].number[2] * fig[i].number[2] < 0  ){
				printf("Point %d is contained in figure %d\n", num_points, i);
				check_in = 1;
			}
		}
		else if(fig[i].tag == 't'){
			temp = fabs( tri_area(fig[i].number[0],fig[i].number[1],fig[i].number[2],fig[i].number[3],x,y) + tri_area(fig[i].number[2],fig[i].number[3],fig[i].number[4],fig[i].number[5],x,y) + tri_area(fig[i].number[4],fig[i].number[5],fig[i].number[0],fig[i].number[1],x,y) - tri_area(fig[i].number[0],fig[i].number[1],fig[i].number[2],fig[i].number[3],fig[i].number[4],fig[i].number[5]) );
			if( temp<0.000001 ){
				printf("Point %d is contained in figure %d\n", num_points, i);
				check_in = 1;
			}
		}
	}
	if(check_in == 0)
		printf("Point %d is not contained in any figure\n", num_points);
	num_points++;
}

int main()
{
	/*freopen("Data.txt", "r", stdin);*/
	read_fig();
	while(read_point() == 1)
		test_point();
	return 0;
}
