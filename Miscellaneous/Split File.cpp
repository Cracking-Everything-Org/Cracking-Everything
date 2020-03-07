#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 1000000000
#define MIN -1000000000

using namespace std;

int main() {
	string line;
	fstream myfile("../../file.txt");
	vector<int> numbers;
	int currentLine = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << "Line " << currentLine << endl;
			string current;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ' ') {
					numbers.push_back(atoi(current.c_str()));
					cout << atoi(current.c_str()) << endl;
					current = "";
				}
				else if (line.length() == (i + 1)){
					current += line[i];
					numbers.push_back(atoi(current.c_str()));
					cout << atoi(current.c_str()) << endl;
					current = "";
				}
				else {
					current += line[i];
				}
			}
			currentLine++;
		}
		myfile.close();
	}
	system("pause");
	return 0;
}

