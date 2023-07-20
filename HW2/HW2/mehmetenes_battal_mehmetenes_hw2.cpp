#include <iostream>
#include <string>

using namespace std;

// Mehmet Enes Battal - Homework 2

void welcomeFunc(string name) //Display welcome message with name
{
	cout << "Dear "<< name <<", would you kindly answer our questions, so we can determine the coffee you want." << endl;

}

bool ingredientCheck(string ingr) //Check if the customer wants that ingredient
{
	string response;
	cout << "Does it have " << ingr << "?" << endl;
	cin >> response;
	if (response == "yes"){
		return true;
	}

	else 
		return false;
}

bool ingredientAmount(string ingr1, string ingr2) //Check the amounts of given ingredients
{
	string response;

	cout << "Do "<< ingr1 << " and " << ingr2 <<" are in equal amounts?" << endl;
	cin >> response;
	if (response == "yes"){
		return true;
	}
	else
		return false;

}

void order(string name, string type) // Display customer's order
{
	cout << "Your order is ready " << name << "! What you want is " << type << ". Enjoy!" << endl;
}



int main()
{
	string name, espresso, milk, water, hotchoco, foam;	
	
	cout << "Welcome to Pequod's Coffee! Can you tell me your name?" << endl; // Get customer's name
	cin >> name;

	welcomeFunc(name); 

	if (ingredientCheck("espresso")){ // Check for espresso
		
		if (ingredientCheck("milk")){ // Check for milk

			if (ingredientCheck("hot chocolate")){ // Check for hot chocolate

				order(name, "a mocha"); // Display order
			}
			
			else if (ingredientCheck("foam")){ // Check for foam

				if (ingredientAmount("foam", "milk")){ // Check the amounts

				order(name, "a cappucino"); // Display order
				}
				
				else {
					order(name, "a latte"); // Display order
				}
			}		

			else {
				order(name, "a cafe au lait"); // Display order
			}			
		}

		else if (ingredientCheck("water")){ // Check for water

				order(name, "an americano"); // Display order
		}		

		else {
			order(name, "an espresso"); // Display order
		}				
	}

	else {
		order(name, "a filtered coffee"); // Display order
	}
		
	return 0;
}