//============================================================================
// Name        : Moment.cpp
// Author      : Jonathan Kiing
// Version     : may 29, 2022
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//
#include <iostream>
#include <cmath>
using namespace std;

/*
 * --------DECLARING FUNCTIONS--------
 */
//build functions BEFORE running int main or declare them before int main
void coutExamples();
void switchExamples();
void getlineExamples();
string* pointerExample();
double simpleMaths(double x1, double y1);
double differentRoots(double x1, double y1);



//int main() {
//	/* wow look at me
//	 * a multi-lined
//	 * comment */
//
//	coutExamples();
//	getlineExamples();
//	switchExamples();
////	cout << simpleMaths(13, 88) << endl;
//	/* debugging math and variables
//
//	double lego = 3.444;
//	cout << lego << endl;
//	*/
//	cout << differentRoots(13,88) << endl;
//
//	return 0;
//}

/*
 * --------writing to the console examples--------
 */

void coutExamples() {
//examples of syntax for cout
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << "   /|" << endl;
//	cout << "  / |" << endl;
//	cout << " /  |" << endl;
//	cout << "/___|" << endl;

	int characterAge;
	string characterName = "JON";

//	characterName = "Jon";
	characterAge = 25;

	cout << "Hi I'm " <<characterName<< " and I am " <<characterAge<< endl;
}

void getlineExamples() {
	string lego;
	cout << "Type in the month:"<< endl;
	getline (cin,lego);
	cout << "you just entered '" <<lego<< "'. are you sure about that" << endl;

}

string* pointerExample(){
	string food = "Pizza";  // A food variable of type string
	string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

//	// Output the value of food (Pizza)
//	cout << "food variable:	" << food << "\n";
//
//	// Output the memory address of food (0x6dfed4)
//	cout << "&food variable:	" << &food << "\n";
//
//	// Output the memory address of food with the pointer (0x6dfed4)
//	cout << "ptr variable:	" << ptr << "\n";
	cout << "*ptr: " << *ptr << "\n";
	return ptr;
}


void switchExamples(){
	cout << "nothing happened" << endl;
//	string dateEntered;			//switches cannot use strings, only integers...
//	getline (cin,dateEntered);
//
//	switch(dateEntered){
//		case "monday":
//		//
//			break;
//		case "tuesday":
//
//			break;
//
//		case "wednesday":
//		//
//			break;
//
//		case "thursday":
//			break;
//
//		case "friday":
//		//
//			break;
//
//		case "saturday":
//
//			break;
//
//		case "sunday":
//
//			break;
//		default:
//			cout <<"That entry is not valid. Enter in one of the following options:"<< endl;
//			cout <<"monday"<< endl;
//			cout <<"tuesday"<< endl;
//			cout <<"wednesday"<< endl;
//			cout <<"thursday"<< endl;
//			cout <<"friday"<< endl;
//	}
}

/*
 * --------function and math operating examples--------
 */


double simpleMaths(double x1,double y1) {
	//make sure your variables match up!! no int x doubles
	//doubles are larger than floats (15 vs 7 decimal places)
	return((x1+y1)/y1);
}
#if 0
double differentRoots(double x1, double y1) {
	double lego1;
	double lego2;
	lego1 = cbrt(x1+y1);
	lego2 = pow((x1+y1),0.33);
	return (lego1,lego2);
}
#endif



