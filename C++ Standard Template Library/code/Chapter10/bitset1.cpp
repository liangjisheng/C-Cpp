
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// enumeration type for the bits, each bit represents a color
	enum Color { red, yellow, green, blue, white, black, numColors };

	bitset<numColors> usedColors;

	usedColors.set(red);
	usedColors.set(blue);

	// print some bitset data
	cout << "bitfield of used colors: " << usedColors << endl;
	cout << "number of used colors: " << usedColors.count() << endl;
	cout << "bitfield of unused color: " << ~usedColors << endl;

	// if any color is used
	if (usedColors.any())
	{
		// loop over all colors
		for (int c = 0; c < numColors; ++c)
		{
			// if the actual color is used
			if (usedColors[(Color)c])
				cout << c << endl;
		}
	}

	system("pause");
	return 0;
}