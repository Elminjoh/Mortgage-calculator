#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <ios>
#include <sstream> // Include for stringstream
#include <vector>
#include <stdexcept>
#include <random>
#include <unordered_set>
#include <mutex>
#include <sstream>
#include <algorithm>
#include <ctime>
#include "mortage_account.h"
using namespace std;

void Mortgage_Account::MonthlyInstallment()
{
    const string filePath = "user_mortgage.txt";
    ifstream infile(filePath);

    if (!infile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    string line;
    while (getline(infile, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        double totalAmountOwned = stod(tokens[1]);
        cout << "Amount loaned: "<< totalAmountOwned << endl;

        double rate = pow(1 + 0.09/1,1*25); 
        double FinalAmount = totalAmountOwned * rate;
        cout << "Interest Percentage Rate is : 9%" << endl;
        cout << "Length of Mortgage: 25 years" << endl;
        cout << "Total amount to pay over 25 years: "<< FinalAmount << endl;

        char choice;
        do 
        {
            cout << "Would you like to proceed with the Mortgage?" << endl;
            cout << "'y' = Yes" << endl;
            cout << "'n' = No" << endl;
            cin >> choice;

            if (choice == 'y')
            {
                cout << "Mortgage accepted and should be fully set up within the next 3-5 business days. Thank you for applying." << endl;
                break;
            }
            else if (choice == 'n')
            {
                cout << "Thank You, Goodbye" << endl;
                break;
            }
            else 
            {
                cout << "Invalid Input. Try again" << endl;
            }
        } while (choice != 'y');
    }

    infile.close();
}



// void Mortgage_Account::MonthlyInstallment()
// {
//     const string filePath = "user_mortgage.txt";
//     ifstream infile(filePath);

//     if (!infile.is_open())
//     {
//         cout << "Error opening file" << endl;
//         return;
//     }

//     string line;
//     while (getline(infile, line))
//     {
//         stringstream ss(line);
//         string token;
//         vector<string> tokens;

//         while (getline(ss, token, ','))
//         {
//             tokens.push_back(token);
//         }

//         double totalAmountOwned = stod(tokens[1]);
//         cout << "Amount loaned: "<< totalAmountOwned << endl;

//         double rate = pow(1 + 0.09/1,1*25); 
//         double FinalAmount = totalAmountOwned * rate;
//         cout << "Interest Percentage Rate is : 9%" << endl;
//         cout << "Length of Mortgage: 25 years" << endl;
//         cout << "Total amount to pay over 25 years: "<< FinalAmount << endl;

//         char choice;
//         do 
//         {
//             cout << "Would you like to proceed with the Mortgage?" << endl;
//             cout << "'y' = Yes" << endl;
//             cout << "'n' = No" << endl;
//             cin >> choice;

//             if (choice == 'y')
//             {
//                 cout << "Mortgage accepted and should be fully set up within the next 3-5 business days. Thank you for applying." << endl;
//                 break;
//             }
//             else if (choice == 'n')
//             {
//                 cout << "Thank You, Goodbye" << endl;
//                 break;
//             }
//             else 
//             {
//                 cout << "Invalid Input. Try again" << endl;
//             }
//         } while (choice != 'y');
//     }

//     infile.close();
// }



