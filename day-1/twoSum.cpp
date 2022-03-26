class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        
        int st = 0;
        int en = nums.size() - 1;
        vector<int> v;
        while(st < en){
            if(nums[st] + nums[en] == target){
                v.push_back(nums[st]);
                v.push_back(nums[en]);
                break;
            }
            
            else if(target > nums[st] + nums[en]) st++;
            
            else en--;
        }
        
        int first;
        for(int i = 0; i < nums.size(); i ++){
            if(v[0] == temp[i]){
                v[0] = i;
                first = i;
                break;
            }
        }
        
        for(int i = 0; i < nums.size(); i ++){
            if(v[1] == temp[i] && i != first) v[1] = i;
        }
        
        return v;
    }
};