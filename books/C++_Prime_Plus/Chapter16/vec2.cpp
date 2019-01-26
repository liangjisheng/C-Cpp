// vec2.cpp -- methods and iterator
#include"iostream"
#include"string"
#include"vector"
#include"algorithm"

struct Review {
	std::string title;
	int rating;
};

bool operator < (const Review & r1,const Review & r2);
bool worseThan(const Review & r1,const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main() 
{
	using namespace std;
	vector<Review> books;
	Review temp;
	while(FillReview(temp))
		books.push_back(temp);
	int num=books.size();
	if(num>0) {
		cout<<"\noutput vector<Review>:\n";
		for(int i=0;i<num;i++)
			ShowReview(books[i]);
		cout<<"\nRe output the books:\n";
		vector<Review>::iterator iter;
		for(iter=books.begin(); iter!=books.end(); iter++)
			ShowReview(*iter);

		cout<<endl;
		cout<<"Re output the books:\n";
		for_each(books.begin(),books.end(),ShowReview);

		sort(books.begin(),books.end());
		cout<<"\nSorted by title:\nRating\tBook\n";
		for_each(books.begin(),books.end(),ShowReview);

		sort(books.begin(),books.end(),worseThan);
		cout<<"\nSorted by rating:\nRating\tBook\n";
		for_each(books.begin(),books.end(),ShowReview);

		random_shuffle(books.begin(),books.end());
		cout<<"\nAfter shuffling:\nRating\tBook\n";
		for_each(books.begin(),books.end(),ShowReview);
		cout<<"\nBye!\n";
	}
	else 
		cout<<"There is no any data\n";

	return 0;
}

bool operator < (const Review & r1,const Review & r2) {
	if(r1.title<r2.title)
		return true;
	else if(r1.title==r2.title && r1.rating<r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review & r1,const Review & r2) {
	if(r1.rating < r2.rating)
		return true;
	else 
		return false;
}

bool FillReview(Review & rr) {
	using std::cout;
	using std::cin;
	cout<<"\ninput a string(quit to quit):";
	std::getline(cin,rr.title,'\n');
	if(rr.title=="quit")
		return false;
	cout<<"input a integer:";
	cin>>rr.rating;
	while(cin.get()!='\n')
		continue;
	if(!std::cin)
		return false;
	return true;
}
void ShowReview(const Review & rr) {
	using std::cout;
	using std::endl;
	cout<<rr.rating<<" :"<<rr.title<<endl;
}