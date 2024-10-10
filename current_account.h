 #include <string>
 #include <iostream>
 #include <unordered_set>
 using namespace std;

class user_details
{
    private:
        long int UserID;
        string UserFirstName;
        string UserSurName;
        long long int UserPhoneNumber;
        string UserEmail;
        string UserHomeAddress;
    
    public:

        user_details();

        //setter functions
        void setUserID();
        void setUserFirstName();
        void setUserSurName();
        void setUserPhoneNumber();
        void setUserEmail();
        void setUserHomeAddress();
        

        //getter functions
        long int getUserID() const;
        string getUserFirstName() const;
        string getUserSurName() const;
        long int getUserPhoneNumber() const;
        string getUserEmail() const;
        string getUserHomeAddress() const;

        bool Admin_login(); // for admin login to access the program 
        bool SalaryVerification(); // verifies the clients salary via documantation
        bool eligibilty(); // checks if the client is eligable for the mortgage 
        void saveMortgageAmount(); // saves the amount the clients ask for in the user mortgage text file
        void setuserdetails(); // calls all the setters in one function 
        bool validateUserDetails(); // validates the clients details by checking if it matches what is saved in the text file
        
};
