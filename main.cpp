#include <iostream>
#include "current_account.h"
#include "mortage_account.h"
// #include "user_details.txt"
// #include "admin_login.txt"
// #include <string>
// #include <map>
// #include <cmath>

int main()
{
      user_details user;
      Mortgage_Account admin;
  bool isUserLoggedIn = user.Admin_login(); // Assume there's a login function in user_details class
  while (isUserLoggedIn) {
      user.setuserdetails();
      user.eligibilty();
      user.saveMortgageAmount();
      admin.MonthlyInstallment();
      char response;
      cout << "Do you want to continue logged in? (Y/N): ";
      cin >> response;

      if (response == 'N') {
          cout << "Logging out..." << endl;
         isUserLoggedIn = false; // Update flag to indicate user is not logged in
      } else if (response != 'Y') {
          cout << "Invalid input. Please try again." << endl;
      }
  }
  admin.MonthlyInstallment();

 cout << "Logged out successfully." << endl;

    return 0;
}