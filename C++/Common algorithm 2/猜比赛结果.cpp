//两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。已抽签决定
//比赛名单。有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出
//三队赛手的名单。
#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	char i,j,k;
	for(i='x';i<='z';i++)
		for(j='x';j<='z';j++){
			if(i!=j){
				for(k='x';k<='z';k++){
					if(i!=k&&k!=j){
					if(i!='x'&&k!='x'&&k!='z')
						cout<<"a-"<<i<<" b-"<<j<<" c-"<<k<<endl;
					}
				}
			}
		}
	return 0;
}


//以下代码和上面给代码具有相同效果
#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	char i,j,k;
	for(i='x';i<='z';i++)
		for(j='x';j<='z';j++){
			if(i!=j){
				for(k='x';k<='z';k++){
					if(i!='x'&&k!='x'&&k!='z'&&i!=k&&k!=j)
						cout<<"a-"<<i<<" b-"<<j<<" c-"<<k<<endl;
				}
			}
		}
	return 0;
}