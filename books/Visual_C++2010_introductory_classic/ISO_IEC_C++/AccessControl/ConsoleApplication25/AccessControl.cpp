// Using the protected access specifier
#include <iostream>
#include <cstring>
#include"CandyBox.h"
using std::cout;
using std::endl;

int main()
{
	CCandyBox myCandyBox;
	CCandyBox myToffeeBox(2,3,4,"lishuyu");

	cout << "\nmyCandyBox valume is :" << myCandyBox.Volume()
		<< "\nmyToffeeBox volume is :" << myToffeeBox.Volume()
		<< "\nDone\n"<<endl;

	CCandyBox chocBox(2.0, 3.0, 4.0, "lishuyu");
	CCandyBox chocolateBox(chocBox);

	cout << "\nVolume of chocBox is :" << chocBox.Volume()
		<< "\nVolume of chocolateBox is :" << chocolateBox.Volume()
		<< "\nDone\n\n";

	system("pause");
	return 0;
}