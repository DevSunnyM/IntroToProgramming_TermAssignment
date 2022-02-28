//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////														 /////////////////////////////////
/////////////////////////		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!						   ///////////////////////////
//////////////////////				IMPORTANT!!! Please read the 							 /////////////////////////	
/////////////////////////		Instruction text file before compiling					  ////////////////////////////
///////////////////////////////														//////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>																								//////
#include <iomanip>	// allows the use of manipulator functions such as setw()									//////
#include <fstream> // Allows the use of creating, storing, and retrieving information from an external file		//////
#include <string> // Allows the use of strings																	//////	
#include <sstream> // allows the conversion from a string into a char and vice versa							//////
#include <cstring> // Allows the use of c-strings																//////
#include <vector> // allows me to use vectors																	//////
#include <stdlib.h> // allows me to use a standard string library												//////
#include <cstdlib> // CLoses the program if the file is not in the directory									//////
#include <cmath> // Allows me to use mathematic functions		for removeName function							//////
#include <algorithm> //allows sorting function																	//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;																							//////	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Person{															////// group of data elements grouped together under one name
	string name;														//////
	string Address;														//////
	string PostalCode;													//////
	string quantity;													//////	
																		//////
};																		//////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int addPerson (vector<Person>& p);										//////		
void displayPerson(const vector<Person>& p);							//////
//void sortNames(vector<Person>& p);									//////		Declaring all the functions
void searchPerson (vector<Person> p);									//////		that will be used...
void editPackage(vector <Person>& p);									//////
void removePerson (vector<Person> &p);									//////
void saveFile(vector<Person> p, ofstream& fout);						//////
void openFile(vector<Person> p, ifstream& fin);							//////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){																						//////
																								//////
	int size =50, function=0, quit=0;   //size declared here so it has something to work with. 	//////
	vector <Person> p;																			//////
	while(true)																					//////
	{																							//////
	cout << endl;		//So it gives some space between the functions when called				//////
	cout << "================================================="<<endl;							//////
	cout << "=========Menu==========Menu=========Menu========="<<endl;							//////		
	cout << "=========Menu==========Menu=========Menu========="<<endl;							//////		Display title for the menu
	cout << "=========Menu==========Menu=========Menu========="<<endl;							//////
	cout << "================================================="<<endl;							//////
	cout << "1)	Add a package to the list." <<endl;												//////
	cout << "2)	Sort all the packages." <<endl;													//////
	cout << "3)	Find the location of a package." <<endl;										//////
	cout << "4)	Display the entire inventory list of packages." <<endl;							//////
	cout << "5)	Remove a name from the list."<<endl;											//////	
	cout << "6)	Edit the current information from a package in the list."<<endl;				//////
	cout << "	What would you like to do: ";													//////
	cin >> function;																			//////
																								//////
	if (function==1) 																			//////
	size = addPerson(p);																		//////
//	else if (function==2)sortNames(p);															//////
	else if (function==4)displayPerson(p);														//////	Which values to input to make the menu work
	else if (function == 5)removePerson(p); 													//////
	else if (function==3)searchPerson(p);														//////
																								//////		
	}																							//////		
																								//////			
	vector<Person> people;																		//////
	vector <Person> newPeople;																	//////			
	addPerson(people);																			//////
	displayPerson(people);																		//////
	ofstream fout;																				//////
	fout.open("record.txt");																	//////
	saveFile (people, fout);																	//////
	fout.close();																				//////
	ifstream fin;																				//////
	fin.open("record.txt");			//tells program to store information in record.txt			//////							
	openFile (newPeople, fin);																	//////
	displayPerson(newPeople);																	//////
																								//////
}																								//////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int addPerson (vector<Person>& p){			//Function to add the information					//////
	string name;																				//////		
	string Address;																				//////
	string PostalCode;																			//////
	string quantity;																			//////	
	Person aPerson;																				//////
	while (true){			//loop to add as many recipients as required...						//////
		cin.ignore();																			//////
		cout << "Enter name, quit to stop: ";													//////
		getline(cin, name);																		//////	
																								//////
																								//////
		if (name == "quit"){																	//////
			break;																				//////
		}																						//////
		aPerson.name=name;																		//////
																								//////
																								//////
		cout << "Enter Address: ";																//////
		getline(cin, Address);																	//////
		aPerson.Address=Address;																//////
																								//////
		cout << "Enter PostalCode: ";															//////
		getline(cin, PostalCode);																//////
		aPerson.PostalCode=PostalCode;															//////
																								//////
		cout<< "Enter quantity of packages: ";													//////
		getline(cin, quantity);																	//////
		cin.ignore(1);																			//////
		aPerson.quantity=quantity;																//////
																								//////
																								//////	
		p.push_back(aPerson);																	//////		
	}																							//////
}																								//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void displayPerson(const vector<Person>& p){					//function displays all the information in a nice table			//////
	for (int i=0; i<p.size(); i++){																								//////	
		cout<<p[i].name<<setw(10)<<'\t'<<p[i].Address<<setw(10)<<'\t'<< p[i].PostalCode<<setw(10)<<'\t'<<p[i].quantity<<endl;	//////
	}																															//////
																																//////
}																																//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
																																//////
