#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

class Data
{
        public:
                Data(const string& em, const string& p, const string& F, const string& L, vector< map<string, set<string>>> &s);
                void update_stay(map<string, set<string>>& new_stay);
                void show_stay() const;
                string get_password() const;
        private:
                string email;
                string password;
                string Fname;
                string Lname;
                vector< map<string, set<string>>> stays;
                // January <1, 2, 3>
};

#endif
