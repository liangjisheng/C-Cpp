// structfun.cpp -- function with a structure argument
/*#include"iostream"
#include"cmath"
using namespace std;

struct polar {
	double distance,angle;
};
struct rect {
	double x,y;
};

polar rect_to_polar(rect);
void show_polar(polar);

int main() {
	rect rplace;
	polar pplace;

	cout<<"Enter the x and y values: ";
	while(cin>>rplace.x>>rplace.y) {  // slick use of cin
		pplace=rect_to_polar(rplace);
		show_polar(pplace);
		cout<<"Next two numbers(a char to quit):";
	}
	cout<<"Done.\n";

	return 0;
}

polar rect_to_polar(rect xypos) {
	polar answer;
	answer.distance=sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle=atan2(xypos.y,xypos.x);
	return answer;
}

void show_polar(polar dapos) {
	cout<<"distance is:"<<dapos.distance<<endl;
	cout<<"angle is:"<<dapos.angle<<endl;
}*/


/*#include"iostream"
#include"cmath"
using namespace std;

struct polar {
	double distance,angle;
};
struct rect {
	double x,y;
};

void rect_to_polar(rect*,polar*);
void show_polar(polar*);

int main() {
	rect rplace;
	polar pplace;

	cout<<"Enter the x and y values: ";
	while(cin>>rplace.x>>rplace.y) {  // slick use of cin
		rect_to_polar(&rplace,&pplace);
		show_polar(&pplace);
		cout<<"Next two numbers(a char to quit):";
	}
	cout<<"Done.\n";

	return 0;
}

void rect_to_polar(rect* xypos,polar* answer) {
	answer->distance=sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
	answer->angle=atan2(xypos->y,xypos->x);
}

void show_polar(polar* dapos) {
	cout<<"distance is:"<<dapos->distance<<endl;
	cout<<"angle is:"<<dapos->angle<<endl;
}*/