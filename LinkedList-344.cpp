// My Realization

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        char temp;
        int length = s.size();
        int count = length / 2; // 交换次数
        for (int i = 0; i < count; ++i)
        {
            temp = s[i];
            s[i] = s[length - 1 - i];
            s[length - 1 - i] = temp;
        }
    }
};

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        char temp;
        int length = s.size();
        int count = length / 2; // 交换次数
        for (int i = 0, j = length - 1; i < count; ++i, --j)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};