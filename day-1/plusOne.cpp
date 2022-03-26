class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // if the last digit is not 9 simply increment it and  return
        int n = digits.size();

        if (digits[n - 1] != 9)
        {
            digits[n - 1]++;
            return digits;
        }

        digits[n - 1] = 0;
        int carry = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0)
            {
                carry = 0;
                break;
            }
        }

        if (carry == 1)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};