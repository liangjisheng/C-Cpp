// use_tv.cpp -- using the Tv and Remote classes
#include"iostream"
#include"tv.h"

int main() 
{
	using std::cout;
	Tv s;
	cout<<"Initial settings for s\" TV:\n";
	s.settings();
	s.onoff();
	s.chanup();
	cout<<"\n Adjusted settings for s\" TV: \n";
	s.settings();

	Remote r;
	r.set_chan(s,10);
	r.volup(s);
	r.volup(s);
	cout<<"\ns\" settings after using remote:\n";
	s.settings();

	Tv s1(Tv::On);
	s1.set_mode();
	r.set_chan(s1,28);
	cout<<"\ns1\" settings: \n";
	s1.settings();

	return 0;
}