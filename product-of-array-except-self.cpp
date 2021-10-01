#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // here int 32 means product will be the intger
        vector<int> output;
        int p=1;
        for(int i=0;i<nums.size();i++)
        {
            p=p*nums[i];
            output.push_back(p);
        }
        p=nums[nums.size()-1];
        output[nums.size()-1]=output[nums.size()-2];
        for(int i=nums.size()-2;i>0;i--)
        {
           
            output[i]=p*output[i-1];
            p=p*nums[i];
        }
    output[0]=p;
    return output;
    }
};
