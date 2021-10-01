class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(),nums.end());
        // vector<int> nums;
        // nums.push_back(num[0]);
        // for(int i=1;i<num.size();i++)
        // {
        //     if(nums.back()!=num[i])
        //     {
        //         nums.push_back(num[i]);
        //     }
        // }
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && (nums[i]==nums[i-1]) )
                continue;
            
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                if((nums[i]+nums[j]+nums[k])==0)
                {
                    
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==result.back()[1])
                    {
                        j++;
                    }
                    while(j<k && nums[k]==result.back()[2])
                    {
                        k--;
                    }
                        
                     
                }
                else if((nums[i]+nums[j]+nums[k])<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
    return result;
    }
};
