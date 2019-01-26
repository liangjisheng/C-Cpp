//:VECTOR.CPP -Test "infinite" vector
#include"fstream.h"
#include"allege.h"
#include"vector.h"
#include"SString.h"
typedef SString<40> String;

int main() {
	ifstream source("vector.cpp");
	allegefile(source);
	const bsz=255;
	char buf[bsz];
	vector<String> words;
	int i=0;
	while(source.getline(buf,bsz)) {
		char* s=strtok(buf," \t");
		while(s) {
			words[i++]=new String(s);
			s=strtok(0," \t");
		}
		words[i++]=new String("\n");
	}
	for(int j=0;words[j];j++)
		cout<<*words[j]<<' ';
	return 0;
}