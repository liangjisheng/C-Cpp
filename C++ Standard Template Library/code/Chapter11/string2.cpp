
// �ӱ�׼�����豸��ȡ���ʣ�Ȼ�����и����ַ�(��ĸ)�������.���ʺ͵���֮����һ��ո�
// (����newline���ո��space���Ʊ��Tab)�򶺺š���š��ֺŷָ��

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	const string delims(" \t,.;");
	string line;

	// for every line read successfully
	while (getline(cin, line))
	{
		string::size_type begIdx, endIdx;
		// search beginning of the first word
		begIdx = line.find_first_not_of(delims);

		// while beginning of a word found
		while (begIdx != string::npos)
		{
			// search end of the actual word
			endIdx = line.find_first_of(delims, begIdx);
			if (endIdx == string::npos)
				endIdx = line.length();		// end of word is end of line

			// print characters in reverse order
			for (int i = endIdx - 1; i >= static_cast<int>(begIdx); --i)
				cout << line[i];
			cout << ' ';

			begIdx = line.find_first_not_of(delims, endIdx);
		}
		cout << endl;
	}

	system("pause");
	return 0;
}