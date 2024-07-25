// ? EXERCISE 2: CLASS AND OBJECT MANIPULATIONS

/// Programming Technique II

// Member 1's Name: LUBNA AL HAANI BINTI RADZUAN	(A23CS0107)
// Member 2's Name: NUR FIRZANA BINTI BADRUS HISHAM (A23CS0156)
//
// Section: 03
// Member 1's Name: HAANI		    Location: UTM, JB (i.e. where are you currently located)
// Member 2's Name: FIRZANA    		Location: UTM, JB

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  25/4/2024    11.39 PM	   12.02 PM		  23 Minutes
//  25/4/2024    12.09 PM      12.41 PM       32 Minutes
//  25/4/2024    12.45 PM      12.51 PM       06 Minutes

// Video link:
//  https://drive.google.com/drive/folders/1EJ8MPEW98OC2Oh43-sCHdXFk5mmZkEG-?usp=sharing 


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SUBJECT_COUNT 11

class Subject
{
private:
	string name;
	string code;
	int score;
	int credits;
	string grades;
	double points;
	double subTotal;
	double pointTotal;
	int creditTotal;

public:
	Subject();
	int credit() const;
	string grade() const;
	double point() const;
	void print(Subject subjects[], int) const;
	void printTotal(Subject subjects[], int);
	bool operator< (const Subject &) const; //overloaded operator
	friend int readUserInput(Subject subjects[]);
};

Subject lower(Subject, Subject);

int main()
{
	Subject sub;
	Subject subjects[MAX_SUBJECT_COUNT];
	int count = readUserInput(subjects);
 
	cout << endl
		 << endl
		 << "THE RESULT"
		 << endl
		 << endl;

	// Print the output table header
	cout << left << setw(15) << "Subject Code";
	cout << left << setw(30) << "Subject Name";
	cout << left << setw(10) << "Credit";
	cout << left << setw(10) << "Score";
	cout << left << setw(10) << "Grade";
	cout << left << setw(10) << "Point";
	cout << left << setw(10) << "Sub Total";
	cout << endl
		 << endl;
	
	
	for(int i = 0; i < count; i++)
	{
		sub.print(subjects, i);
		subjects[10] = lower(subjects[10], subjects[i]);
	} 

	sub.printTotal(subjects, count);

	cout << endl;
	cout << "LOWEST SUBJECT : " << endl;
	sub.print(subjects, 10);
	cout << endl;

	system("pause");

	return 0;
}

// The definition of the default constructor is fully given
Subject::Subject() : name(""), code(""), score(0) {}

// The definition of the getter for the 'credit()' is fully given
int Subject::credit() const { return code[7] - '0'; }

// The definition of the getter for the 'grade()' is fully given
string Subject::grade() const
{
	if (score >= 90)
		return "A+";
	if (score >= 80)
		return "A";
	if (score >= 75)
		return "A-";
	if (score >= 70)
		return "B+";
	if (score >= 65)
		return "B";
	if (score >= 60)
		return "B-";
	if (score >= 55)
		return "C+";
	if (score >= 50)
		return "C";
	if (score >= 45)
		return "C-";
	if (score >= 40)
		return "D+";
	if (score >= 35)
		return "D";
	if (score >= 30)
		return "D-";
	return "E";
}

// Definition of accesseor point()
double Subject::point() const
{
	if (grades == "A+")
		return 4;
	if (grades == "A")
		return 4;
	if (grades == "A-")
		return 3.67;
	if (grades == "B+")
		return 3.33;
	if (grades == "B")
		return 3;
	if (grades == "B-")
		return 2.67;
	if (grades == "C+")
		return 2.33;
	if (grades == "C")
		return 2;
	if (grades == "C-")
		return 1.67;
	if (grades == "D+")
		return 1.33;
	if (grades == "D")
		return 1;
	if (grades == "D-")
		return 0.67;
	return 0;
}

// Definition function to print a list of subjects
void Subject::print(Subject subjects[], int i) const
{
	cout << left << setw(15) << subjects[i].code;
	cout << left << setw(30) << subjects[i].name;
	cout << left << setw(10) << subjects[i].credits;
	cout << left << setw(10) << subjects[i].score;
	cout << left << setw(10) << subjects[i].grades;
	cout << left << setw(10) << subjects[i].points;
	cout << left << setw(10) << subjects[i].subTotal;
	cout << endl;
}

// Definition of setter printTotal
void Subject :: printTotal(Subject subjects[], int count)
{
	pointTotal = 0; 
	creditTotal = 0;
	for ( int i =0 ; i < count ; i++)
	{
		pointTotal += subjects[i].subTotal;
		creditTotal += subjects[i].credits;
	}
	cout << endl;
	cout << "TOTAL POINT  : " << static_cast<int>(pointTotal) << endl;
	cout << "TOTAL CREDIT : " << creditTotal << endl;
	cout << "GPA          : " << setprecision(3) << (pointTotal/creditTotal) << endl;
}

//Definition of overloaded operator
bool Subject :: operator< (const Subject &other) const
{
	return score < other.score;
}

// Define a regular function that read a list of subjects from user input
int readUserInput(Subject subjects[])
{
	int count;
	cout << "How many subjects do you want to enter? => ";
	cin >> count;
	cout << endl; 

	while (count >= MAX_SUBJECT_COUNT)
	{
		cout << "Maximum number of subjects is 10. Try again." << endl;
		cout << "How many subjects do you want to enter? => ";
		cin >> count;
		cout << endl;
	}

	for (int i = 0; i < count ; i++)
	{
		cin.ignore();
		cout << "Enter info for subject #" << (i+1) << ":" << endl;
		cout << "Subject code => " ;
		getline(cin, subjects[i].code);

		cout << "Subject name => " ;
		getline(cin, subjects[i].name);

		cout << "Score Earned => " ;
		cin >> subjects[i].score;
		cout << endl;

		subjects[i].credits = subjects[i].credit(); // Credit setter 
		subjects[i].grades = subjects[i].grade(); // Grade setter
		subjects[i].points = subjects[i].point(); // Point setter
		subjects[i].subTotal = subjects[i].credits * subjects[i].points; // subTotal setter
	}
	subjects[10].score = 101;
	return count;
}


// Define a regular function that determines the lower subject.
Subject lower(Subject a, Subject b)
{
	bool small = a.operator<(b);
	if (small == true)
		return a;
	else
		return b;
}