/**
 * GOALS:
 *       Review for-loop, cout, endl
 *       create a program that will only allows a user to login who knows a correct username
 *          and a password.
 *          - nested if statement
 *          - command line input
 * STEPS:
 *       1. Create variables that hold your correct username and your correct password.
 *          - note for myself: show them how to create a bigger database.
 *       2. Output a message to a user. ex) "Type in your username"
 *       3. Wait for a user to type a username.
 *       4. Output a message to a user. ex) "Type in your password"
 *       5. Wait for a user to type a password.
 *       6. Verify the username with your database.
 *              7. Verify the passworde with your database.
 *              8. Which case authenticatoin fails?
 **/

#include <iostream>
using namespace std;

int main()
{
        string my_username = "user1";
        string my_password = "password123";

        string input_username;
        string input_password;
        
        cout << "Type in your username below." << endl;
        cin >> input_username;
        
        cout << "Type in your password below." << endl;
        cin >> input_password;
        
        if( input_username == my_username )
        {
            if( input_password == my_password )
            {
                    cout << "++++++++++++++++++++++++++" << endl;
                    cout << "   Welcome back " << username << "!" << endl;
                    cout << "++++++++++++++++++++++++++" << endl;
            }
            else
            {
                    cout << "+++++++++++++++++++++++++++++++" << endl;
                    cout << " You typed a wrong password..." << endl;
                    cout << "   Authentication failed..." << endl;
                    cout << "+++++++++++++++++++++++++++++++" << endl;
            }
        }
        else
        {
                cout << "+++++++++++++++++++++++++++++++" << endl;
                cout << "       User not found..." << endl;
                cout << "     Authentication failed..." << endl;
                cout << "+++++++++++++++++++++++++++++++" << endl;
        }


        return 0;
}
