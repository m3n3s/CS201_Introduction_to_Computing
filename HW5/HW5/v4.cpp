#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// ayný notu aldýlarsa soyadýna göre sort olmasý lazým !!!

// SORUN COZULDU. BITMIS HALI son CPP DE.

struct grades{
	string type;
	double grade;
};

struct student{
	string stuName;
	string stuLastname;
	string stuID;
	vector <grades> stuGrades;
	double weightedSum;
	
};

void weightedSum(vector<student> & list)
{
	for (int i = 0; i < list.size(); i++)
	{
		double sum = 0;
		double count = 0;

		for (int j = 0 ; j < list[i].stuGrades.size(); j++)
		{
			if (list[i].stuGrades[j].type == "HW")
				sum +=  list[i].stuGrades[j].grade * 10 /100;
			else if (list[i].stuGrades[j].type == "MID")
				sum +=  list[i].stuGrades[j].grade * 20 /100;
			else if(list[i].stuGrades[j].type == "FIN")
				sum +=  list[i].stuGrades[j].grade * 30 /100;				
		}

		list[i].weightedSum = sum;
		
	}
}

/*
void sort(vector <student> & v) // sorts in descending order.
{
	int k,loc, numElts = v.size();
    for (k=1; k < numElts; k++) 
	{   
		double hold = v[k].weightedSum;   
		student temp = v[k];	// insert this element
        loc = k;              // location for insertion
	
        // shift elements to make room for temp (i.e. v[k])
		while ((0 < loc  && hold >= v[loc-1].weightedSum)) 
		//	|| (v[k].weightedSum == v[loc -1].weightedSum && v[k].stuLastname < v[loc -1].stuLastname )
        {   
			if (hold == v[loc-1].weightedSum && v[k].stuLastname < v[loc-1].stuLastname)
			{
				
			
			
			}
			else
			{
				v[loc] = v[loc-1];
				loc--;
			}

			
        }
        v[loc] = temp;
    }

	while (v[v.size()-1].stuGrades.size() == 0)
	{
		v.pop_back();
	}
	
}
*/
void Swap (student & s1, student & s2)
{
	student temp;
	temp = s1;
	s1 = s2;
	s2 = temp;
}

void sort(vector<student> & a, int size)
{
    int j,k,min;
    
    for(j=0 ; j< size-1; j++)
    {	
		min = j;
		
        for(k=j+1; k<size; k++)
        {
			if (a[k].weightedSum > a[min].weightedSum) 
            {
                min = k;
			}		
			else if((a[k].weightedSum == a[min].weightedSum)  && (a[k].stuLastname < a[min-1].stuLastname))
			{
				min = k;
			}

        }
		
        Swap(a[min],a[j]);
    }    

}

/*
void sort(vector <student> & v) // sorts in descending order.
{
	int k,loc, numElts = v.size();
    for (k=1; k < numElts; k++) 
	{   
		double hold = v[k].weightedSum;   
		student temp = v[k];	// insert this element
        loc = k;              // location for insertion
	
        // shift elements to make room for temp (i.e. v[k])
		while ((0 < loc  && hold > v[loc-1].weightedSum)) 
        {   
			v[loc] = v[loc-1];
            loc--;
        }
        v[loc] = temp;
    }

	while (v[v.size()-1].stuGrades.size() == 0)
	{
		v.pop_back();
	}
	
}

*/






bool rankCheck(int & r, int s)
{
	while (r < 0 || r > s) // UST LIMITI SOR SAMPLE LARA GORE DEGISIYOR !!!
	{
		cout << "Rank needs to be greater than 0 and smaller than " << s + 1 << "!" << endl;
		cout << "Enter the rank you want to query (enter 0 to exit): ";
		cin >> r;
	}
	return true;
}

int main()
{
	string stuLine, gradesLine, gradeFilename, stuFilename;
	vector <student> studentList(0); 
	ifstream inputGrades, inputStudents;

	cout << "Please enter a filename for Students Grades Results: ";
	cin >> gradeFilename;

	inputGrades.open(gradeFilename.c_str());

	if (inputGrades.fail())
	{
		cout << "Can not find the requested file. Terminating application ..." << endl;
		system("pause");
		return 0;
	}

	cout << "Please enter a filename for Students Names : ";
	cin >> stuFilename;

	inputStudents.open(stuFilename.c_str());

	if (inputStudents.fail())
	{
		cout << "Can not find the requested file. Terminating application ..." << endl;
		system("pause");
		return 0;
	}




	while (getline(inputStudents, stuLine )) // Read student information
	{
		istringstream streamStu(stuLine);
		string fullName, lastname, word, id;

		streamStu >> id;
		while(streamStu >> word)
		{
			fullName += word + " ";
		}
		fullName = fullName.substr(0, fullName.length()-1);
		lastname = fullName.substr(fullName.rfind(" ")+1, fullName.length());//

	    student stu;
		stu.stuName = fullName;
		stu.stuID = id;
		stu.stuLastname = lastname; //

		studentList.push_back(stu);
	}




	string gradesID,gradeType;
	double grade;

	while (getline(inputGrades, gradesLine)) // Read grades according to student's information
	{
		istringstream streamGrade(gradesLine);

		if (gradesLine == "***HOMEWORK***" )
			gradeType = "HW";
		else if (gradesLine == "***MIDTERM***")
			gradeType = "MID";
		else if (gradesLine == "***FINAL***")
			gradeType = "FIN";
		else if (gradesLine != "")
		{
			grades gr;

			streamGrade >> gradesID >> grade;
			gr.type = gradeType;
			gr.grade = grade;		
		
			bool check = false;

			for (int i = 0 ; i < studentList.size() && !check; i++)
			{
				if (studentList[i].stuID == gradesID) 
				{
					studentList[i].stuGrades.push_back(gr);
					check = true;

				}

			}
			
		}

	}

	// Buraya kadar her id icin notlar alýnýyor ve studentList'te depolanýyo

	weightedSum(studentList);

	//

	for (int i=0; i < studentList.size(); i++)
	{
		cout << studentList[i].stuID << "    " << studentList[i].stuName << "    " << 
			studentList[i].weightedSum << "    " << studentList[i].stuLastname << endl;
		
	}

	cout << endl << endl << endl << endl;

	//


	sort(studentList,studentList.size()); // sýkýntý var

	//
	
	for (int i=0; i < studentList.size(); i++)
	{
		cout << studentList[i].stuID << "    " << studentList[i].stuName << "    " << 
			studentList[i].weightedSum << "    " << studentList[i].stuLastname << endl;
		
	}

	//

	
	int rank, size = studentList.size();

	do
	{
	cout << "Enter the rank you want to query (enter 0 to exit): ";
	cin >> rank;

	rankCheck(rank, size);

	if (rank == 0)
	{
		cout << "Exiting..." << endl;
		system("pause");
		return 0;
	}
		
	cout << rank << ", " << studentList[rank-1].stuID 
			<< ", " << studentList[rank-1].stuName << ", " 
			<< studentList[rank-1].weightedSum << endl;
	
	}while (rank != 0);

	system("pause");
	return 0;
}