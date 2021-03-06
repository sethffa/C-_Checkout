// Final Project.cpp : Defines the entry point for the console application.
//

//Seth McFarland
//Final_Project.cpp
//Last worked on //2018
//Input movie to order, calculate late fee, output cost
// Final Project : Defines the entry point for the console application.
#pragma once

#include "stdafx.h"
#include<chrono>
#include "MovieCheckOut.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;


int main()
{
	int items = 0;
	menuItemType menuList[] = {
		"Movie 11 ", 7.99,
		"Movie 12 ", 4.99,
		"Movie 13 ", 3.99,
		"Movie 14 ", 10.99,
		"Movie 15 ", 12.99,
		"Movie 16 ", 8.99,
		"Movie 17 ", 10.99,
		"Movie 81 ", 10.99,
		"Movie 19 ", 18.99,
		"Movie 17 ", 12.99,
		"Movie 178 ", 14.99,
		"Movie 189 ", 7.99,
		"Movie 112 ", 4.99,
		"Movie 145 ", 6.99,
		"Movie 164 ", 3.99,
		"Movie 1788 ", 6.99,
		"Movie 1784 ", 6.99,
		"Movie 14523 ", 6.99,
		"Movie 1425 ", 6.99,
		"Movie 1245 ", 7.99,

	};
	menuItemType order[20];
	char again = 'Y';
	

	cout << "Welcome to the Movie Checkout Place " << endl;

	while (again == 'y' || again == 'Y') {
		
		
	 
		getCustomerInfo(); //Ask for customer info
		showMenu(menuList, 20); //Movie order
		getdata(menuList, order, items); //Input
		printBill(order, items); //Print bill
	


	

		
		cout << "Restart program y/n ";
		cin >> again; //Restarting the program 
	}
	

}
void getCustomerInfo()
{
	string name;
	string email;
	string phonenumber;

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter email: ";
	cin >> email;
	cout << "Enter phone number: ";
	cin >> phonenumber;
}

void showMenu(menuItemType a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		cout << i + 1 << ". " << setw(16) << left << a[i].menuItem << "$" << setprecision(2) << fixed << a[i].menuPrice << endl;
}


void printBill(menuItemType order[], int items)
{
	int i;
	string day;
	double total = 0, tax;
	cout << "Total Cost\Ordered Movies\n Item\t price\n";
	showMenu(order, items);
	for (i = 0; i < items; i++)
		total += order[i].menuPrice;
	cout << "\nMovie total \t" << "$" << setprecision(2) << fixed << total << endl;
	tax = total * .06; //tax for kentucky
	cout << "Tax\t\t" << "$" << setprecision(2) << fixed << tax << endl;
	cout << "Amount Due \t" << "$" << setprecision(2) << fixed << total + tax << endl;
	cout << "Are you paying with cash, credit, or debit? ";
	int paymentsetup();
	{
		int n;

		cout << "1 - CASH" << endl;
		cout << "2 - DEBIT" << endl;
		cout << "3 - CREDIT" << endl << endl;
		cout << "PAYMENT TYPE: ";

		cin >> n;

		switch (n) {
		case 1:
			cout << "You selected cash " << endl;
			break;
		case 2:
			cout << "You selected debit " << endl;
			break;
		case 3:
			cout << "You selected credit " << endl;
			break;
		default:
			cout << "Wrong input";
		}




	}
	cout << "Late fee \t" << "$" << setprecision(2) << fixed << total * .3 << endl;
	cout << "Enter day of week: ";
	cin >> day;
	cout << "Return date: \t" << setprecision(2) << fixed <<  day + " Of next week" << endl;
	cout << "Have a great day";
}






void getdata(menuItemType menu[], menuItemType order[], int& items)
{
	char answer = 'Y';
	int n;
	while (toupper(answer) == 'Y') {
		cout << "Enter the movie number: ";
		cin >> n;
		while (n < 1 || n > 20) {
			cout << "invalid number\n";
			cout << "Enter the movie number: ";
			cin >> n;
		}
		order[items].menuItem = menu[n - 1].menuItem;
		order[items].menuPrice = menu[n - 1].menuPrice;
		items++;


		cout << "Is there any other movies to checkout? (y/n) ? ";
		cin >> answer;


	}
}


