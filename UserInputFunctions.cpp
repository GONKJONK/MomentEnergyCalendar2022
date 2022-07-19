

#include "CalendarFunctions.h"



//Compares "UserInput" to all of the correct answer array "RightAnswers". It will return a true or false statement
bool CorrectSelection(string UserInput, int NumCorrectAnswers, string* ptrRightAnswers)
{
	UserInput = StringFixer(UserInput);
//	cout << "UserInput: " << UserInput << "\nNumCorrectAnswers: " << NumCorrectAnswers << "\n&RightAnswers: " << RightAnswers << "\n&RightAnswers+1: " << RightAnswers+1 << "\n";
	string* ptrTempAnswer = ptrRightAnswers;
//	cout << "2nd element of RightAnswers: " << *ptrTempAnswer;
	for (int i = 0; i < NumCorrectAnswers; i++) {
		ptrTempAnswer = ptrRightAnswers+i;
		if (UserInput == *ptrTempAnswer){
//			cout << "Debug: CorrectSelection match: UserInput: " << UserInput << " Correct Answer: " << *ptrTempAnswer << "		'i'th position: " << i << "\n";
 			return true;
		} else {
//			cout << "Debug: CorrectSelection no match: UserInput: " << UserInput << " Correct Answer: " << *ptrTempAnswer << "		'i'th position: " << i << "\n";
		}

	}
	return false;

}



//Compares "UserInput" to all of the correct answer array "RightAnswers". Returns index of the "RightAnswers". Returns sizeof(RightAnswers)+1 if it couldnt find a match
int CorrectSelectionIndex(string UserInput, int NumCorrectAnswers, string* ptrRightAnswers)
{
	UserInput = StringFixer(UserInput);
//	cout << "UserInput: " << UserInput << "\nNumCorrectAnswers: " << NumCorrectAnswers << "\n&RightAnswers: " << RightAnswers << "\n&RightAnswers+1: " << RightAnswers+1 << "\n";
	string* ptrTempAnswer = ptrRightAnswers;
//	cout << "2nd element of RightAnswers: " << *ptrTempAnswer;
	for (int i = 0; i < NumCorrectAnswers; i++) {
		ptrTempAnswer = ptrRightAnswers+i;
		if (UserInput == *ptrTempAnswer){
//			cout << "UserInput: " << UserInput << " Correct Answer: " << *ptrTempAnswer << " 'i'th position: " << i << "\n";
 			return i;
		} else {
//			cout << "did not match: " << i << "\n";
		}

	}
	cout << "Debug: CorrectSelectionIndex failed. Could not find matching inputs\n";
	return NumCorrectAnswers+1;

}



//it feeds a string through and erases all spaces and capitalizes the first character, then returns said string.
string StringFixer(string FixMe){
//	cout << "StringFixer input: "<<FixMe << "\n"; //debugging statement: testing the filters
	FixMe[0] = toupper(FixMe[0]);
	FixMe.erase(remove(FixMe.begin(), FixMe.end(), ' '), FixMe.end());
//	cout << "StringFixer output: "<<FixMe << "\n"; //debugging statement: testing the filters
	return FixMe;
}



//takes in UserInput, feeds through "StringFixer" then compares UserInput to answers using "CorrectSelection"
//Only returns UserInput if "CorrectSelection" returns a true statement
string GetUserInput(int NumCorrectAnswers, string* ptrRightAnswers)
{
	//Function loops and compares the user inputs answers with required answers. There is no exit button
	bool ExitPass = false;
	string UserInput;
	while (ExitPass == false)
	{
		getline (cin,UserInput);
		UserInput = StringFixer(UserInput);
		ExitPass = CorrectSelection(UserInput, NumCorrectAnswers, ptrRightAnswers);
		if (ExitPass == false)
		{
			cout << "Invalid choice, please try again: ";
//			InvalidAnswer(int SarcasmMeter);
		}
	}

	return UserInput;
	//function ONLY returns a correct UserInput value
}