//////////////////////////////////////////////////////////////////////////////////////////////									//////	
//!!!! SORT NAME FUNCTION RUNNING ERROR: PREDEFINED_OPS.H WHEN TRYING TO COMPILE !!!!!!!//////									//////
//!!!! WITH SORTNAMES(VECTOR<PERSON>& P) IS USED... UNSURE OF MEANING AND/OR WHY !!!!!!!//////									//////	
//////////////////////////////////////////////////////////////////////////////////////////////									//////
																																//////	
//void sortNames(vector<Person>& p) // This function sorts the names in alphabetical order										//////
//{																																//////	
//	sort(p.begin(),p.end());																									//////
//}																																//////
																																//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void searchPerson (vector<Person> p){			// Function allows me to search the vector										//////
	int i=0;									//  array to find the location of a "persons" information						//////
	string searchPerson;																										//////
	cout << "What name should be searched for within the file?: ";																//////
	cin.ignore(1, '\n');																										//////
	getline(cin, searchPerson);																									//////
//	while (i<p.size()){																											//////
//		if(p[i]==searchPerson) {																								//////
//		cout<<"The name is stored as p["<<i<<"]"<<endl;				issues here as well with command operators such as "=="...	//////
//		}																														//////
//		i++;																													//////		
//	}																															//////			
}																																//////		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void removePerson(vector<Person>& p) 		// This function allows me to remove a name from the list							//////
{																																//////
	string remove;																												//////
	bool match;																													//////
	cout<<"Which Name should be removed?  :";																					//////
	cin.ignore(1,'\n'); //it ignores everything after new line																	//////	
	getline(cin, remove);																										//////	
	//for (int i=0;i<p.size();i++)																								//////
	//for (int j=0;j<p.size()-1;j++)																							//////		
	//		if(p[j]==remove){																									//////	
	//			swap(p[j],p[j+1]);							I was having issues making this work....							//////
	//			match = 1;											command operator "==" issue here as well...					//////
	//		}																													//////
	//if (match == 1){																											//////	
	//		p.erase(p.end()-1);																									//////
	//}																															//////
}																																//////	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
void saveFile(vector<Person> p, ofstream& fout){								//Saves the information to "record.txt			//////			
	for (int i=0; i<p.size(); i++){																								//////
		fout << p[i].name << ";"<<p[i].Address<<";"<<p[i].PostalCode<<";"<<p[i].quantity;										//////
		if(i<p.size()-1){																										//////	
			fout << endl;																										//////
		}																														//////	
	}																															//////	
}																																//////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void openFile(vector<Person> p, ifstream& fin){			//function to open the record.txt file in order to retrieve information	//////
	Person aPerson;										//When required															//////			
	string str;																													//////
	stringstream ss;																											//////	
	while (!fin.eof()){																											//////				
		getline(fin, aPerson.name, ';');																						//////
		getline(fin, str, ';');																									//////	
		ss<<str;																												//////
		ss>>aPerson.Address;																									//////
		ss.clear();																												//////	
		getline(fin, str);																										//////
		ss<<str;																												//////		
		ss>>aPerson.PostalCode;																									//////
		ss.clear();																												//////
		getline(fin, str, ';');																									//////
		ss<<str;																												//////
		ss>>aPerson.quantity;																									//////
		ss.clear();																												//////
		p.push_back(aPerson);																									//////
	}																															//////					
																																//////
}																																//////	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////																		//////////////////////////////
//////////////////////////////////				END OF CODE => THANK YOU FOR READING					//////////////////////////////
//////////////////////////////////																		//////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
