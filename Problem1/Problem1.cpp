#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream file;
	string line;

	file.open("C:\\Windows\\setupact.log");
	if (file.is_open())
	{
		size_t lineCount = 1;

		vector<string> last10Lines;

		while (!file.eof())
		{
			getline(file, line);
			
			if (last10Lines.size() > 10)
			{
				last10Lines.erase(last10Lines.begin());
			}

			last10Lines.push_back(to_string(lineCount) + ". " + line);
		
			lineCount++;
		}
		cout << "Line count: " << lineCount << endl;
	
		for (size_t i = 0; i < last10Lines.size(); i++)
		{
			cout << last10Lines[i] << endl;
		}

		file.close();
	}
	else {
		cout << "Error opening file!";
	}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
