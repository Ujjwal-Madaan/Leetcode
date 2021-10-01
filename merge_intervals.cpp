class Solution {
public:
   static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),comp);
        vector<vector<int>> result;
        result.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if (nums[i][0]<=result.back()[1])
            {
                cout<<"hello"<<endl;
                vector<int> temp;
                temp.push_back(result.back()[0]);
                temp.push_back(max(result.back()[1],nums[i][1]));
                result.pop_back();
                result.push_back(temp);
            }
            else
            {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
