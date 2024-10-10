#include "current_account.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ios>
#include <sstream> // Include for stringstream
#include <vector>
#include <stdexcept>
#include <random>
#include <unordered_set>
#include <fstream>
#include <ios>
#include <mutex>
#include <sstream>
#include <algorithm>
#include <ctime>


using namespace std;

 user_details::user_details()
 {
    UserID = 298747;
    UserFirstName = "Felix";
    UserSurName = "Baah";
    UserPhoneNumber = 447931115686;
    UserEmail = "elmi@gmail.com";
    UserHomeAddress = "15 Homstead road,Coventry,England,CO1 NH2";
};


// using the setter function to set the users details
void user_details::setUserID()
{
    long int setUserID;
    while(true)
    {
        try 
        {
            cout << "Mortgage Application Page"<< endl;
            cout << "Which client will you be working with today ? " << endl;
            cout << "Enter client ID number: ";
            cin >> setUserID;

            if(setUserID == 0)
            {
                throw invalid_argument("Invalid input");

            }
            else
            {
                UserID = setUserID;
                cout << "ID number entered succuessfully" << endl;
                break;
            }
  
         }
        catch (const invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << ". Try again. "<< std::endl;
        }
    } 
};


void user_details::setUserFirstName()
{
    
    string setUserFirstName;
    while(true)
    {
        try 
        {
            
            cout << "Enter client first name: " ;
            cin.clear();
            cin >> setUserFirstName;

            if (setUserFirstName.empty())
            {
                throw invalid_argument("Invalid input");
            }
            else 
            {
                UserFirstName = setUserFirstName;
                cout << "Name entered successfully " << endl;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << ". Try again. "<< std::endl;
        }
    };
}
void user_details::setUserSurName()
{
    string setUserSurName;
    while(true)
    {
        try 
        {
            
            cout << "Enter client Surname: ";
            cin >> setUserSurName;

            if (setUserSurName.empty())
            {
                throw invalid_argument("Invalid input");
            }
            else 
            {
                UserSurName = setUserSurName;
                cout << "Surname entered successfully " << endl;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << ". Try again. "<< std::endl;
        }
    };
}
void user_details::setUserPhoneNumber()
{
    long int setuserphonenumber;
    while (true)
    {
        try 
        {
            
            cout << "Enter client Phone Number: ";
            cin.clear();
            cin >> setuserphonenumber;

            if(setuserphonenumber == 0)
            {
                throw invalid_argument("Invalid input");
            }
            else
            {
                UserPhoneNumber = setuserphonenumber;
                cout << "Phone number entered successfully "<< endl;
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what()<< ". Try again." << endl;
        }
    };
    
}
void user_details::setUserEmail()
{
    string setUserEmail;
    string const email = "elmi@gmail.com";

    while (true)
    {
        try 
        {
            
            cout << "Enter client email address: ";
            cin.clear();
            cin >> setUserEmail;

            if(setUserEmail.empty())
            {
                throw invalid_argument ("Invalid input");
            }
            else 
            {
                UserEmail = setUserEmail;
                cout << " Email entered successfully" << endl;
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << ". Try again." << std::endl;
        }
    }; 
}
void user_details::setUserHomeAddress()
{
   string setUserHomeAddress;

   while(true)
   {
        try 
        {
            cout << "Enter client Home Addresss: ";
            cin.clear();
            getline(cin, setUserHomeAddress);

            if (setUserHomeAddress.empty())
            {
                throw invalid_argument ("Invalid input");
            }
            else
            {
                UserHomeAddress = setUserHomeAddress;
                cout << "Home address entered successfully" << endl;
                break;
            }
        }
         catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << ". Try again." << std::endl;
        }
    };
}

// getter functions to get all the values inputted by users

long int user_details::getUserID() const
{
    return UserID;
}

string user_details::getUserFirstName() const
{
    return UserFirstName;
}

string user_details::getUserSurName() const
{
    return UserSurName;
}

long int user_details::getUserPhoneNumber() const
{
    return UserPhoneNumber;
}

string user_details::getUserEmail() const
{
    return UserEmail;
}

string user_details::getUserHomeAddress() const
{
    return UserHomeAddress;
}

// This is the main function for letting Admin log into the system 

bool user_details::Admin_login()
{
    cout << "Welcome to $wift Ca$h Bank \n";
    cout << "Admin Login \n";
    
    string login;
    string password;
    bool isloggedin = false;

    cout << "Enter your login ID: ";
    // cin.ignore();
    cin >> login;

    cout << "Enter your Password: ";
    cin.ignore();
    getline(cin,password);

    const string filePath = "admin_details.txt";
    ifstream inFile(filePath);

    fstream file(filePath, ios::in | ios::out | ios::ate);
    if (file.is_open()){
        streampos fileSize = file.tellg();
        file.seekg(0); // Move to the beginning of the file

        string line;
        streampos currentPosition;

        while (!file.eof()){
            currentPosition = file.tellg();

            getline(file, line);
            stringstream ss(line);
            string token;
            vector<string>tokens;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            
            if (tokens[0] == login && tokens[1] == password) {
                cout << "Login successful. Welcome, " << endl; 
                cout << tokens[2] << endl;
                cout << tokens[3] << endl;
                isloggedin = true;
                break;
            }
        }
    }
    return isloggedin;
}
// function to check clients salary to see 
bool user_details::eligibilty()
{
     int salary;
     int EligabiltyAmount = 1600;
     bool isSalaryVerified;

     cout << "Roughly how much does client earn per month: ";
     cin >> salary;

     isSalaryVerified = SalaryVerification();

     

     if(salary <= EligabiltyAmount)
     {
        cout << "You do not qualify for a mortgage: ";
        return false;
     }
     else
     {
        cout << "You qualify for the mortgage: ";
        return true;
     }

}

void user_details::saveMortgageAmount() {
    string userAmount;
    string enteredID;

    cout << "Enter user ID: ";
    cin >> enteredID;

    const string filePath = "user_mortgage.txt";
    fstream file(filePath, ios::in | ios::out);

    if (file.is_open()) {
        vector<string> lines; // Store all lines in memory
        string line;
        bool userFound = false;

        // Read all lines from the file and find the user's line
        while (getline(file, line)) {
            stringstream ss(line);
            vector<string> tokens;
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            if (!tokens.empty() && tokens[0] == enteredID) {
                userFound = true;
                cout << "Enter the amount the user borrowed in order to save it: ";
                cin.ignore();
                getline(cin, userAmount);
                line = enteredID + "," + userAmount; // Update the line with new data
            }

            lines.push_back(line); // Store the line in memory
        }

        file.clear(); // Clear end-of-file flag for further file operations

        if (!userFound) {
            cout << "User not found" << endl;
        } else {
            file.seekp(0); // Move file pointer to the beginning of the file
            for (const string& updatedLine : lines) {
                file << updatedLine << endl; // Write updated line to the file
            }
            cout << "Amount saved" << endl;
        }

        file.close();
    } else {
        cout << "Error opening file" << endl;
    }
}

bool user_details::SalaryVerification()
{
    char response;
        cout << "Has the client provided a bank statement for the previous months which indicates their salary ? \n";
        cout << "'Y' = Yes \n";
        cout << "'N' = No \n";
        cout << "'C' = Cancel \n";
        cin >> response;
    do 
    {
        if(response == 'Y')
        {
            while(true) {
                char match;
                cout << "Do their bank statements match the salary they mentioned above ? "<< endl;
                cout << "'Y' = Yes \n";
                cout << "'N' =  No \n";
                cout << "'C' = Cancel \n";
                cin >> match;

                if (match == 'Y')
                {
                    cout << "Proceed to mortgage application page \n";
                    return true;
                    break;
                }
                else if(match == 'N') 
                {
                    cout << "Can not apply for mortgage \n";
                    break;
                }
                else if (match == 'C')
                {
                    cout << "Exiting \n";
                    break;
                }
                else 
                {
                    cout << "Invalid input. Try Again \n";
                    continue;
                }
            } 
            break;
        }
        
        

       else if (response == 'N')
        {
            cout << "Can not apply for mortgage \n ";
            break;
        }
        else if (response == 'C')
        {
            cout << "Exiting \n";
            break;
        }
        else 
        {
            cout << "Invalid Input try again \n";
            continue;
        }
    } while (response != 'C');
        
}

void user_details::setuserdetails() {
    setUserID();
    setUserFirstName();
    setUserSurName();
    setUserPhoneNumber();
    setUserEmail();
    setUserHomeAddress();

    // Validate user details
    if (validateUserDetails()) {
        cout << "Client details are valid." << endl;
    } else {
        cout << "Client details are invalid." << endl;
    }
}

bool user_details::validateUserDetails() {
    // Implement validation logic here
    // For example, check if all required fields are filled

    // For demonstration purposes, assume all fields are required
    if (UserID == 0 || UserFirstName.empty() || UserSurName.empty() ||
        UserPhoneNumber == 0 || UserEmail.empty() || UserHomeAddress.empty()) {
        return false; // Return false if any field is empty
    }

    // Additional validation logic can be added as needed

    return true; // Return true if all fields are filled
}