//Calculates and returns the number of days from start of year to start of MonthSelected (Ex: Month 2, NumDaysPast = 31)
int NumDaysPast(int MonthSelected)
{
	int n = 0; //"n" changes if month is past february (its 28 days instead of 30)
	//			//Checks if logic works for finding the right month and #days until the first of said month
//			int n = 0;
//			for (int MonthSelected = 1; MonthSelected <=12; MonthSelected++){
//
//					if (MonthSelected > 2)
//					{
//						n = 2; 	//February
//					} else {
//						n = 0;
//					}
//			NumDays = ((MonthSelected)/2*(31) + (MonthSelected-1)/2*(30)- n); //61 is 31 + 30
//			cout << "Month: " << MonthSelected << "	NumDays: " << NumDays << "\n";
//			}
	if (MonthSelected > 2)
		{
			n = 2; 	//February
		} else {
			n = 0;
		}
	return((MonthSelected)/2*(31) + (MonthSelected-1)/2*(30)- n);
//			cout << "Debug: NumDays: " << NumDays << "\n";
}



//Uses "GetUserInput" and the array of correct answers to return a month represented as an integer. (Ex: if August was chosen, returns 8)
int Month_Selection(int NumCorrectAnswers, string* ptrMonthAnswers)
{
	string UserInput = GetUserInput(NumCorrectAnswers, ptrMonthAnswers);
	cout << "\n";
	int MonthSelected;
	for (int i = 0; i < NumCorrectAnswers; i++)
	//for loop will index where the right answer lies out of all the options to indicate the selected month
	{
		string* ptrTempAnswer = ptrMonthAnswers+i;
		if (UserInput == *ptrTempAnswer) //UserInput1 should already be filtered and matching one of the "MonthAnswers" values
		//Uses integer placement to index the month
		{
			MonthSelected = i/2+1; //Since each month has two options, dividing integers rounds down, therefore returning the month position denoted as 0->11 or 1->12 (when you +1 to the outcome)
//					cout <<Debug:  "Month Selected: " << MonthSelected << "\n";
			i = NumCorrectAnswers+1; //exits for loop
		}
	}
	return MonthSelected;
}



//Prints month options & "select a month" to terminal
void PrintMonthOptions()
{
	cout <<	"[1] January	[2]  February	[3]  March	[4]  April\n"
			"[5] May		[6]  June	[7]  July	[8]  August\n"
			"[9] September	[10] October	[11] November	[12] December\n"
			"Select a month: ";
}



//Checks all days in a given month and returns a true statement if it finds an existing event, otherwise returns false
bool IsMonthAvailable(int NumDays, int MonthSelected, MyEvent Event2022[])
{
	int NumFreeDays = 0;
//	cout <<"Debug: MonthAvailability \n";
//	cout <<"Debug: " << Event2022[0].EventDay << "\n";
//	cout <<"Debug: " << Event2022[0].EventName << "\n";
//	cout <<"Debug: " << Event2022[0].EventDescription << "\n";
	for (int i = 0; i<NumDaysInMonth(MonthSelected); i++)
	{
		if (Event2022[NumDays+i].EventDay != 0)
		{
			NumFreeDays ++;
		}
	}
//	cout <<"Debug: NumFreeDays: " << NumFreeDays << "\n";
	if (NumFreeDays == NumDaysInMonth(MonthSelected))
	{
		cout <<"The entire month is booked!\n";

		return false;
	} else {
		return true;
	}
}



bool IsMonthEmpty(int NumDays, int MonthSelected, MyEvent Event2022[])
{
	int NumFreeDays = 0;
//	cout <<"Debug: IsMonthEmpty \n";
//	cout <<"Debug: " << Event2022[0].EventDay << "\n";
//	cout <<"Debug: " << Event2022[0].EventName << "\n";
//	cout <<"Debug: " << Event2022[0].EventDescription << "\n";

	for (int i = 0; i<NumDaysInMonth(MonthSelected); i++)
	{
		if (Event2022[NumDays+i].EventDay == 0)
		{
			NumFreeDays ++; //counts number of days free
		}
	}
//	cout <<"Debug: IsMonthEmpty NumFreeDays: " << NumFreeDays << "\n";
	if (NumFreeDays == NumDaysInMonth(MonthSelected))
	{
		return true;
	} else {
		return false;
	}


}



//takes in the an integer between 1&12 and returns number of days in its corresponding month. Outputs 0 if input is not between 1 & 12
int NumDaysInMonth(int MonthSelected)
{
//adjust for which month: even, odd or February
	int MonthType = 0;
	if (MonthSelected % 2 == 0) //if equals 0, its even
	//Checks if month selected is even or odd.
	{
		if (MonthSelected == 2)
		{
			MonthType = 28;		//February: MonthType = 28
		} else {
			MonthType = 30;	 	//Even: MonthType = 30
		}
	} else {
		MonthType = 31;			//Odd: MonthType = 31
	}
	return MonthType;
}



