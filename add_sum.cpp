/** 
 * Referring to the lines from 59 to 75 in main.py of Day3-Python day2 by Sabas
 *
 * GOALS:
 *      1. C++ way of for-loop
 *      2. Get used to the syntax
 * STEPS: 
 *      1. make two containers that hold integers.
 *      2. use if statement to compare the size.
 *      3. run for loop to the containers that you created above.
 *          - add integers that share the same index in the containers inside of for-loop
 *          - print the sum of two integers.
 **/

#include <iostream>
#include <vector>
using namespace std;

void fortnite(int length, vector<int> listA, vector<int> listB)
{
        //STEP 3 
        //start at index 0; do loop while index is less than 5; increment index by 1
        int result;
        for(int i=0; i<length; i++)
        {
                result= listA[i] + listB[i];
                cout << result << endl;
        }
}

int main()
{
        //STEP 1
        vector<int> listA = {1, 2, 3, 4, 5};
        vector<int> listB = {1, 2, 3, 4, 5};

        //STEP 2
        if(listA.size() == listB.size())
        {
                int length = listA.size();
                fortnite(length, listA, listB);
        }
        else
        {
                cout << "Size in not the same" << endl;
        }
        
        return 0;
}
