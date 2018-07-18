
/***********************************************************
 * @name: mem_fun_1.cpp
 * @brief: mem_fun
 * @author: Jisheng Liang
 * @date: 2018/6/30 15:34:06
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

struct Car {
	int id;
	Car(int id) { this->id = id; }
	void display() const { cout << "car " << id << endl; }
};

int main()
{
	vector<Car*> pcars;
	vector<Car> cars;

	for (int i = 0; i < 5; i++)
		pcars.push_back(new Car(i));
	for (int i = 5; i < 10; i++)
		cars.push_back(Car(i));

	cout << "elements in pcars:" << endl;
	for_each(pcars.begin(), pcars.end(), std::mem_fun(&Car::display));

	cout << "elements in cars: " << endl;
	for_each(cars.begin(), cars.end(), std::mem_fun_ref(&Car::display));

	for (size_t i = 0; i < pcars.size(); i++)
		delete pcars[i], pcars[i] = NULL;

	getchar();
	return 0;
}
