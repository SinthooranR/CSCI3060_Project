/*
This is a program that holds the definitions of the methods and classes defined in Transaction.h

@authors: Leonard Zbona, Sinthooran Ravinathan, Danooshan Sureshkumar
@since: 2019-01-14
@version 1.0
*/

#include <iostream>
#include "User.h" //Includes the declaration of the User class and its methods.
#include "Transaction.h" //Includes the declaration of the Transaction class and its methods.
#include <string>
#include <fstream>
#include <stdlib.h>

//Importing from the standard library in order to avoid using redundant methods and slowing down performance.
using std::to_string;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::stod;
//Method: Transaction
Transaction::Transaction(){

}


string cmd;
string result;

string newUser;
string accountType;
double userCredit;

string currUser;
string existUser;


string eventN;
string sellerN;
int ticketQ;
double ticketPrice;
double transactCredit;

void fileOutput(string result){
    std::ofstream file("TransactionTest.txt", std::ios::app);
    if(file.is_open() ==  true){
        file << result;
        file.close();
    }
}


//Transaction Methods 
//Method: login
void Transaction::login(string UserName, string temp, bool &nameExists, User &currentUser){

    nameExists = 0;

        if (UserName.size() < 15){
			UserName += (string(15 - UserName.size(), ' '));

            if (UserName == temp.substr(0,15)){
                nameExists = 1;
            }

            else {
			nameExists = 0;
		}
		}
       
      if(nameExists == 1){
        	cout << "Welcome User: " <<  UserName << endl;
			currentUser.UserName = temp.substr(0,15);
			currentUser.accountType = temp.substr(16,17);
			currentUser.creditAmount = stod(temp.substr(19,27));
			//currentUser = user;
      }
	}

//Method: logout 
void Transaction::logout(){
    exit(0);
}

//Method: create
void Transaction::create(string userName, string accountType, double credit){

}

//Method: deleteUser
// Delete Note: Used deleteUser instead of delete due to delete being a C++ keyword
void Transaction::deleteUser(string userName){

}

//Method: sell
void Transaction::sell(string eventTitle, int ticketQuantity, double ticketPrice){
    string result;

    cout << "Enter the Event Title: ";
    cin >> eventTitle;

    while (eventTitle.size() <= 25 && eventTitle.size() > 0){
        cout << "Enter the amount of tickets to sell: ";
        cin >> ticketQuantity;  

        if(ticketQuantity == 0 || ticketQuantity > 100){
            cout << "Logging out for either no Quanitity or exceeding Maximum" << endl;
            logout();
        }
        else{
            cout << "Enter the price for each ticket: ";
            cin >> ticketPrice;
        }
        if (ticketPrice > 999.99){
            cout << "Logging out for Exceeding Maximum Price" << endl;
            logout();
        }
        else{
            cout << "Inputs were all Successful, You can now sell tickets for the event" << endl;
            result = eventTitle + to_string(ticketQuantity) + to_string(ticketPrice);
            fileOutput(result);
            logout();
        }   
    }
    cout << "Length of Event exceeded maximum length" << endl;
    logout();
}




//Method: buy
void Transaction::buy(string eventname, string sellername, int ticketQuantity){
    string confirm;
    string result;
    
    cout << "Enter the Title of the Event: ";
    cin >> eventname;


    while (eventname.size() > 0 && eventname.size() < 25){
        cout << "Enter the Username of the Seller: ";
        cin >> sellername;
        
//Seller Stuff
    if(sellername.size() == 0 || sellername.size() > 15){
         cout << "Invalid Seller. Logging Out " << endl;
         logout();
        }
    else{
       cout << "Enter the amount of Tickets: ";
       cin >> ticketQuantity;
    }
        
//Ticket Stuff
    if(ticketQuantity == 0 || ticketQuantity > 4){
        cout << "Invalid Amount of Tickets. Logging Out " << endl;
        logout();
    }
    else{
        cout << "Do You confirm the transaction [y/n]: ";
        cin >> confirm;
    }

        if(confirm == "y"){
            cout << "Transaction Completed. Logging Out " << endl;
            result = eventname + sellername + to_string(ticketQuantity);
            fileOutput(result);
            logout();
        }

        else if (confirm == "n"){
            cout << "Transaction Cancelled. Logging Out " << endl;
            logout();
        }
}
        cout << "Sorry that was an Invalid event: Logging Out " << endl;
        logout();
}

//Method: refund
void Transaction::refund(User UserAccount /*should be using User object*/){
	string transactionresult;
	string buyerName; //Will become User objects in future.
	string sellerName; //Will become User objects in future.
	double creditTransfer; 
	//TODO: CHECK USERS PRIVELEGE (can be done later) 
	if (UserAccount.getAccountType() == "AA") {
		//Continue refund.
		//Prompt user for buyer username
		cout << "Please enter the buyers username: ";
		cin >> buyerName;
		//TODO: Check valid buyer username format
		if (buyerName.size() <= 15 && buyerName.size() >= 0){
			//Continue Transaction
			//TODO: Check if buyer username exists
			//Prompt user for seller username
			cout << endl;
			cout << "Please enter the sellers username: ";
			cin >> sellerName;
			//TODO: Check valid seller username format
			if (sellerName.size() <= 15 && sellerName.size() >= 0){
				//Continue Transaction
				//TODO: Check if seller username exists
				//Prompt user for amount of credit
				cout << endl;
				cout << "Please enter the credit to refund: ";
				cin >> creditTransfer;
				//TODO: Check valid credit entry
				if (creditTransfer >= 0.00 && creditTransfer <= 999999.99 && creditTransfer == ((double) creditTransfer)){
				//Continue Transaction
				//TODO: Check if entered credit amount can be removed from the sellers account.
				//TODO: Check if entered credit amount causes buyers credit to exceed maximum.
				//TODO: Update buyer and seller accounts
				//TODO: Output to the daily transaction file.
			} else {
				//End Transaction
			}
			
			
			} else {
				// End transaction
			}
		} else {
			//End Transaction
		}
	} else {
		//End Transaction
		cout << "Only users with admin priveleges can make refunds." << endl;
	}
	
}

//Method: addCredit
void Transaction::addCredit(){
	string inputAccount;
	double creditTransfer;
	//TODO: Check users privelege (Can be done later)
	//TODO: Check if recieverAccount exists
	//TODO: Check if sufficient credits to be transfered.
	
	//TODO:
}