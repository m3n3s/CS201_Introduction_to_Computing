#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Mehmet Enes Battal - HW4

bool routecheck(string name, ifstream & input) // Checks if the file can be opened. If yes, it opens and passes it by reference to main.
{
	input.open(name.c_str());

	while(input.fail())
	{
		cout << "cannot open routes database file"<< endl;
		cout << "Please enter a filename for route database: ";
		cin >> name;
		input.open(name.c_str());
	}
	return true;
}

bool timecheck(string name, ifstream & input) // Checks if the file can be opened. If yes, it opens and passes it by reference to main.
{
	input.open(name.c_str());

	while(input.fail())
	{
		cout << "cannot open times database file"<< endl;
		cout << "Please enter a filename for time database: ";
		cin >> name;
		input.open(name.c_str());
	}
	return true;
}


bool deptimecheck(string time) // Checks if the entered time is valid or not.
{
	string hh , mm;
	bool flag = true;
	for (int i = 0 ; i < time.length() ; i++)
	{
		if (time.at(i) != ':' && time.at(i) <= '9' && time.at(i) >= '0' && flag)
			hh += time.at(i); 
		else if(time.at(i) == ':')
			flag = false;
		else if (!flag)
			mm += time.at(i);
	}

	if (hh < "00" || hh > "24"|| hh.length() != 2)
	{
		cout << "Time is not in correct format" << endl;
		return false;
	}

	else if (mm < "00" || mm > "59" || mm.length() != 2)
	{
		cout << "Time is not in correct format" << endl;
		return false;
	}

	else
		return true;
}



int main()
{
	string routefile, timesfile, dep, time, routeline, timeline, ID, depLoc, endLoc, idTimes, timeTimes;
	ifstream routeinput, timeinput;

	cout << "Please enter a filename for route database: ";
	cin >> routefile; // Gets the name of the routes file.

	routecheck(routefile, routeinput);

	cout << "Please enter a filename for time database: ";
	cin >> timesfile; // Gets the name of the times file.

	timecheck(timesfile, timeinput);

	cout << "Please enter departure location: ";
	cin >> dep; // Gets the wanted departure location.

	while (dep != "EXIT")
	{
		do
		{
			cout << "Please enter start time of travel: ";
			cin >> time; // Gets the departure time.
		} while(!deptimecheck(time)); 

		cout << "The search results are: " << endl;

		routeinput.clear();
		routeinput.seekg(0);

		while(getline(routeinput, routeline)) // Reads the routeinput line by line.
		{
			istringstream streamroute(routeline);
			while (streamroute >> ID >> depLoc >> endLoc) // Reads the line word by word.
			{ 
				if ( dep == depLoc) // If entered departure location is the same with the departure location in the file it gets the ID and checks the times file for that ID.
				{
					timeinput.clear();
					timeinput.seekg(0);

					while (getline(timeinput, timeline)) // Reads the timeinput line by line. 
					{
						istringstream streamtime(timeline);
						while (streamtime >> idTimes >> timeTimes) // Reads the line word by word.
						{
							if (timeTimes >= time && ID == idTimes) // If there is an ID match and the departure time in the file is not smaller than the entered departure time, it prints the departure location, end location, and departure time.
							{
								cout << depLoc << " " << endLoc<< " "<< timeTimes << endl;
							}
						}						
					}					
				}
			}						
		}		

		cout << "Please enter departure location: ";
		cin >> dep; // Asks for another departure location.
	}

	// Closes the files.
	routeinput.close(); 
	timeinput.close();

	return 0;
}