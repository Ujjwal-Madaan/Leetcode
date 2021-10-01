#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string calculate(string s1,string s2)
    {
        string result="";
        for(int i=0,j=0;i<s1.size() && j<s2.size();i++,j++)
        {
            if(s1[i]!=s2[j])
            {
                break;
            }
         result=result+s1[i];
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        // string s=strs[0];
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++)
        {
          prefix=calculate(prefix,strs[i]);
        }
    return prefix;
    }
};
