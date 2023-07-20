#include <iostream>
#include <string>
using namespace std;

// Mehmet Enes Battal - Homework 1

int main()
{
	string name;

	cout << "Please enter your name: ";  //Get the name from user
	cin >> name;  //Store the user's name in a variable

	double outgoingprice, outgoingmin, outgoingtotal;

	cout << endl << name << ", please enter the price for outgoing call per minute: "; //Get the price of outgoing call per minute
	cin >> outgoingprice; 
	
	cout << name << ", please enter how many minutes you have talked in outgoing calls: "; //Get the minutes talked as outgoing call
	cin >> outgoingmin;

	outgoingtotal = outgoingprice * outgoingmin; //Calculate the amount spent on outgoing calls

	cout << name << ", you have spent " << outgoingtotal <<" TL for outgoing calls you made while you are abroad." << endl << endl;

	double incomingprice, incomingmin, incomingtotal;

	cout << name << ", please enter the price for incoming call per minute: "; //Get the price of incoming call per minute
	cin >> incomingprice;

	cout << name << ", please enter how many minutes you have talked in incoming calls: "; //Get the minutes talked as incoming call
	cin >> incomingmin;

	incomingtotal = incomingmin * incomingprice; //Calculate the amount spent for incoming calls

	cout << name << ", you have spent " << incomingtotal << " TL for incoming calls you made while you are abroad." << endl << endl;
	
	double dataprice, data_gb, data_mb, datatotal;

	cout << name << ", please enter the price for internet usage per MB: "; //Get price of internet usage per MB
	cin >> dataprice;

	cout << name << ", please enter how many GBs you have used: "; //Get the number of GB’s of internet used
	cin >> data_gb;

	data_mb = data_gb * 1024; //Calculate the used internet in megabytes
	datatotal = data_mb * dataprice; //Calculate the amount spent for internet usage

	cout << name << ", you have spent " << datatotal << " TL for the internet while you are abroad." << endl << endl;

	double smsprice, smscount, smstotal;

	cout << name << ", please enter the price for one SMS: "; //Get the price of one SMS
	cin >> smsprice;

	cout << name << ", please enter the number of SMS you have sent: "; //Get the number of SMS’s sent
	cin >> smscount;

	smstotal = smsprice * smscount; //Calculate the amount spent for sms 

	cout << name << ", you have spent " << smstotal << " TL for the SMS while you are abroad." << endl << endl;

	double withouttax, tax, total;

	withouttax = outgoingtotal + incomingtotal + datatotal + smstotal; //Calculate total cost of all used services
	tax = withouttax * 18 / 100; //Calculate the tax imposed on total cost
	total = withouttax + tax; //Calculate the total bill fee

	cout << name << ", total cost for all roaming services is " << withouttax << " TL." << endl;
	cout << name << ", tax is " << tax << " TL." << endl;
	cout << name << ", total roaming bill fee with tax is " << total <<" TL." << endl;
	

	return 0;
}