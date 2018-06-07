// strtref.cpp -- using structure references
#include"iostream"
using namespace std;
struct sysop{
	char name[50];
	char quote[64];
	int used;
};

const sysop & use(sysop & sysopref);
const sysop & clone(sysop & sysopref);

int main() {
	// Note: some implementation require using the keyword static
	// in the two structure declaretions to enable initialization
	sysop looper={"Rick \"Fortran\" Looper",
					"I'm a goto kind of guy.",
					0};
	use(looper);
	cout<<"looper: "<<looper.used<<" use(s)\n";
	sysop copycat;
	copycat=use(looper);
	cout<<"looper: "<<looper.used<<" use(s)\n";
	cout<<"Copycat: "<<copycat.used<<" use(s)\n";
	cout<<"use(loooper): "<<use(looper).used<<" use(s)\n";

	const sysop & jolly=clone(looper);
	cout<<"jolly: "<<jolly.quote<<endl;
	cout<<"jolly: "<<jolly.used<<endl;

	return 0;
}

const sysop & use(sysop & sysopref) {
	cout<<sysopref.name<<" says:\n";
	cout<<sysopref.quote <<endl;
	sysopref.used++;
	return sysopref;
}

const sysop & clone(sysop & sysopref) {
	sysop * psysop=new sysop;
	*psysop=sysopref;
	return *psysop;
}