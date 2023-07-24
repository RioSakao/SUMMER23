#include "Data.h"
#include "Database.h"
#include <string>
#include <bits/stdc++.h>

void Welcome();
int Options(Database &db, string& option, string &email);
int Management_options();
int dayNumber(int day, int month, int year);
int numberOfDays (int monthNumber, int year);
void Calendar(string month, int year);
void Book(Database &db, string& email);
void Record(Database &db, string& email);
void Management_system(Database &db, int option, string& email);

int main()
{
        string email;
        Welcome();
        string option;
        cin >> option;
        Database db;
        int ret = Options(db, option, email);
        if(ret==3) return 1;
        //only user who has logged in can go further.
        int management_option = Management_options();
        Management_system(db, management_option, email);

        return 0;
}

void Welcome()
{
        cout << "Welcome to the Hotel Chico! How can we help you today? " << endl;
        cout << "1. Log in." << endl;
        //cout << "2. Sign up if you don’t have an account." << endl;
        cout << "3. Exit." << endl;
}


int Options(Database &db, string& option, string& email)
{
        int Options_ret, ret;
        int cases = stoi(option);
        tuple<string, int> mytuple;
        switch(cases)
        {
                case 1:
                        Options_ret=1;
                        mytuple = db.User_login();
                        email = get<0>(mytuple);
                        if(get<1>(mytuple) == 1)
                                Options_ret=3;
                        break;
                /**
                case 2:
                        db.Sign_up();
                        db.User_login();
                        break;
                **/
                case 3:
                        Options_ret=3;
                        break;
        }
        return Options_ret;

}
int dayNumber(int day, int month, int year)
{

        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                           4, 6, 2, 4 };
        year -= month < 3;
        return ( year + year/4 - year/100 +
                 year/400 + t[month-1] + day) % 7;
}
int numberOfDays (int monthNumber, int year)
{
        switch(monthNumber)
        {
                case 0:
                        return (31);
                        break;
                case 1:
                        if (year % 400 == 0 ||
                            (year % 4 == 0 && year % 100 != 0))
                        {
                                return (29);
                                break;
                        }
                        else
                                return (28);
                        break;
                case 2:
                        return (31);
                        break;
                case 3:
                        return (30);
                        break;
                case 4:
                        return (31);
                        break;
                case 5:
                        return (30);
                        break;
                case 6:
                        return (31);
                        break;
                case 7:
                        return (31);
                        break;
                case 8:
                        return (30);
                        break;
                case 9:
                        return (31);
                        break;
                case 10:
                        return (30);
                        break;
                case 11:
                        return (31);
                        break;
        }
        return 0;
}

void Calendar(string month, int year)
{
        int int_month;
        if(month=="January")
                int_month=0;
        else if(month=="Feburary")
                int_month=1;
        else if(month=="March")
                int_month=2;
        else if(month=="April")
                int_month=3;
        else if(month=="May")
                int_month=4;
        else if(month=="June")
                int_month=5;
        else if(month=="July")
                int_month=6;
        else if(month=="August")
                int_month=7;
        else if(month=="September")
                int_month=8;
        else if(month=="October")
                int_month=9;
        else if(month=="November")
                int_month=10;
        else
                int_month=11;


        int days;
        days = numberOfDays(int_month, year);
        cout << "         Calendar - " <<  year << endl;
        int current = dayNumber (1, 1, year);
        cout <<  "-------------" << month  << "--------------" << endl;
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat " << endl;
        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            cout << setw(5) << j;
            if (++k > 6)
            {
                k = 0;
                cout << endl;
            }
        }


}
void Book(Database &db, string& email)
{
        string days, month, date;
        //cout << "How many days would you like to stay?" << endl;
        //cin >> days;
        cout << "Which month would you like to stay? (ex. January)" << endl;
        cin >> month;
        Calendar(month, 2023);
        cout << endl;
        cout << "Which date would you like to stay? (ex. 1, 2, 3)" << endl;
        cin >> date;
        set<string> s;
        stringstream ss(date);
        while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                s.insert(substr);
        }
        map<string, set<string>> new_stay;
        new_stay[month] = s;
        db.Book(email,new_stay);
}

void Record(Database &db, string& email)
{
        db.Record(email);
}
int Management_options()
{
        cout << "How can I help you today?" << endl;
        cout << "1. Book a room." << endl;
        cout << "2. Check a customer record." << endl;
        string input;
        cin >> input;
        int ret = stoi(input);
        return ret;
}
void Management_system(Database &db,int option, string& email)
{
        switch(option)
        {
                case 1:
                        Book(db, email);
                        cout << "You have successfully booked your stay!" << endl;
                        Record(db,email);
                        break;
                case 2:
                        Record(db, email);
                        break;
        }
}
