#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
const int SIZE = 100;
using namespace std;
int main() {
	string file="example.txt";
	string line;
	string mystring[SIZE];
	vector<string> found;
	vector<string> result;
	vector<string> se;
	ifstream myfile(file);
	int i = 0;
	if (myfile.is_open())
	{
		cout << "File Given " << endl;
		while (getline(myfile, line))
		{

			mystring[i] = line;
			cout << line << endl;
			i++;
		}
		myfile.close();
		cout << "=======================\n=======================" << endl;
	}
	{
		if (mystring->size() != 0) {
			string s = mystring[0];

			int a = 0;
			int k = s.find("|");
			int p = s.find(">");

			found.push_back(mystring[0].substr(0, p - 1));
			while (k != -1) {
				se.push_back(s.substr(p + 1, k - p - 1));
				s = s.substr(k + 1, s.size() - k);
				k = s.find("|");
				a++;
			}
			se.push_back(s);
			for (int sei = 0;sei < se.size();sei++) {
				int fc = se[sei].find("P");

				if (std::find(found.begin(), found.end(), se[sei].substr(fc, se[sei].size() - fc)) == found.end())
				{
					found.push_back(se[sei].substr(fc, se[sei].size() - fc));
				}

			}
			se.clear();
		}
	}
	for (int j = 1;j < i; j++) {
		string s = mystring[j];
		int a = 0;
		int k = s.find("|");
		int p = s.find(">");
		string mycase = mystring[j].substr(0, p - 1);
		if (std::find(found.begin(), found.end(), mycase) != found.end())
		{
			while (k != -1) {
				se.push_back(s.substr(p + 1, k - p - 1));
				s = s.substr(k + 1, s.size() - k);
				k = s.find("|");
				a++;
			}
			se.push_back(s);
			for (int sei = 0;sei < se.size();sei++) {
				int fc = se[sei].find("P");

				if (std::find(found.begin(), found.end(), se[sei].substr(fc, se[sei].size() - fc)) == found.end())
				{
					found.push_back(se[sei].substr(fc, se[sei].size() - fc));
				}

			}
			se.clear();
		}
	}
	fstream ofs;
	ofs.open(file, ios::out | ios::trunc);
	cout << "File Result" << endl;
		for (int j = 0; j < i; j++) {
			int p = mystring[j].find(">");
			string mycase = mystring[j].substr(0, p - 1);
			if (std::find(found.begin(), found.end(), mycase) != found.end()) {
				ofs << mystring[j] << "\n";
				cout << mystring[j] << endl;
			}
		}
		system("pause");
}