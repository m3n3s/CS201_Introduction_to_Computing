#include <iostream>
#include <string>

using namespace std;


void menu()
{

	cout << "This program searches a search string in a source string with the option of wild cards.\n\n\
Example inputs with their meaning in parantheses:\n\
1 thislectureisawesome (to enter a new source string)\n\
2 lecture (to enter a new source string)\n\
2 t?r? (to enter a source string with wildcards)\n\
3 (to exit the program)" << endl << endl;

}


bool choiceCheck(string choice) {
	if (choice == "1" || "2"  || "3")
		return true;

	return false;
}


bool inputCheck(string choice, string entry)
{
	if (choice == "1"){
		for (int i=0; i < entry.length(); i++){
			if (entry.at(i) > 'z' || entry.at(i) < 'a')
				return false;
		}
		return true;
	}

	else if (choice == "2"){
		for (int i=0; i < entry.length(); i++){
			if (entry.at(i) > 'z' || entry.at(i) < 'a')
				return false;
			// ? ÝÇÝN CHECKKK!!! neredeeeee
		}
		return true;
	}

	else if (choice == "3"){
		cout << " get out";
	}
	return false;
}

void findIndex(string source, string search)
{
	cout << "I am at the find index function!!!!" << endl;
	int index;
	string word;
	
	index = source.find(search);

	for (int i = 0; i < source.length(); i++){
		if (index != string::npos ){
			word = source.substr(index, search.length());
			
			cout << "\"" << word << "\" has been found at index " << index << endl;
			
			index = source.find(search, index + 1);
		}
	}

	cout << endl;
}

int main()
{
	string choice = "1";
	string entry, source, search;
	bool flag1 = false;
	
	menu();

	cout << "Enter your choice and string: "; 
	cin >> choice>> entry; 
	
	while ( choice != "3") 
	{
		
		

		while (!choiceCheck(choice) || inputCheck(choice, entry) == false) 
		{
			if (!choiceCheck(choice))
				cout << "Choice can be 1, 2 or 3! Try again." << endl << endl;

			else if (inputCheck(choice, entry) == false)
				cout << "Wrong input format! Try again." << endl;
			
			cout << endl << "Enter your choice and string: "; 
			cin >> choice >> entry;
		}
		
		if (choice == "1" && inputCheck(choice, entry)){
			source = entry;
			flag1 = true;
			cout << "Source word has been changed to \"" << source << "\"" <<  endl << endl;

		}

		else if ( choice == "2" && inputCheck(choice, entry) && flag1){
			search = entry;
			cout << "For the source word " << source << "\" and search word \"" << search << "\"," << endl;
			findIndex(source, search);
			// ? kýsmý için search i pass by reference yapmak gerekebilir!!
		}

		cout << "Enter your choice and string: "; 
		cin >> choice >> entry; 
			
	}
	
	cout << "See you!" << endl;



	system("pause");
	return 0;
}