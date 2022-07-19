#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;

class MyEvent{
public:
	int EventDay, EventMonth;
	string EventName, EventDescription;
};

void HelloWorld();

//-------------Calc number of days past from month--------------------
int NumDaysPast(int MonthSelected);
//calcuates the number of days from start of year to begining of month (Ex: Month 2, NumDays = 31) and returns that value

//-----------------------Correct Selection function---------------------------
bool CorrectSelection (string input, int NumCorrectAnswers, string* RightAnswers);
//it compares the input to all of the correct answer array "RightAnswers". It will return a true or false statement


int CorrectSelectionIndex(string UserInput, int NumCorrectAnswers, string* ptrRightAnswers);


//------------------------String fixing function------------------------------
string StringFixer(string FixMe);
//it feeds a string through and erases all spaces and capitalizes the first character.



//----------------------Get User Input-------------------------------
string GetUserInput(int NumCorrectAnswers, string* RightAnswers);
//Uses cin and getline then filters answers through the stringfixer function then returns said parsed answer


//------------------------wrong answer responses----------------------
void InvalidAnswer(int SarcasmMeter);
//outputs statements telling the user they entered an invalid response. It progressively gets more sarcastic



//-------------Returns selected month as an integer------------------
int Month_Selection(int NumCorrectAnswers, string* ptrMonthAnswers);


bool UserConfirmCheck();



int NumDaysInMonth(int MonthSelected);


bool IsMonthAvailable(int NumDays, int MonthSelected, MyEvent Event2022[]);


bool IsMonthEmpty(int NumDays, int MonthSelected, MyEvent Event2022[]);


void CreateNewEvent(int MonthAnswerSize, string *ptrMonthAnswers, MyEvent Event2022[]);

void PrintMonthEvents(int MonthSelected, MyEvent Event2022[]);

bool DeleteEvent(int MonthAnswersSize, string* ptrMonthAnswers, MyEvent Event2022[]);

void TestFunc();

void PrintMonthOptions();

string MonthName(int MonthSelected);