//Asks user to confirm their choice. Returns true if yes, false if no
bool UserConfirmCheck()
{
	cout << "Are you sure? \n [Yes] or [No]: ";
	string UserCheckAnswers[4] = {"Yes", "Y", "No", "N"};
	string* ptrUserCheckAnswers = &UserCheckAnswers[0];

	if (CorrectSelectionIndex(GetUserInput(4, ptrUserCheckAnswers), 4, ptrUserCheckAnswers) < 2){
		return true;
	} else {
		return false;
	}

}




void InvalidAnswer(int SarcasmMeter)
{

}



//outputs the selected month, its days and whether they're available or unavailable
void PrintMonthEvents(int MonthSelected, MyEvent Event2022[])
{
	int NumDays = NumDaysPast(MonthSelected);	//the +6 is to denote that the first day 	of 2022 was on saturday
	int WeekDayPos = 0;
	if ((((NumDays+7)/7)*7) <= 7)
		{
//			cout << " Debug: Outcome = D: (((NumDays[i]+7)/7)*7)	" << (((NumDays+7)/7)*7) << "\n";
			WeekDayPos  = (((NumDays+7)/7)*7); //count # of days before the beginning of each month
		} else {
//			cout << " Debug: Outcome = A-D: (NumDays[i]+7) - (((NumDays[i]+7)/7)*7)	" << (NumDays+7) - (((NumDays+7)/7)*7) << "\n";
			WeekDayPos  = (NumDays+7) - (((NumDays+7)/7)*7); //count # of days before the beginning of each month
		}

//    cout << "Debug: PrintMonthEvents(): WeekDayPos: " <<WeekDayPos << "\n";
	cout << "	[Sun]			[Mon]			[Tues]			[Wed]			[Thurs]			[Fri]			[Sat]\n";


	for (int i = 1; i<WeekDayPos; i++)
	{
		cout<< "			";
	}
	for (int i = 1; i<=NumDaysInMonth(MonthSelected); i++)
	{
		if (Event2022[NumDays+i-1].EventDay != 0)
		{
			cout << "[" << i << "]	'Unavailable'	";
		} else {
			cout << "[" << i << "]	'Available'	";
		}

        if (WeekDayPos == 7)
		{
			cout << "\n";
			WeekDayPos = 1;
		} else {
		WeekDayPos ++;
        }
	}
}




