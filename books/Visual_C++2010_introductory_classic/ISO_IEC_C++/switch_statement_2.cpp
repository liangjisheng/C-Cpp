// switch_statement2.cpp
// C2360 expected
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	switch( tolower( *argv[1] ) )
	{
		// Error. Unreachable declaration.
		// char szChEntered[] = "Character entered was: ";

	case 'a' :
		{
			// Declaration of szChEntered OK. Local scope.
			char szChEntered[] = "Character entered was: ";
			cout << szChEntered << "a\n";
		}
		break;

	case 'b' : 
		{
		// Value of szChEntered undefined.
		char szChEntered[] = "Character entered was: ";
		cout << szChEntered << "b\n";
		break;
		}

	default:
		{
			// Value of szChEntered undefined.
			char szChEntered[] = "Character entered was: ";
			cout << szChEntered << "neither a nor b\n";
			break;
		}
	}

	system("pause");
	return 0;
}