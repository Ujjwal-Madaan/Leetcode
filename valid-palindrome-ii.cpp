#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        int flag=1;
        int flag1=1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
             i++;
             j--;   
            }
            else if(s[i]!=s[j] && flag==1)
            {
                  int a=i+1;
                  int b=j;
                  int check1=1;
                  while(a<=b)
                  {
                      if(s[a]!=s[b])
                      {
                          check1=0;
                          break;
                      }
                      a++;
                      b--;
                  }
                int c=i;
                int d=j-1;
                int check2=1;
                while(c<=d)
                  {
                      if(s[c]!=s[d])
                      {
                          check2=0;
                          break;
                      }
                c++;
                d--;    
                    
                }
                //cout<<"che"<<check1<<" "<<check2<<endl;
                return(check1 || check2);
             }
            else if(s[i]!=s[j])
            {
                flag1=0;
                break;
            }
        }
        if(flag1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
