#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    
    {
        int len1 = word1.size();//andx
        int len2 = word2.size();//nsncjk
        string result;
        int p1=0;
        int p2=0;
        while(p1<len1 && p2<len2)
        {
        
            result+=word1[p1];
            p1++;
            result+=word2[p2];
            p2++;
        }
        result+=word1.substr(p1);
        result+=word2.substr(p2);
     
        return result;
    }
};


int main()
{
    string word1;
    string word2;
    cin>>word1>>word2;
    //¹¹½¨ÊµÀý
    Solution sol;
    string str;
    str = sol.mergeAlternately(word1,word2);
    cout<<str<<endl;



}