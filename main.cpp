//Kellie Henderson restaurant structure style
/*
created on 10/2/2019
Dr. Tyson McMillan
Tarrant County Community College
The purpose of the assignment is to create a menu where the user can add or delete items while it keeps a running total of items sold and the price of the item. 
A reciept is generated at the end of the program.

skills:
how to include files and which header files are needed.
Vectors, pushback, do-while loops, for loops, placement of voids, where to include most of your work, how to add color.


*/


#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<unistd.h>
#include<fstream>
#include "Input_Validation_Extended.h"
using namespace std;

struct MenuItem
{
  string name;
  double itemCost;
  string desc;
  char addLetter;
  char removeLetter;
  int count; //how many of that item did you order
};

//function definition

void populateMenu(vector<MenuItem> &entireMenu)
{
   string color = "\x1b[" + to_string(32) + ";"+to_string(99)+"m";
string reset = "\x1b[0m";
//put some default values in our Menu
const int numItems = 7;
MenuItem Item1;// Item1 is data type MenuItem
MenuItem Item2;
MenuItem Item3;
MenuItem Item4;// Item1 is data type MenuItem
MenuItem Item5;
MenuItem Item6;
MenuItem Item7;// Item1 is data type MenuItem

entireMenu.push_back(Item1);//add to the end of the list the Item1
entireMenu.push_back(Item2);//add to the end of the list the Item2
entireMenu.push_back(Item3);//add to the end of the list the Item3
entireMenu.push_back(Item4);//add to the end of the list the Item1
entireMenu.push_back(Item5);//add to the end of the list the Item2
entireMenu.push_back(Item6);
entireMenu.push_back(Item7);

vector<string>defaultMenuNames = { 
" Dr_T's Green Tea", 
"   DIABLO Burger", 
"    The Big Chick",
" Truffle Fries",
"  The Cobb - Cobb", 
"TinasTwrknTacos",
" Lulu's Lemon Pie" };
vector<char> defaultAddLetters = {'A','B','C','D','E','F','G'};
vector<char> defaultRemoveLetters = {'a', 'b', 'c','d', 'e', 'f', 'g'};
for(int i = 0; i < numItems; i++)
  {
      // add each item to the default list efficiently 
      entireMenu[i].name = defaultMenuNames[i];
      entireMenu[i].addLetter = defaultAddLetters[i];
      entireMenu[i].removeLetter = defaultRemoveLetters[i];
      entireMenu[i].count = 0;
      entireMenu[i].desc = "Delicious"; // set all defaults desc to "delicious"
  }   
  entireMenu[0].itemCost = 3.75;
  entireMenu[1].itemCost = 9.50;
  entireMenu[2].itemCost = 7.99;
  entireMenu[3].itemCost = 8.99;
  entireMenu[4].itemCost = 9.99;
  entireMenu[5].itemCost = 6.99;
  entireMenu[6].itemCost = 8.99;

}
void printReciept(vector<MenuItem> &m, double s)
{
  string color = "\x1b[" + to_string(32) + ";"+to_string(99)+"m";
string reset = "\x1b[0m";
  // define above showMenu, because show menu calls it. 
  double totalDue = 0.0;
  double tip = 0.0;
  double tax = 1.0825;
  int decision = 0;
  double tender = 0.0;
  double change = 0.0;
  ofstream myfile;
  myfile.open ("receipt.txt");
    myfile << fixed << setprecision(2) << "$" << s << endl;

  string cc = "";
cout << "Subtotal: $" << s  << endl;
cout << "Fort Worth Tax: $" << ((s/100)*8.25) << endl;
cout << "Suggested  tip 20%: $" << (s*.20) << endl;
//cout << "\nPlease " ;
cout << "\nHow much would you like to tip?" << endl;
tip = validateDouble(tip);
totalDue = (s + tax + tip);
cout << color << "Total Due: $" << totalDue << reset << endl;
// accept a tip amount from the user
do 
{
cout << "How would you like to pay? (press 1 for Cash, 2 for credit.)" << endl;
decision = validateInt(decision);
cout << "\n You have opted to pay with a credit card.";
  cout  << "\nPlease enter your credit card information:" << endl;
  cc = validateString(cc);
}while(decision !=1 && decision <= 2);

if(decision == 1) // cash
  {
    // enter how much cash tender the guest gave you.
    cout << "\nYou have opted to pay cash." << endl;
    do
    {
    cout << "\nPlease enter the amount you have: \n$" ; 
    tender= validateDouble(tender);
    if(tender < totalDue)
    {
       cout << "Insufficient amount; Please try again."<< endl; 
    }
        if(tender > totalDue)
        {
          change = tender - totalDue;
          cout << "Change due to guest is: $ " << change << endl;

        }
    }while(tender < totalDue);
  }
  else if (decision == 2) // credit card time
 {
  
  sleep(3);
  cout << "\nApproved. Thank you for eating at Bob's!" ;
 }
 else
 {
   cout << "\nInvalid Input" << endl;
 }


 

cout << "\n"<< "\n" << endl;
cout << "\n \t\t \t \t \tBob's Burger's Reciept" << endl;
myfile << "\n \t\t \t  Bob's Burger's Reciept" << endl;
cout << "\n_______________________________________________________"<< endl;
myfile << "\n_______________________________________________________"<< endl;
cout  << "\t \t \t        \nItemized COPY" << endl;
myfile  << "\t \t \t      \nItemized COPY" << endl;
cout << "\n" << endl;
myfile << "\n" << endl;
for(int i = 0; i < m.size(); i++)
{
// print on the reciept if count is greater than zero.
  if(m[i].count > 0)
  {
    cout << m[i].addLetter << ": " << setw(19)
    << m[i].name << setw(10) 
    << "(@" << m[i].count << ")"<< setw(10) 
    << "$" << m[i].itemCost << setw (10) 
    << (m[i].count*m[i].itemCost) << endl;
    myfile << m[i].addLetter << ": " << setw(19)
    << m[i].name << setw(10) 
    << "(@" << m[i].count << ")"<< setw(10) 
    << "$" << m[i].itemCost << setw (10) 
    << (m[i].count*m[i].itemCost) << endl;
  }
}
cout << "\n_______________________________________________________" << endl;
myfile << "\n_______________________________________________________" << endl;
  cout << "\nSubtotal: $" << s 
       << "\nFort Worth Tax(8.25%): $" << tax 
       << "\nTip: $" << tip << "\nTotal Due: $" 
       << totalDue << "\nTender" << endl;
  myfile << "\nSubtotal: $" << s << "\nFort Worth Tax(8.25%): $" 
         << tax << "\nTip: $" << tip << "\nTotal Due: $" 
         << totalDue << endl;
cout << "\n" << "\n"<< endl;
myfile << "\n" << "\n"<< endl;
cout << "\n_______________________________________________________" << endl;
myfile << "\n_______________________________________________________" << endl;
if(decision == 1) //cash payment
  {
      cout << "Tender Amount $" << tender << endl; 
      myfile << "Tender Amount $" << tender << endl; 
      cout << "Change $" << change << endl; 
      myfile << "Tender Amount $" << tender << endl; 
      myfile << "Change $" << change << endl; 
  }
  else
  {
    cout << "Credit Card Status: APPROVED" << endl; 
  }


  myfile << "_______________RECIEPT - Bob's Burger's____________________" << endl;
  myfile.close(); //close the file after printing

}




