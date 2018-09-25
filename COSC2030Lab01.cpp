// Alejandro Bermudez 


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<fstream>
#include <sstream>
using std::ifstream;
using namespace std;

void PromptUser(ifstream& filestream)
{
	do
	{
		string filename;
		cout << "Please enter the name of the file: " << endl;
		getline(cin, filename); //get the filename
		filestream.open(filename); //open the file

		if (filestream.fail()) //if file could not be opened, give error message
		{
			cout << "Error opening file" << endl;
		}
	}
	while (!filestream.is_open()); //repeat if file was not opened
	
}

int main()
{
	

	ifstream fileopener;
	PromptUser(fileopener);

	int total = 0;

	double first, second, secondtolast, last = 0; //variables to store doubles

	while (!(fileopener.eof()))
	{
		
		double current = 0;
		if (fileopener >> current)
		{
			if (total == 0) //if total == 0, then it is the first word in the file 
			{
				first = current;
			}

			if (total == 1) //if total == 1, then it is the second word in the file 
			{
				second = current;
			}

				secondtolast = last; //replace the secondtothe last varaible with what was in the last variable
			
				last = current; //always save the current double in the last variable 
		
			total++; //increment count 
		}
		
	}


	cout << "The number of numbers in the file is :\t" << total << endl;
	cout << "\n The First number is: \t\t" << first << endl;
	cout << "\n The Second number is: \t\t" << second << endl;
	cout << "\n The Second to the last number is: \t" << secondtolast << endl;
	cout << "\n The Last number is: \t\t" << last << endl;

	fileopener.close();
	system("pause");
	return 0;
}

