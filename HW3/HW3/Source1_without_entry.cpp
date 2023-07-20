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
	else{
		cout << "Choice can be 1, 2 or 3! Try again." << endl << endl;
		return false;
	}
}


bool inputCheck(string choice, string entry, int lenSource, bool & questionMark)
{
	if (choice == "1"){
		if (entry == ""){
			cout << "Wrong input format! Try again." << endl;
			return false;
		}

		for (int i=0; i < entry.length(); i++){
			if (entry.at(i) > 'z' || entry.at(i) < 'a'){
				cout << "Wrong input format! Try again." << endl;
				return false;
			}
		}
		return true;
	}

	else if (choice == "2"){
		if (entry == ""){
			cout << "Wrong input format! Try again." << endl;
			return false;
		}

		else if (entry.length() > lenSource){
			cout << "Wrong input format! Try again." << endl;
			return false;
		}

		int count = 0;
		for (int i=0; i < entry.length(); i++){
			if ( entry.at(i) == '?'){
				questionMark = true;
				count++;
			}
			
			else if (entry.at(i) > 'z' || entry.at(i) < 'a'){
				cout << "Wrong input format! Try again." << endl;
				
				return false;
			}
			
		}
		
		if (count == entry.length()){
			cout << "Wrong input format! Try again." << endl;
			return false;
		}

		return true;
	}

	
	return false;
}

/*
void wrongInput(string choice, string entry){

	if (!choiceCheck(choice) || inputCheck(choice, entry, 1) == false) {

		if (!choiceCheck(choice))
			cout << "Choice can be 1, 2 or 3! Try again." << endl << endl;

		else if (inputCheck(choice, entry, 1) == false)
			cout << "Wrong input format! Try again." << endl;
			
			//cout << endl << "Enter your choice and string: "; 
			//cin >> choice >> entry;
	}

}
*/

void findIndex(string source, string search)
{
	cout << "I am at the find index function!!!!" << endl;
	int index;
	string word;
	bool nomatch = true;
	
	index = source.find(search);

	for (int i = 0; i < source.length(); i++){
		if (index != string::npos ){
			nomatch = false;
			word = source.substr(index, search.length());
			
			cout << "\"" << word << "\" has been found at index " << index << endl;
			
			index = source.find(search, index + 1);
		}
		
	}
	if (index == string::npos && nomatch)
		cout << "no match has been found." << endl;
	
}



void wildcardIndex(string source, string search)
{
	string match = "";

	for (int i=0; i < search.length(); i++){


		for (int j = 0; j < source.length(); j++){




		}



	}


}









int main()
{
	string choice;
	string entry, source, search;
	bool flag1 = false, questionMark = false;
	int lenSource;
	
	menu();

	cout << "Enter your choice and string: "; 
	cin >> choice; 
	
	while ( choice != "3") 
	{
				
		if (choice == "1" ){
			cin >> source;

			if (inputCheck(choice, source, 1, questionMark)){
				flag1 = true;
				lenSource = source.length();
				cout << "Source word has been changed to \"" << source << "\"" <<  endl;
			}
			

		}

		else if ( choice == "2" && flag1){
			cin >> search;

			if (inputCheck(choice, search, lenSource, questionMark)){
				cout << "For the source word " << source << "\" and search word \"" << search << "\"," << endl;
				findIndex(source, search);

			}
			
			// ? kýsmý için search i pass by reference yapmak gerekebilir!!
		}

		else
			cout << "Choice can be 1, 2 or 3! Try again." << endl;
		

		cout << endl <<  "Enter your choice and string: "; 
		cin >> choice; 
			
	}
	
	cout << "See you!" << endl;



	system("pause");
	return 0;
}