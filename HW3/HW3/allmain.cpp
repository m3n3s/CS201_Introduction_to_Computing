#include <iostream>
#include <string>

using namespace std;

bool choiceCheck(int c)
{
	if (c > 0 && c < 4)
		return true;
	return false;
}



bool entryCheck(string e)  //"?" için kontrol ETMEDÝK
{
	for (int i = 0; i < e.length(); i++)
	{
		if (!( 'a' <= e.at(i) && e.at(i) <= 'z'))
			return false;
	}
	return true;
}

//menu



int main()
{
	cout << "This program searches a search string in a source string with the option of wild cards.\n\n\
Example inputs with their meaning in parantheses:\n\
1 thislectureisawesome (to enter a new source string)\n\
2 lecture (to enter a new source string)\n\
2 t?r? (to enter a source string with wildcards)\n\
3 (to exit the program)\n\n";

	int choice;
	string entry;
	bool flag = false;

	
	while (choice


	while (!flag) // choice entry loop
	{ 
		cout << "Enter your choice and string: ";
		cin >> choice >> entry;
		if (!choiceCheck(choice))
			cout << "Choice can be 1, 2 or 3! Try again." << endl;
	
		else
			flag = true;
	}

	cout << "out of loop";


	cin.ignore();
	cin.get();
	return 0;
}