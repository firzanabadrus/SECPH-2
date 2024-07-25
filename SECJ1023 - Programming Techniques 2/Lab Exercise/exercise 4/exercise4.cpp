//? EXERCISE 4: ASSOCIATION

// Programming Technique II

// Member 1's Name: NUR FIRZANA BINTI BADRUS HISHAM A23CS0156
// Member 2's Name: LUBNA AL HAANI BINTI RADZUAN    A23CS0107
// Log the time(s) your pair programming sessions

//  Date         Time (From)   To             Duration (in minutes)
//  7/6/2024     22:49         23:09          20 minutes

// Video link:
// https://drive.google.com/file/d/17J-K2m7tL7I82gqXezIEaizqJ5ju-i0U/view?usp=sharing


#include <iostream>
#include <cmath>
using namespace std;

#define MAX_TERM_COUNT 10

class Term
{
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0);
    void set(int c, int e);
    int evaluate(int x) const;
    int exponent() const;
    int coefficient() const;
};

class Polynomial
{
private:
    Term terms[MAX_TERM_COUNT];
    int count;
public:
    Polynomial();
    void input();
    int evaluate(int x) const;
    Term largestTerm() const;
    int degree() const;
};

//----------------------------------------------------------------------------
int main()
{
    Polynomial poly;
    poly.input();
    
    cout << endl;

    cout << " x  \t\tPolynomial value" << endl;
    cout << "----\t\t----------------" << endl;

    for (int x = 0; x <= 5; x++){
        cout << x << "  \t\t" << poly.evaluate(x) << endl;
    }
    cout << endl;

    system("pause");
    return 0;
}

//----------------------------------------------------------------------------
// class Term

// The constructor is given

Term::Term(int c, int e) : coef(c), exp(e) {}

// Implement the other methods
void Term::set(int c, int e) {
    coef = c;
    exp = e;
}
int Term::exponent() const {
    return exp;
}
int Term::coefficient() const {
    return coef;
}
int Term::evaluate(int x) const {
    int result = 1;
    for(int i = 0; i<exp; i++)
    {
        result = pow(x,exp);
    }
    return result*coef;
}
//----------------------------------------------------------------------------

// class Polynomial

// Implement the constructor and the other methods of the class Polynomial
Polynomial::Polynomial(){
    count = 0;
}

void Polynomial :: input(){
    cout << "Enter a polynomial : " << endl;
    cout << "\tHow many terms? => ";
    cin >> count;


    for(int i=0 ; i < count ; i++){
        int c, e;
       cout << "\tEnter term #" << (i+1) << " (coef and exp) => " ;
       cin >> c >> e;
       terms[i].set(c,e);
    }
}

int Polynomial :: evaluate(int x) const {
    int sum = 0, result = 0;

    for (int i=0 ; i < count ; i++){
        result = terms[i].evaluate(x);
        sum = sum + result;
    }
    
    return sum;
}