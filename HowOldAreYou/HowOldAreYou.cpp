#include <iostream>

#include <stdlib.h>

#include <ctime>


using namespace std;


int main() 

{ 


string day = "";

string month = "";

string year = "";



cout << "What year were you born? (yyyy) " << endl;

getline(cin, year);

int c = atoi(year.c_str() );

cout << "What month were you born? (mm) " << endl;

getline(cin, month);

int b = atoi(month.c_str() );

cout << "What day were you born? (dd) " << endl;

getline(cin, day);

int a = atoi(day.c_str() );

int secc = c * 31536000;

int secb = b * 2678400;

int seca = a * 86400; 

int totalsec = seca + secb + secc;


   // current date/time based on current system

   
   time_t now = time(0);


cout << "Number of seconds since January 1,1970: " << now << endl;
  
int yourage = (now + (1970 * 31536000)) - totalsec;

cout << "You have lived " << yourage << " seconds" << endl; 



// This is where it gets complic

int yearsyoulived = yourage / 31536000;

int monthsyoulived = (yourage % 31536000) / 2678400;
 
int daysyoulived = (yourage % ((monthsyoulived * 2678400) + yearsyoulived * 31536000)) / 86400;

cout << "You have lived " << yearsyoulived << " years" << endl; 

cout << "You have lived " << monthsyoulived + 1 << " months" << endl; 

cout << "You have lived " << daysyoulived << " days" << endl; 

return 0;

}
