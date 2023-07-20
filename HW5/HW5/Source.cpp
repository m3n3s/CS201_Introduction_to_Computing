#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct grades{
	string type;
	int grade;
};

struct student{
	string stuName;
	string stuID;
	vector <grades> stuGrades;
};

void openFile(ifstream & stuFile, ifstream & gradeFile)
{

}


int main()
{
	string fullName, fName, mName, lName = "", id, stuLine, gradesLine, gradeFilename, stuFilename;
	vector <student> studentList(0);
	ifstream inputGrades, inputStudents;

	cout << "Please enter a filename for Students Grades Results: ";
	cin >> gradeFilename;

	inputGrades.open(gradeFilename.c_str());

	if (inputGrades.fail())
	{
		cout << "Can not find the requested file. Terminating application ...";
		return 0;
	}

	cout << "Please enter a filename for Students Names : ";
	cin >> stuFilename;

	inputStudents.open(stuFilename.c_str());

	if (inputStudents.fail())
	{
		cout << "Can not find the requested file. Terminating application ...";
		return 0;
	}

	while (getline(inputStudents, stuLine ))
	{
		istringstream streamStu(stuLine);

		streamStu >> id >> fName >> mName >> lName;
		fullName = fName + " " + mName + " " + lName;

	    student stu;
		stu.stuName = fullName;
		stu.stuID = id;

		studentList.push_back(stu);
	}

	string gradesID,gradeType;
	int grade;

	while (getline(inputGrades, gradesLine))
	{
		istringstream streamGrade(gradesLine);
		grades gr;

		if (gradesLine == "***HOMEWORK***" )
			gradeType = "HW";
		else if (gradesLine == "***MIDTERM***")
			gradeType = "MID";
		else if (gradesLine == "***FINAL***")
			gradeType = "FIN";
		else
		{
			streamGrade >> gradesID >> grade;
			gr.type = gradeType;
			gr.grade = grade;
		}
		
		for (int i = 0 ; i < studentList.size(); i++)
		{
			if (studentList[i].stuID == gradesID)
				studentList[i].stuGrades.push_back(gr);
		}
	}

	// Buraya kadar her id icin notlar alýnýyor ve studentList'te depolanýyo




	for (int i=0; i < studentList.size(); i++)
	{
		cout << studentList[i].stuID << "    " << studentList[i].stuName << endl;
		for (int j = 0;j < studentList[i].stuGrades.size() ; j++)
		{
			cout << studentList[i].stuGrades[j].type << "    " << studentList[i].stuGrades[j].grade << endl;
		}
	}


	system("pause");
	return 0;
}


