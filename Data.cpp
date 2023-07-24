#include "Data.h"

Data::Data(const string& em, const string& p, const string& F, const string& L, vector< map<string, set<string>>> &s)
        :email(em), password(p), Fname(F), Lname(L), stays(s)
{
}

string Data::get_password() const{ return password; }

void Data::update_stay(map<string, set<string>>& new_stay)
{
        stays.push_back(new_stay);
}

void Data::show_stay() const
{
        cout << "+++++++++++++++ Stay info ++++++++++++++++++" << endl;
        for(int i=0; i<stays.size(); i++)
        {
                for(const auto& map_itr: stays[i])
                {
                        cout << setw(20) << map_itr.first << " "; 
                        for(const auto& set_itr: map_itr.second)
                        {
                                cout << set_itr << " ";
                        }//set
                        
                }//map
        }//vector
        cout << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
