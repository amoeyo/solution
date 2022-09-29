#include "DPSolution.h"

int maxProfit(vector<int>& prices)
{
    //贪心，从左往右最小值，从右往左最大值
    
    return 0;
}

int lengthOfLIS(vector<int>& nums)
{
    int len = nums.size();
    vector<int> dp(len, 1);
    int max_len = 1;

    for (int i = 1; i < len; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (dp[i] > max_len)
            max_len = dp[i];
    }
    return max_len;
}

int minDistance(string word1, string word2)
{
    
    int word_len1 = word1.size();
    int word_len2 = word2.size();
    vector<vector<int>> dp(word_len1 + 1, vector<int>(word_len2 + 1, 0));
    for (int i = 0; i <= word_len1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= word_len2; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= word_len1; i++)
    {
               for (int j = 1; j <= word_len2; j++)
        {
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            else
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
    for (int i = 0; i <= word_len1; i++)
    {
        for (int j = 0; j <= word_len2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[word_len1][word_len2];
}

int trap(vector<int>& height)
{
    int n = height.size();
    vector<int> left_highest;
    vector<int> right_highest;
    left_highest.assign(height.begin(), height.end());
    right_highest.assign(height.begin(), height.end());

    int maxH = height[0];
    for (int i = 1; i < n; i++)
    {
        if (height[i] > maxH)
        {
            maxH = height[i];
        }
        left_highest[i] = maxH;
    }

    maxH = height[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (height[i] > maxH)
        {
            maxH = height[i];
        }
        right_highest[i] = maxH;
    }

    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int high = min(left_highest[i], right_highest[i]);
        if (high > height[i])
        {
            res += high - height[i];
        }
    }

    return res;
}

int cuttingRope(int n)
{
    return 0;
}

/*

int cal_num(vector<int>& coins_num)
{
    int sum = 0;
    auto it = coins_num.begin();
    while (it != coins_num.end())
    {
        sum += *it;
        it++;
    }
    return sum;
}

void change(vector<int>& coins, int& sum, int& min_cnt, vector<int>& coins_num, int amount)
{
    if (sum > amount) return;
    if (sum == amount)
    {
        int cnt = cal_num(coins_num);
        if (cnt < min_cnt)
        {
            min_cnt = cnt;
        }
        return;
    }
    for (int i = 0; i < coins.size(); i++)
    {
        sum += coins[i];
        coins_num[i]++;
        change(coins, sum, min_cnt, coins_num, amount);
        coins_num[i]--;
        sum -= coins[i];
    }
    return;
}
*/

int coinChange(vector<int>& coins, int amount)
{
    int sum = 0;
    int type_num = coins.size();
    vector<int> dp(amount + 1, MAX_UNIT);
    dp[0] = 0;
    //vector<int> coins_num(coins.size(), 0);
    //change(coins, sum, min_cnt, coins_num, amount);
    
    //dp[S] = min{ dp[S - c0], dp[S - c1], dp[S - c2], dp[S - c3]} + 1
    for (int i = 1; i <= amount; i++)
    {
        int min_temp_cnt = MAX_UNIT;
        for (int j = 0; j < type_num; j++)
        {
            if (i >= coins[j])
            {
                if (dp[i - coins[j]] < min_temp_cnt)
                {
                    min_temp_cnt = dp[i - coins[j]];
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        
    }


    return (dp[amount] < MAX_UNIT)? dp[amount]: -1;
}

//动态规划的思路比较容易理解
//res[n] = (res[p])res[q]
//写得稍微有点麻烦
//回溯思路，记录左右括号数，递归退出条件为left < right和left, right > n
//优先放置左括号再放置右括号
vector<string> generateParenthesis(int n)
{
    vector<vector<string>> res;
    res.resize(n + 1);

    res[1].push_back("()");

    for (int length = 2; length <= n; length++)
    {
        //res[n] = (res[left])res[length - 1 - left]
        for (int left = 0; left <= length - 1; left++)
        {
            if (left == 0)
            {
                string newStr = "()";
                int num = res[length - 1].size();
                for (int i = 0; i < num; i++)
                {
                    string str = newStr + res[length - 1][i];
                    res[length].push_back(str);
                }
            }
            else
            {
                string newStr = "(";
                int leftNum = res[left].size();
                for (int leftIndex = 0; leftIndex < leftNum; leftIndex++)
                {
                    string leftStr = newStr + res[left][leftIndex];
                    leftStr += ")";
                    int rightNum = res[length - 1 - left].size();
                    if (rightNum == 0)
                    {
                        res[length].push_back(leftStr);
                    }
                    for (int rightIndex = 0; rightIndex < rightNum; rightIndex++)
                    {
                        string str = leftStr + res[length - 1 - left][rightIndex];
                        res[length].push_back(str);
                    }
                }
            }

        }
    }
    return res[n];

}

//text[i] != text[j] dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
//text[i] == text[j] dp[i][j] = dp[i - 1][j - 1] + 1
//text1[i] != text2[j] 
int longestCommonSubsequence(string text1, string text2)
{
    int textLen1 = text1.length();
    int textLen2 = text2.length();
    vector<vector<int>> dp(textLen2 + 1, vector<int>(textLen1 + 1, 0));
    for (int row = 1; row <= textLen2; row++)
    {
        for (int col = 1; col <= textLen1; col++)
        {
            //int maxL = max(dp[row - 1][col], dp[row][col - 1]);
            //int maxL = dp[row - 1][col];

            if (text2[row - 1] == text1[col - 1])
            {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            }
            else
            {
                dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
            }

        }
    }
    return dp[textLen2][textLen1];
}

// dp[i][j]表示以matrix[i][j]为右下角的最大正方形大小
// dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
int maximalSquare(vector<vector<char>>& matrix)
{
    return 0;
}