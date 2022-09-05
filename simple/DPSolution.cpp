#include "DPSolution.h"

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