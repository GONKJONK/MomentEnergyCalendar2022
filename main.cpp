//============================================================================
// Name        : Moment.cpp
// Author      : Jonathan Kiing
// Version     : may 29, 2022
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <src/CalendarFunctions.h>


#if 0
string* pointerExample();


void AppendToFile(int month,string FileName);
//------------------------Month selection function----------------------------
int SelectMonth();
//Provides the user with months to select then returns an integer representing the selected month
//ex: January outputs 0, December outputs 11 (its month-1)
#endif





int main()
{

	//----------Establish a localized database on ram--------------------
	const int YearSize = 365;
	MyEvent Event2022[YearSize];
	for (int i = 0; i <365; i++)
		//need to initialize memory otherwise random numbers pop up inside the event memory
	{
		Event2022[i].EventDay = 0;
		Event2022[i].EventMonth = 0;
		Event2022[i].EventName = "0";
		Event2022[i].EventDescription = "0";
	}

	int NumEvents = 0;
//	string* ptrEvent2022 = &Event2022[];

//	make function to fill in event with events from a txt file
	string UserInput;
	bool ExitProgram = false;

	//MainMenuAnswers are the correct input answers for the main menu
	string MainMenuAnswers[10] = {"Createnewevent", "1", "Deleteanevent", "2", "Viewremainingdays","3", "Viewcalendarandevents", "4", "Exitprogram", "5"};
	string* ptrMainMenuAnswers = &MainMenuAnswers[0];

	//MonthAnswers are all correct inputs for selecting a month
	string MonthAnswers[24] = {"January","1","February","2","March","3","April","4","May","5","June","6","July","7","August","8","September","9","October","10","November","11","December","12"};
	string* ptrMonthAnswers = &MonthAnswers[0];
//	int NumMonthAnswersPerMonth = 2; //There are two correct options



	while (ExitProgram == false)
	{
		cout << "\nMain Menu. Select one of the following\n"
			"[1] Create new event\n"
			"[2] Delete an event\n"
			"[3] View remaining days\n"
			"[4] View calendar and events\n"
			"[5] Exit program\n"
			"Main Menu Selection: ";

		UserInput = GetUserInput(sizeof(MainMenuAnswers)/sizeof(MainMenuAnswers[0]), ptrMainMenuAnswers);
		if (UserInput == MainMenuAnswers[0] or UserInput == MainMenuAnswers[1])

//------------------------------CREATE NEW EVENT------------------------------------

		{
			CreateNewEvent(sizeof(MonthAnswers)/sizeof(MonthAnswers[0]), ptrMonthAnswers, Event2022);
			NumEvents ++;
//			cout <<"\n'Create new event' has been selected \n";
//			PrintMonthOptions();
//
//			//-------------Gets Month and # of days from start of year to start of selected month--------------
//
//			int MonthSelected = Month_Selection(sizeof(MonthAnswers)/sizeof(MonthAnswers[0]), ptrMonthAnswers);
////			cout << "Debug: MonthSelected: " << MonthSelected << "\n";
//			int NumDays = NumDaysPast(MonthSelected); //# of days from start of year to start of selected month
////			cout << "Debug: NumDays: " << NumDays << "\n";
//
//
//			//--------------Checks availability in that month----------------
//
//			bool MonthAvail = false; //statement to view if selected month is available or not
//			MonthAvail = IsMonthAvailable(NumDays, MonthSelected, Event2022);
////			cout << "Debug: MonthAvail" << MonthAvail << "\n";
//
//			if (MonthAvail == false)
//			{
//				cout << MonthAnswers[MonthSelected*2-2] << "has no available days\n";
//			}
//
//			//--------------Generates MonthDayAnswers------------------
//
//			if (MonthAvail == true)
//			{
//				string MonthDayAnswers[NumDaysInMonth(MonthSelected)]; //MonthDayAnswers array houses all available days in the given month
//				for (int i = 0; i < NumDaysInMonth(MonthSelected); i++)
//					//Creates a string array of correct answers for days of the month. Puts 1-30 or 1-31
//				{
//
//					//CREATE PROTOCOL TO OUTPUT THE MONTH DAYS IN THE WEEKDAY ORDER AND LAYOUT
//
////					cout << "Debug: Event2022[NumDays+i].EventDay is: " << Event2022[NumDays+i].EventDay << "	";
//					if (Event2022[NumDays+i].EventDay == 0)
//					{
//
//						MonthDayAnswers[i]=to_string(i+1); //day is available
////						cout << "Debug: MonthDayAnswers (Day available) index: '" << i << "' Day: " << MonthDayAnswers[i] << "\n";
//					}
//
//					if (Event2022[NumDays+i].EventDay != 0)
//					{
//
//						MonthDayAnswers[i] = "0"; //day is unavailable
////						cout << "Debug: MonthDayAnswers (Day unavailable) index: '" << i << "' Day: " << MonthDayAnswers[i] << "\n";
//
//					}
//				}
//				//----Day----
//				string* ptrMonthDayAnswers = &MonthDayAnswers[0];
//				cout << "Select a day: ";
//				int DaySelected= stoi(GetUserInput(sizeof(MonthDayAnswers)/sizeof(MonthDayAnswers[0]), ptrMonthDayAnswers)); //'stoi' is a string to int function. This GetUserInput should only return 1-31 in form of strings
//				Event2022[NumDays+DaySelected-1].EventDay = DaySelected;
////				cout << "Debug: Day selected Event2022[NumDays+DaySelected-1].EventDay: " << Event2022[NumDays+DaySelected-1].EventDay << "\n";
//
//				//----Month----
//				Event2022[NumDays+DaySelected-1].EventMonth = MonthSelected;
//
//				//----Event Name-----
//				cout <<"Event Name: ";
//				getline(cin,Event2022[NumDays+DaySelected-1].EventName);
////				cout <<"Debug: Event name entered: " << Event2022[NumDays+DaySelected-1].EventName << "\n";
//
//				//----Event Description----
//				cout <<"Event Description: ";
//				getline(cin,Event2022[NumDays+DaySelected-1].EventDescription);
////				cout <<"Debug: Event description entered: " << Event2022[NumDays+DaySelected-1].EventDescription << "\n";
//				NumEvents ++;
//			}
		}


		if (UserInput == MainMenuAnswers[2] or UserInput == MainMenuAnswers[3])
		{

//----------------------------------DELETE EVENT-----------------------------
//
////			cout <<"2nd input\n";
//			cout << "\n'Delete an event' has been selected \n";
//			PrintMonthOptions();
//
//
//			//-------------Gets Month and # of days from start of year to start of selected month--------------
//			int MonthSelected = Month_Selection(sizeof(MonthAnswers)/sizeof(MonthAnswers[0]), ptrMonthAnswers);
//			int NumDays = NumDaysPast(MonthSelected); //# of days from start of year to start of selected month
//
//
//			//-------------Checks month availability------------
//			bool MonthAvail = false;
//			MonthAvail = IsMonthEmpty(NumDays, MonthSelected, Event2022);
//
//
////			cout << "Debug: IsMonthAvailable from DeleteEent: " << MonthAvail << "\n";
//
//			if (MonthAvail == false)
//			{
//				//-----------counts # of available days in a month----------------
//				int EventAnswersSize = 1;
//				for (int i = 0; i<NumDaysInMonth(MonthSelected); i++)
//				{
//					if (Event2022[i+NumDays].EventDay !=0)
//					{
//						EventAnswersSize ++;
//					}
//				}
//				string EventAnswers[EventAnswersSize*2]; //size is double due to right answer being the "day" and the "Event name"
//
//
//				//------------Displays and stores all events in selected month-----------------
//				EventAnswersSize = 0;
//				cout << "Events in the month: \n";
//				for (int i = 0; i<NumDaysInMonth(MonthSelected); i++)
//				{
//					if (Event2022[i+NumDays].EventDay !=0)
//					{
//						cout << "Day: [" << Event2022[i+NumDays].EventDay << "]	Name: '" << Event2022[i+NumDays].EventName << "'	Description: '" << Event2022[i+NumDays].EventDescription << "'\n";
//						EventAnswers[EventAnswersSize] =  to_string(Event2022[i+NumDays].EventDay);
//						EventAnswers[EventAnswersSize+1] =  StringFixer(Event2022[i+NumDays].EventName);
//						EventAnswersSize ++;
////						cout << "Debug: EventAnswers: " << i << " EventAnswers+1: " << i+1 << "\n";
//					}
//				}
//				cout << "Select an event to delete: ";
//				string* ptrEventAnswers = &EventAnswers[0];
//
//
//				//-----------Gets user input and grabs the index from the "EventAnswers"-----------------
//				int EventAnswerIndex = CorrectSelectionIndex(GetUserInput(sizeof(EventAnswers)/sizeof(EventAnswers[0]), ptrEventAnswers),	sizeof(EventAnswers)/sizeof(EventAnswers[0]), 	ptrEventAnswers);
//				if (EventAnswerIndex % 2 != 0) //if index is odd, it corresponds with string not day
//				{
//					EventAnswerIndex = EventAnswerIndex - 1;
//				}
//
//
//				//----------Deletes Event--------------------
//
//				if (UserConfirmCheck() == true)
//				{
////					cout << "Debug: NumDays + stoi(EventAnswers[EventAnswerIndex])-1 = " << NumDays + stoi(EventAnswers[EventAnswerIndex])-1 << "\n";
//					cout << "Deleting event day: '" << Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventDay << "' ";
//					cout << "month: '" << Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventMonth << "' ";
//					cout << "Event name: '" << Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventName << "' \n";
//					Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventDay = 0;
//					Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventMonth = 0;
//					Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventName = "0";
//					Event2022[NumDays + stoi(EventAnswers[EventAnswerIndex])-1].EventDescription = "0";
//					NumEvents --;
//				}

		//	cout <<"2nd input\n";
			cout << "\n'Delete an event' has been selected \n";

			if (DeleteEvent(sizeof(MonthAnswers)/sizeof(MonthAnswers[0]), ptrMonthAnswers, Event2022) == true)
			{
				NumEvents --;
			}

		}


		if (UserInput == MainMenuAnswers[4] or UserInput == MainMenuAnswers[5])

//---------------------------VIEW REMAINING DAYS-------------------------------
		{
//			cout <<"3rd input\n";
			cout << "Number of exisiting events: " << NumEvents <<"\n";
			cout << "Number of available days: " << 365-NumEvents <<"\n";

		}
		if (UserInput == MainMenuAnswers[6] or UserInput == MainMenuAnswers[7])
		//----View calendar and events----
		{
////			cout <<"4th input\n";
			cout << "\n'View Calendar and events' has been selected\n";
			cout << "[1] View all events\n"
					"[2] View each month\n"
					"[3] Back to Main Menu\n"
					"Select one of the options: ";

			string ViewCalnEveAnswers[6] = {"1", "Viewallevents", "2", "Searchbymonth", "3", "Backtomainmenu"};
			string* ptrViewCalnEveAnswers = &ViewCalnEveAnswers[0];

			int UserInput = CorrectSelectionIndex(GetUserInput(sizeof(ViewCalnEveAnswers)/sizeof(ViewCalnEveAnswers[0]), ptrViewCalnEveAnswers), sizeof(ViewCalnEveAnswers)/sizeof(ViewCalnEveAnswers[0]), ptrViewCalnEveAnswers);
			if (UserInput == 0 or UserInput == 1)
			{
				//view all events
				for (int i = 0; i<365; i++)
				{
					if (Event2022[i].EventDay !=0)
					cout << "Month: " << MonthName(Event2022[i].EventMonth) << "		Day: [" << Event2022[i].EventDay << "]	Name: '" << Event2022[i].EventName << "'	Description: '" << Event2022[i].EventDescription << "'\n";
				}

			}
			if (UserInput == 2 or UserInput == 3)
			{
				//view by month
				cout << "\n";
				PrintMonthOptions();
				int MonthSelected = Month_Selection(sizeof(MonthAnswers)/sizeof(MonthAnswers[0]), ptrMonthAnswers);
	//			cout << "Debug: MonthSelected: " << MonthSelected << "\n";

	//			cout << "Debug: NumDays: " << NumDays << "\n";
				PrintMonthEvents(MonthSelected, Event2022);

				cout << "\n[1] Select an event\n"
						"[2]  Back to main menu\n";
				string ViewEventAnswers[4] = {"1", "Selectanevent", "2", "Backtomainmenu"};
				string* ptrViewEventAnswers = &ViewEventAnswers[0];
				UserInput = CorrectSelectionIndex(GetUserInput(sizeof(ViewEventAnswers)/sizeof(ViewEventAnswers[0]), ptrViewEventAnswers), sizeof(ViewEventAnswers)/sizeof(ViewEventAnswers[0]), ptrViewEventAnswers);
				if (UserInput == 0 or UserInput == 1)
				{
					//Select an event
					cout << "Select an available day: ";

					//-------------Generates right answers----------------------
					//TURN INTO FUNCTION
					int NumDays = NumDaysPast(MonthSelected); //# of days from start of year to start of selected month

					string EventDayAnswers[NumDaysInMonth(MonthSelected)]; //MonthDayAnswers array houses all available days in the given month
					for (int i = 0; i < NumDaysInMonth(MonthSelected); i++)
						//Creates a string array of correct answers for days of the month. Puts 1-30 or 1-31
					{

						EventDayAnswers[i] = to_string(i);
					}
					string* ptrEventDayAnswers = &EventDayAnswers[0];
					string EventDaySelected = GetUserInput(sizeof(EventDayAnswers)/sizeof(EventDayAnswers[0]), ptrEventDayAnswers);
//					cout << "Debug: Event selected index: " << NumDays+stoi(EventDaySelected) <<"\n";
					if (Event2022[NumDays+stoi(EventDaySelected)-1].EventDay != 0)
					{
						cout << "Day: [" << Event2022[NumDays+stoi(EventDaySelected)-1].EventDay << "]	Name: '" << Event2022[NumDays+stoi(EventDaySelected)-1].EventName << "'	Description: '" << Event2022[NumDays+stoi(EventDaySelected)-1].EventDescription << "'\n";

					} else if (Event2022[NumDays+stoi(EventDaySelected)-1].EventDay == 0)
					{
						cout << "No event exists on the selected day\n";
					}

				} else if (UserInput == 2 or UserInput == 3)
				{

				}
			} else if (UserInput == 4 or UserInput ==5)
			{
				//exit
			}





		}
		if (UserInput == MainMenuAnswers[8] or UserInput == MainMenuAnswers[9])
		//----Exit program----
		{

			cout <<"Exit program confirmed, goodbye!\n";
			ExitProgram = true;
		}
	}

//#endif
}




