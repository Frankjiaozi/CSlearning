#include <iostream>
#include <string>
using namespace std;
//word    or
class Solution
{public:
        int strStr(string haystack,string needle)
        {   int flag=-1;

            for(int i=0;i<(int)haystack.size();i++)
            {
                string temp = haystack.substr(i,needle.size());
                if(temp == needle)
                {
                    flag=i;
                    return flag;
                }
 
            }

            return flag;
            
        }


};


int main()
{
    string haystack;
    string needle;
    cin>>haystack>>needle;
    Solution sol;
    int  result;
    result = sol.strStr(haystack,needle);
    cout<<result<<endl;
}