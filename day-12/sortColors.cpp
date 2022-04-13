class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int st = 0;
        int en = nums.size() - 1;
        int mid = 0;

        while (mid <= en)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid++], nums[st++]);
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[en--]);
            }
            else
            {
                mid++;
            }
        }
    }
};