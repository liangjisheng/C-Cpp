// reler.cpp -- using recursion to subdivide a ruler
#include"iostream"
const int Len=66;
const int Divs=6;
void subdivide(char ar[],int,int,int);

int main() {
	char ruler[Len];
	int i;
	for(i=1;i<Len-2;i++)
		ruler[i]=' ';
	ruler[0]='|'; ruler[Len-2]='|';ruler[Len-1]='\0';
	int max=Len-2,min=0;
	std::cout<<ruler<<std::endl;
	for(i=1;i<=Divs;i++) {
		subdivide(ruler,min,max,i);
		std::cout<<ruler<<std::endl;
		for(int j=1;j<Len-2;j++)
			ruler[j]=' ';
	}
	return 0;
}

void subdivide(char ar[],int low,int high,int level) {
	if(level==0) return ;
	int mid=(low+high)/2;
	ar[mid]='|';
	subdivide(ar,low,mid,level-1);
	subdivide(ar,mid,high,level-1);
}