void CreateNewEvent(int MonthAnswersSize, string* ptrMonthAnswers, MyEvent Event2022[])
{
	cout <<"\n'Create new event' has been selected \n";
				PrintMonthOptions();

				//-------------Gets Month and # of days from start of year to start of selected month--------------

				int MonthSelected = Month_Selection(MonthAnswersSize, ptrMonthAnswers);
	//			cout << "Debug: MonthSelected: " << MonthSelected << "\n";
				int NumDays = NumDaysPast(MonthSelected); //# of days from start of year to start of selected month
	//			cout << "Debug: NumDays: " << NumDays << "\n";


				//--------------Checks availability in that month----------------

				bool MonthAvail = false; //statement to view if selected month is available or not
				MonthAvail = IsMonthAvailable(NumDays, MonthSelected, Event2022);
	//			cout << "Debug: MonthAvail" << MonthAvail << "\n";

				string* MonthAnswers = ptrMonthAnswers+(MonthSelected*2-2);
				if (MonthAvail == false)
				{
					cout << &MonthAnswers << "has no available days\n";
				}

				//--------------Generates MonthDayAnswers------------------

				if (MonthAvail == true)
				{
					string MonthDayAnswers[NumDaysInMonth(MonthSelected)]; //MonthDayAnswers array houses all available days in the given month
					for (int i = 0; i < NumDaysInMonth(MonthSelected); i++)
						//Creates a string array of correct answers for days of the month. Puts 1-30 or 1-31
					{
	//					cout << "Debug: Event2022[NumDays+i].EventDay is: " << Event2022[NumDays+i].EventDay << "	";
						if (Event2022[NumDays+i].EventDay == 0)
						{

							MonthDayAnswers[i]=to_string(i+1); //day is available
	//						cout << "Debug: MonthDayAnswers (Day available) index: '" << i << "' Day: " << MonthDayAnswers[i] << "\n";
						}

						if (Event2022[NumDays+i].EventDay != 0)
						{

							MonthDayAnswers[i] = "0"; //day is unavailable
	//						cout << "Debug: MonthDayAnswers (Day unavailable) index: '" << i << "' Day: " << MonthDayAnswers[i] << "\n";

						}
					}

					//PRINT MONTH EVENT TO SCREEN

					//----Day----
					string* ptrMonthDayAnswers = &MonthDayAnswers[0];
					cout << "Select a day: ";
					int DaySelected= stoi(GetUserInput(sizeof(MonthDayAnswers)/sizeof(MonthDayAnswers[0]), ptrMonthDayAnswers)); //'stoi' is a string to int function. This GetUserInput should only return 1-31 in form of strings
					Event2022[NumDays+DaySelected-1].EventDay = DaySelected;
	//				cout << "Debug: Day selected Event2022[NumDays+DaySelected-1].EventDay: " << Event2022[NumDays+DaySelected-1].EventDay << "\n";

					//----Month----
					Event2022[NumDays+DaySelected-1].EventMonth = MonthSelected;

					//----Event Name-----
					cout <<"Event Name: ";
					getline(cin,Event2022[NumDays+DaySelected-1].EventName);
	//				cout <<"Debug: Event name entered: " << Event2022[NumDays+DaySelected-1].EventName << "\n";

					//----Event Description----
					cout <<"Event Description: ";
					getline(cin,Event2022[NumDays+DaySelected-1].EventDescription);
	//				cout <<"Debug: Event description entered: " << Event2022[NumDays+DaySelected-1].EventDescription << "\n";
				}
}




void TestFunc()
{
	int NumDays[12] = {0, 31, 59, 90, 120, 151, 181, 212, 242, 273, 303, 334};

	for (int i =0; i < 12; i++)
	{
		if ((((NumDays[i]+7)/7)*7) <= 7)
		{
			cout << " Outcome = D: (((NumDays[i]+7)/7)*7)	" << (((NumDays[i]+7)/7)*7) << "\n";

		} else {
			cout << " Outcome = A-D: (NumDays[i]+7) - (((NumDays[i]+7)/7)*7)	" << (NumDays[i]+7) - (((NumDays[i]+7)/7)*7) << "\n";
		}
//		cout << (NumDays[i]+7) - (((NumDays[i]+7)/7)*7) << "	C: " << ((NumDays[i]+7)/7) << "	D: " << (((NumDays[i]+7)/7)*7) << "\n";

//		cout << " B%: " << ((NumDays[i]+7)%7) << "\n";
	}

}



