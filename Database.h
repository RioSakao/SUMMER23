#ifndef DATABASE_H
#define DATABASE_H
#include "Data.h"
#include <tuple>

class Database
{
        public:
                Database();
                ~Database();
                string AccessPassword(const string& email);
                int User_auth(const string& user_email, const string& user_password);
                tuple<string, int> User_login();
                void Sign_up();
                void Book(string& email, map<string, set<string>> &new_stay);
                void Record(string& email);
        private:
                map<string, Data* > database;
};

#endif
