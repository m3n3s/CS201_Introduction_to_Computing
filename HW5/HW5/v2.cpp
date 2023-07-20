#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// SORTING PROBLEMI VAR
// SOYAD BASLANGICINA GORE YAPMIYOR VE ARTAN SEKILDE SIRALIYOR
// SINAVA GIRMEDIYSE DE VECTORE ATIYOR
// DUZELTMELER v3 te.




struct grades{
	string type;
	double grade;
};

struct student{
	string stuName;
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

void sort(vector <student> & v) //non-descending order
{
	int k,loc, numElts = v.size();
    for (k=1; k < numElts; k++) 
	{   
		double hold = v[k].weightedSum;   
		student temp = v[k];	// insert this element
        loc = k;              // location for insertion
	
        // shift elements to make room for temp (i.e. v[k])
		while (0 < loc  && hold < v[loc-1].weightedSum)
        {   
			v[loc] = v[loc-1];
            loc--;
        }
        v[loc] = temp;
    }

}

void rankCheck(int & r)
{
	while (r < 0 || r > 14)
	{
		cout << "Rank needs to be greater than 0 and smaller than 15!" << endl;
		cout << "Enter the rank you want to query (enter 0 to exit): ";
		cin >> r;
	}
}

int main()
{
	string stuLine, gradesLine, gradeFilename, stuFilename;
	vector <student> studentList; 
	ifstream inputGrades, inputStudents;

	cout << "Please enter a filename for Students Grades Results: ";
	cin >> gradeFilename;

	inputGrades.open(gradeFilename.c_str());

	if (inputGrades.fail())
	{
		cout << "Can not find the requested file. Terminating application ..." << endl;
		return 0;
	}

	cout << "Please enter a filename for Students Names : ";
	cin >> stuFilename;

	inputStudents.open(stuFilename.c_str());

	if (inputStudents.fail())
	{
		cout << "Can not find the requested file. Terminating application ..." << endl;
		return 0;
	}

	while (getline(inputStudents, stuLine )) // Read student information
	{
		istringstream streamStu(stuLine);
		string fullName, word, id;

		streamStu >> id;
		while(streamStu >> word)
		{
			fullName += word + " ";
		}
		fullName = fullName.substr(0, fullName.length()-1);

	    student stu;
		stu.stuName = fullName;
		stu.stuID = id;

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

		/*
		if (!check)
			studentList.pop_back(); //BURDA SIKINTI VAR grades2.txt girince hata veriyor.
		*/

	}

	// Buraya kadar her id icin notlar alýnýyor ve studentList'te depolanýyo

	weightedSum(studentList);

	sort(studentList);
	// azalan þekilde sort edip popback yapýlabilir.

	/*
	for (int i=0; i < studentList.size(); i++)
	{
		cout << studentList[i].stuID << "    " << studentList[i].stuName << "    " << studentList[i].weightedSum << endl;
		
	}
	*/
	
	int rank;

	do
	{
	cout << "Enter the rank you want to query (enter 0 to exit): ";
	cin >> rank;

	rankCheck(rank);

	if (rank == 0)
	{
		cout << "Exiting..." << endl;
		return 0;
	}
		
	cout << rank << ", " << studentList[studentList.size()-rank].stuID 
			<< ", " << studentList[studentList.size()-rank].stuName << ", " 
			<< studentList[studentList.size()-rank].weightedSum << endl;
	
	}while (rank != 0);

	return 0;
}