//Displays and deletes events if so be it. Returns true if delete occurs. Returns if nothing was deleted
bool DeleteEvent(int MonthAnswersSize, string* ptrMonthAnswers, MyEvent Event2022[])
{
	PrintMonthOptions();


	//-------------Gets Month and # of days from start of year to start of selected month--------------
	int MonthSelected = Month_Selection(MonthAnswersSize, ptrMonthAnswers);
	int NumDays = NumDaysPast(MonthSelected); //# of days from start of year to start of selected month


	//-------------Checks month availability------------
	bool MonthAvail = false;
	MonthAvail = IsMonthEmpty(NumDays, MonthSelected, Event2022);


//			cout << "Debug: IsMonthAvailable from DeleteEent: " << MonthAvail << "\n";

	if (MonthAvail == false)
	{
		//-----------counts # of available days in a month----------------
		int EventAnswersSize = 1;
		for (int i = 0; i<NumDaysInMonth(MonthSelected); i++)
		{
			if (Event2022[i+NumDays].EventDay !=0)
			{
				EventAnswersSize ++;
			}
		}
		string EventAnswers[EventAnswersSize*2]; //size is double due to right answer being the "day" and the "Event name"


		//------------Displays and stores all events in selected month-----------------
		EventAnswersSize = 0;
		cout << "Events in the month: \n";
		for (int i = 0; i<NumDaysInMonth(MonthSelected); i++)
		{
			if (Event2022[i+NumDays].EventDay !=0)
			{
//				cout << "Debug: EventAnswersSize: " << EventAnswersSize << "\n";
				cout << "Day: [" << Event2022[i+NumDays].EventDay << "]	Name: '" << Event2022[i+NumDays].EventName << "'	Description: '" << Event2022[i+NumDays].EventDescription << "'\n";
				EventAnswers[EventAnswersSize] =  to_string(Event2022[i+NumDays].EventDay);
				EventAnswers[EventAnswersSize+1] =  StringFixer(Event2022[i+NumDays].EventName);
//				cout << "Debug: EventAnswers[" << EventAnswersSize << "]: "	<< EventAnswers[EventAnswersSize];
//				cout << "	EventAnswers[" << EventAnswersSize+1 << "]: " << EventAnswers[EventAnswersSize+1] << "\n\n";
				EventAnswersSize= EventAnswersSize+2;
			}
		}
		cout << "Select an event to delete: ";
		string* ptrEventAnswers = &EventAnswers[0];


		//-----------Gets user input and grabs the index from the "EventAnswers"-----------------
		int EventAnswerIndex = CorrectSelectionIndex(GetUserInput(sizeof(EventAnswers)/sizeof(EventAnswers[0]), ptrEventAnswers),	sizeof(EventAnswers)/sizeof(EventAnswers[0]), 	ptrEventAnswers);
		if (EventAnswerIndex % 2 != 0) //if index is odd, it corresponds with string not day
		{
			EventAnswerIndex = EventAnswerIndex - 1;
		}


		//----------Deletes Event--------------------

		if (UserConfirmCheck() == true)
		{
//			cout << "Debug: DeletEvent: NumDays: " << NumDays << "\n";
//			cout << "Debug: DeletEvent: " << "stoi(EventAnswers[EventAnswerIndex])-1: " <<  stoi(EventAnswers[EventAnswerIndex])-1 << "\n";
//			cout << "Debug: NumDays + stoi(EventAnswers[EventAnswerIndex])-1 = " << NumDays + stoi(EventAnswers[EventAnswerIndex])-1 << "\n";
			cout << "Deleting event day: '" << Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventDay << "' ";
			cout << "month: '" << Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventMonth << "' ";
			cout << "Event name: '" << Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventName << "' \n";
			Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventDay = 0;
			Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventMonth = 0;
			Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventName = "0";
			Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventDescription = "0";
			return true;
		} else {
			return false;
		}
	}
	if (MonthAvail == true)
	{
		cout << "There are no events occurring in this month \n";
		return false;
	}
	return false;
}



string MonthName(int MonthSelected)
{
	if (MonthSelected >12 or MonthSelected <0){
		return "Error";
	}

	string Months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
//	cout << "Debug: MonthName: index: " << MonthSelected-1 << "output: " << Months[MonthSelected+1] << "\n";
	return Months[MonthSelected-1];
}
#if 0
int SelectMonth(){
	string month;
	bool Pass = false;
	cout << "[1] January	[2]  February	[3]  March	[4]  April\n"
			"[5] May		[6]  June	[7]  July	[8]  August\n"
			"[9] September	[10] October	[11] November	[12] December\n"
			"Select a month: ";

	while (Pass == false){
		getline (cin,month);
//		month = "11"; //debugging statement: Replaces the getline function
		month = StringFixer(month);
//		cout <<"you entered: " <<month <<"\n";
		string Months[2][12] = {
		{"January", "February","March","April","May","June","July", "August","September", "October", "November", "December"},
		{"1","2","3","4","5","6","7","8","9","10","11","12"}
		};
		for (int i = 0; i < 12; i++) {
//			cout <<"i value: " << i <<" Entered month: "  <<month <<" Compared month: " <<Months[i] <<"\n"; //debugging statement
			if (month == Months[0][i]){
				Pass = true;
				return i;
			}
			if (month == Months[1][i]){
				Pass = true;
				return i;
			}
		}
		if (Pass == false){
			cout << "invalid choice. Re-select a month: ";
		}
	}
	return 13;
}




void AppendToFile(int month, string FileName){

	//function appends an integer into a new line into a selected file

	fstream EventsFile;
	EventsFile.open(FileName, ios::app); //append
	if (EventsFile.is_open()){
		EventsFile << "'"<< month << "' ";
		EventsFile << "\n";
	}
	EventsFile.close();
}
#endif
