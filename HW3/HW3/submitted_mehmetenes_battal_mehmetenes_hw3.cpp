#include <iostream>
#include <string>

using namespace std;


void menu()
{

	cout << "This program searches a search string in a source string with the option of wildcards.\n\n\
Example inputs with their meaning in parantheses:\n\
1 thislectureisawesome (to enter a new source string)\n\
2 lecture (to enter a new source string)\n\
2 t?r? (to enter a source string with wildcards)  \n\
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


bool inputCheck(string choice, string entry, int lenSource)
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


void wildcardIndex(string source, string search)
{
    int j = 0, i = 0, z = 0;
    string match = "", search2 = search;
	bool nomatch = true;

	
   
    for(; search.at(z) == '?'; z++)
    {
        search2 = search.substr(z + 1, search.length());
    }




	for( ; j <= source.length()-search2.length(); j++)
	{
		
		while(i < search2.length() && (source.at(z+i+j) == search2.at(i) || search2.at(i) == '?'))
		{
			match = match + source.at(z+j+i);
			i++;
		}
	}

	if(match.length() == search2.length() && source.find(match) != string::npos)
	{		
		nomatch = false;
			
		cout << endl << "\"" << source.substr((source.find(match) - z), search.length()) << "\" has been found at index " << source.find(match) - z  << endl;
            
	}
	else if(nomatch)
	{
		cout << " no match has been found." << endl;
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

			if (inputCheck(choice, source, 1)){
				flag1 = true;
				lenSource = source.length();
				cout << "Source word has been changed to \"" << source << "\"" <<  endl;
			}
			

		}

		else if ( choice == "2" && flag1){
			cin >> search;

			if (inputCheck(choice, search, lenSource)){
				cout << "For the source word \"" << source << "\" and search word \"" << search << "\"," ;
				wildcardIndex(source, search);

			}
			
			
		}

		else if (choice == "2" && flag1 == false){
			cout << "Wrong input format! Try again." << endl;
			cin >> entry;
		}
		
		else
			cout << "Choice can be 1, 2 or 3! Try again." << endl;

		cout << endl <<  "Enter your choice and string: "; 
		cin >> choice; 
			
	}
	
	cout << "See you!" << endl;




	return 0;
}