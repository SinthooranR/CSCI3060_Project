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
using std::string;
using std::cout;
using std::cin;
using std::endl;

//Method: Transaction
Transaction::Transaction(){

}

string cmd;

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


//Transaction Methods 
//Method: login
void Transaction::login(string UserName, string temp, bool nameExists){

    nameExists = 0;
	for(int i = 0; i < UserName.size() - 1; i++){
        if (UserName[i] == temp[i]){
			nameExists = 1;
		}
        else {
			nameExists = 0;
			break;

    if(UserName == "exit"){
         exit(0);
     }
		}
        
  	}

 

      if(nameExists){
        	cout << "Welcome User: " << UserName << endl;
			cout << "Enter a Cmd (Only 'buy', 'logout', and 'sell' work): ";
            cin >> cmd;
		}

        if(cmd == "buy"){
            buy(eventN, sellerN, ticketQ);
        }

        else if(cmd == "logout"){
           cout << "User " << UserName << " Logging Out " << endl;  
           logout();
        }  

        else if(cmd == "sell"){
           sell(eventN, ticketQ, ticketPrice);
        }  

        else if(cmd == "delete"){
           deleteUser(existUser); 
        }  

        else if(cmd == "create"){  
           create(newUser, accountType, userCredit);
        }  

        else if(cmd == "refund"){
           refund(currUser, sellerN, transactCredit);
      
        }  

        else if(cmd == "addcredit"){ 
           addCredit(transactCredit, existUser);
      
        }  

	}

//Method: logout 
void Transaction::logout(){

    string filename;
    string output;
    
    std::ofstream file;
    file.open(filename.c_str());
    file << output;
    file.close();
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
            logout();
        }   
    }
    cout << "Length of Event exceeded maximum length" << endl;
    logout();
}




//Method: buy
void Transaction::buy(string eventname, string sellername, int ticketQuantity){
    string confirm;
  //Event Stuff (Skeleton Code)
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
void Transaction::refund(string userNameBuy, string userNameSell, double creditAmount){

}

//Method: addCredit
void Transaction::addCredit(double creditAmount, string userName){

}