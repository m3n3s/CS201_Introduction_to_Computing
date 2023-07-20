#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool routecheck(string name)
{
	ifstream input;

	input.open(name.c_str());

	while(input.fail())
	{
		cout << "cannot open routes database file"<< endl;
		cout << "Please enter a filename for route database: ";
		cin >> name;
		input.open(name.c_str());
	}
	input.close();
	return true;
}

bool timecheck(string name)
{
	ifstream input;

	input.open(name.c_str());

	while(input.fail())
	{
		cout << "cannot open times database file"<< endl;
		cout << "Please enter a filename for time database: ";
		cin >> name;
		input.open(name.c_str());
	}
	input.close();
	return true;
}


bool deptimecheck(string time)
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
		return false;

	else if (mm < "00" || mm > "59" || mm.length() != 2)
		return false;

	else
		return true;
}

void search()
{
	
}



int main()
{
	string routefile, timesfile, dep, time, routeline, timeline, ID, depLoc, endLoc, idTimes, timeTimes;
	bool valid_routes, valid_times;
	ifstream routeinput, timeinput;

	cout << "Please enter a filename for route database: ";
	cin >> routefile;

	valid_routes = routecheck(routefile);

	cout << "Please enter a filename for time database: ";
	cin >> timesfile;

	valid_times = timecheck(timesfile);

	// Buraya kadar file input check

	routeinput.open(routefile.c_str());
	timeinput.open(timesfile.c_str());  

	cout << "Please enter departure location: ";
	cin >> dep;

	while (dep != "EXIT")
	{
		do
		{
			cout << "Please enter start time of travel: ";
			cin >> time;
		}while(!deptimecheck(time)); 

		cout << "The search results are: " << endl;

		while(getline(routeinput, routeline))
		{
			istringstream streamroute(routeline);
			while (streamroute >> ID >> depLoc >> endLoc)
			{ 
				// ikinci dosyayla karþýlaþtýr

				if ( dep == depLoc)
				{
					while (getline(timeinput, timeline))
					{
						istringstream streamtime(timeline);
						while (streamtime >> idTimes >> timeTimes)
						{
							if (timeTimes >= time && ID == idTimes)
							{
								cout << depLoc << "    " << endLoc<< "    "<< timeTimes << endl;

							}
						}
						
					}
					timeinput.clear();
					timeinput.seekg(0);
				}

			}

			
		}
		routeinput.clear();
		routeinput.seekg(0);

		cout << "Please enter departure location: ";
		cin >> dep;
	}

	routeinput.close();
	timeinput.close();

	// FORMATI DÜZELTT!!!!!!!!!!!1


	return 0;
}