void showMenu(vector<MenuItem> &m)
{
cout << fixed << setprecision(2);
cout << "   \t  \t    \t    \t   \t   Bob's Burger's" << endl;
cout << "Add \t \tName \t  \t \t Cost \t \tRemove  \t Count \t   \tDescription" << endl;
for(int i = 0; i < m.size(); i++)
  {
      cout << m[i].addLetter << ": " << setw(19)
      << m[i].name << setw(10) << "$ " 
      << m[i].itemCost << setw(10) 
      << m[i].removeLetter << ")" << setw(10) 
      << m[i].count << setw(19) << m[i].desc << endl;
  } 
}


void acceptOrder(vector<MenuItem> &m)
{
char option = '\0'; // user=selected menu item
double subtotal = 0.0;

//double tax = 0.0;
//double total = 0.0;
do
{
cout << "\nPlease make your selection from the above menu or enter x to exit: ";
cin >> option;
for(int i = 0; i < m.size(); i++)
  {
    if(option == m[i].addLetter)
    {
      cout << m[i].addLetter << " has been selected." << endl;
      m[i].count++; // increment count by one
      cout << "\033[2J\033[1;1H";
      // m[i].itemCost++;
      cout << "\n1 UP on " << m[i].name << endl;
      subtotal += m[i].itemCost; // increment the subtotal by the cost of the item.
      showMenu(m);
      cout << "\n Subtotal: $" << subtotal << endl;
    }
    else if(option == m[i].removeLetter)
    {
      cout << "\nRemove Item: " <<"'" << m[i].removeLetter << "'" << " selected.";
      if(m[i].count > 0)// subtract if and only if the count is > 0
      {
        m[i].count --; // decrement the count by one.
        cout << "\033[2J\033[1;1H" ;
        cout <<  "\n 1 Down on " << m[i].name << endl;
         subtotal -= m[i].itemCost; // increment the subtotal by the cost of the item.
      showMenu(m);
      cout << "\n Subtotal: $" << subtotal << endl;
      }
    else // tell the user why you blocked item removal
    {
      cout << "\nCAPITAL LETTERS TO ADD ITEMS, lowercase letters remove items: "
      << m[i].name << endl;
    }
    }
     else if(option != m[i].removeLetter && 
            option != m[i].addLetter && 
            option != 'x' &&
            option != 'X')
      {
        if (i == 0)
        {
        cout << "\nInvalid input ("<< option << ") Please try again." << endl;
      }

      }
  }

}
while(option != 'x' && option != 'X');
cout << "\nThank you for ordering with us. \nPlease take your reciept and don't forget to tip your server." << endl;
printReciept(m, subtotal);
}

int main() 
{
vector<MenuItem> wholeMenu;// name is wholeMenu
string decision = " ";
populateMenu(wholeMenu); //  put some default values in the menu
do
{
showMenu(wholeMenu);
acceptOrder(wholeMenu);
cout << "\n Would you like to order again? Enter \"exit\" to complete your order. (No adjustments or substitutions at this time.) " << endl;
cin >> decision;
if (decision != "exit")
{
  cout << "\033[2J\033[1;1H" ;
  cout << "\nWelcome!" << endl;
    for(int i = 0; i<wholeMenu.size(); i++)
    {wholeMenu[i].count = 0;}
    
}

}while(decision !="exit");
cout << "\n Come back soon!" << endl;

  return 0;
}
