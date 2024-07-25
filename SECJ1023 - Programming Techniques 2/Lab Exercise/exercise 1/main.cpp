// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II

// Member 1's Name: Nur Firzana Binti Badrus Hisham
// Member 2's Name: Lubna Al Haani Binti Radzuan
//
// Section: 03
// Member 1's Name: Nur Firzana Binti Badrus Hisham    Location: Home (i.e. where are you currently located)
// Member 2's Name: Lubna Al Haani Binti Radzuan       Location: Home

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  14/4/2024    5.33 PM       5.54 PM        21 Minutes
//  14/4/2024    7.50 PM       8.20 PM        30 Minutes
//  14/4/2024    8.30 PM       9.02 PM		  32 Minutes
//  14/4/2024    10.07 PM      10.22 PM		  15 Minutes

// Video link:
//  https://drive.google.com/drive/folders/1jEuCqfAKYSgpoLVu2BCFDK1scKp7vNqE?usp=sharing


#include <iostream>
#include <string>

// Student Class Declaration 
using namespace std;

class Student
{
	private : 
		string subjectName;
		string subjectCode;
		int score;
		int creditHour;
		string grade;
		double gradePoint;

	public :
		inline Student(string subjName) 
		{ subjectName = subjName;}
		Student(){}
		~Student(){}
		
		inline void setSubjectCode(string subjCode)
			{subjectCode = subjCode; }
		inline void setScore(int sco)
			{score = sco; } 
		inline void setCreditHour(string subjCode)
			{creditHour = subjCode[7]; creditHour = creditHour - 48;} 
		inline void setGradeAndPoint(int sco)
			{
				if (sco >= 90 && sco <= 100) 
					{ grade = "A+" ; gradePoint = 4.00; }
				else if (sco >=80)
					{ grade = "A" ; gradePoint = 4.00; }
				else if (sco >=75)
					{ grade = "A-" ; gradePoint = 3.67; }
				else if (sco >=70)
					{ grade = "B+" ; gradePoint = 3.33; }
				else if (sco >=65)
					{ grade = "B" ; gradePoint = 3.00; }
				else if (sco >=60)
					{ grade = "B-" ; gradePoint = 2.67; }
				else if (sco >=55)
					{ grade = "C+" ; gradePoint = 2.33; }
				else if (sco >=50)
					{ grade = "C" ; gradePoint = 2.00; }
				else if (sco >=45)
					{ grade = "C-" ; gradePoint = 1.67; }
				else if (sco >=40)
					{ grade = "D+" ; gradePoint = 1.33; }
				else if (sco >=35)
					{ grade = "D" ; gradePoint = 1.00; }
				else if (sco >=30)
					{ grade = "D-" ; gradePoint = 0.67; }
				else 
					{ grade = "E" ; gradePoint = 0.00; }
			}

		inline string getSubjectName() const
			{ return subjectName; }
		inline string getSubjectCode() const
			{ return subjectCode; }
		inline int getScore() const
			{ return score; }
		inline double getCreditHour() const
			{ return creditHour; }
		inline string getGrade() const
			{ return grade; }
		inline double getGradePoint() const
			{ return gradePoint; }
		inline double getPointEarn()
			{ return creditHour * gradePoint;}

};


int main()
{
	Student sub; // Define an instance of the Student class
	string subjName;
	string subjCode;
	int sco;


	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin,subjName);
	cout << endl;

	cout << "  Subject code => ";
	cin >> subjCode;
	cout << endl;

	cout << "  Score earned => ";
	cin >> sco;
	cout << endl;

	Student s(subjName);
	sub.setSubjectCode(subjCode);
	sub.setScore(sco);
	sub.setCreditHour(subjCode);
	sub.setGradeAndPoint(sco);

	cout << endl
		 << endl;

	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : " << sub.getSubjectCode() << endl;
	cout << "Subject Name : " << s.getSubjectName() << endl;
	cout << "Credit Hour  : " << sub.getCreditHour() << endl;
	cout << "Score Earned : " << sub.getScore() << endl;
	cout << "Grade Earned : " << sub.getGrade() << endl;
	cout << "Grade Point  : " << sub.getGradePoint() << endl;
	cout << "Point Earned : " << sub.getPointEarn() << endl;
	cout << endl;

	system("pause");

	return 0;
}
