#include "Database.h"
#include "Data.h"
Database::Database()
{
        vector< map<string, set<string>>> s;
        Data *d = new Data("a123","123","F123","L123",s);
        database["a123"]=d;

        Data *d2= new Data("Nicole@email","Martinez123","Nicole","Martinez",s);
        database["Nicole@email"]=d2;
}

Database::~Database()
{
        for(auto it=database.begin(); it!=database.end(); it++)
        {
                delete it->second;
        }
}


string Database::AccessPassword(const string& email)
{
        string pass;
        Data *data;
        try
        {
                data = database[email];
                if(data!=nullptr)
                    pass  = data->get_password();
        }catch(...){
                cerr << "Account not found" << endl;
                throw;
        }

        return pass;
}

int Database::User_auth(const string& user_email, const string& user_password)
{
        try
        {
                string pass = AccessPassword(user_email);
                if(pass!=user_password)
                {
                        cout << "Auth failed." << endl;
                        return 1;
                }
                 else
                 {
                        cout << "Welcome back " << user_email << "!" << endl;
                        return 0;
                 }
        }catch(...)
        {
                throw;
        }
        return 0;
}
tuple<string, int> Database::User_login()
{
        string email, pass;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter you password: ";
        cin >> pass;
        cout << endl;
        int ret;

        try 
        {
                ret =  User_auth(email, pass);
        }catch(...){
                throw;
        }
        tuple<string, int> mytuple (email,ret);   
        return mytuple;

}

void Database::Sign_up()
{
        string email, pass, F, L;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter you password: ";
        cin >> pass;
        cout << "Enter your first name: ";
        cin >> F;
        cout << "Enter your last name: ";
        cin >> L;

        vector< map<string, set<string>>> s;
        try
        {
                //Database *db = new Database(email,pass,F,L,s);
                cout << "Your accout has created!" << endl;
        }catch(...){
                throw;
        }
        cout << "You can now log in!" << endl << endl;
}
void Database::Book(string& email, map<string, set<string>> &new_stay)
{
       database[email]->update_stay(new_stay);

}
void Database::Record(string& email)
{
        database[email]->show_stay();
}

