#include "SimpleSolution.h"

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> nums_map;
    vector<int> res;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (nums_map.count(nums[i])) {
            res.push_back(i);
            res.push_back(nums_map[nums[i]]);
            break;
        }
        else {
            nums_map[target - nums[i]] = i;
        }
    }
    return res;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> res;

    int rowNum = matrix.size();
    int colNum = matrix[0].size();


    int up_edge = 0;
    int down_edge = rowNum - 1;
    int right_edge = colNum - 1;
    int left_edge = 0;
    while (left_edge <= right_edge && up_edge <= down_edge)
    {
        for (int col = left_edge; col <= right_edge; col++)
        {
            res.push_back(matrix[up_edge][col]);
        }


        for (int row = up_edge + 1; row <= down_edge; row++)
        {
            res.push_back(matrix[row][right_edge]);
        }

        if (up_edge < down_edge && left_edge < right_edge)
        {
            for (int i = right_edge - 1; i >= left_edge; i--)
            {
                res.push_back(matrix[down_edge][i]);
            }

            for (int i = down_edge - 1; i > up_edge; i--)
            {
                res.push_back(matrix[i][left_edge]);
            };
        }
        
        right_edge--;
        down_edge--;
        left_edge++;
        up_edge++;
    }
    return res;
}

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> res;
    int aL = a.size();
    int bL = b.size();
    res.resize(aL + bL);
    int ap = 0, bp = 0, resp = 0;
    while (ap < aL || bp < bL)
    {
        int areal = (ap < aL) ? a[ap] : INF;
        int breal = (bp < bL) ? b[bp] : INF;
        if (areal < breal)
        {
            res[resp] = areal;
            ap++;            
        }
        else
        {
            res[resp] = breal;
            bp++;
        }
        resp++;
    }
    
    return res;

}

void nextPermutation(vector<int>& nums)
{
    int len = nums.size();
    int post = len - 1;
    int pre = post - 1;
    //从后往前找第一个较小的数
    while (pre >= 0)
    {
        if (nums[pre] < nums[post]) break;
        pre--;
        post--;
    }
    if (pre < 0) {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        //从后往前找
        post = len - 1;
        while (nums[post] <= nums[pre])
        {
            post--;
        }
        swap(nums[post], nums[pre]);
        sort(nums.begin() + pre + 1, nums.end());
    }
}







int firstMissingPositive(vector<int>& nums)
{
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        //注意这里是while不是if，要一直换使得当前nums[i]是正确的值才行
        //否则只是把nums[i]的原住民换到正确的地方了
        while (nums[i] >= 1 && nums[i] <= len && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (nums[i] - 1 != i)
        {
            return i + 1;
        }
    }
    return len + 1;
}

bool isFull(unordered_map<char, int> s_map)
{
    auto it = s_map.begin();
    while (it != s_map.end())
    {
        if (it->second == 0) return false;
        it++;
    }
    return true;
}

//遍历所有子串
string minWindow(string s, string t)
{
    return "";

}

string add(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    int index1 = 0;
    int index2 = 0;
    int flag = 0;
    string result;
    while (index1 < len1 || index2 < len2)
    {
        int addNum1 = (index1 < len1) ? num1[index1] - '0' : 0;
        int addNum2 = (index2 < len2) ? num2[index2] - '0' : 0;
        int addResult = addNum1 + addNum2 + flag;
        result += ('0' + addResult % 10);
        flag = addResult / 10;
        index1++;
        index2++;
    }
    if (flag) result += '1';

    return result;

}

string multiply(string num1, string num2)
{
    string res = "0";
    vector<string> temp_sum;
    int flag = 0;
    int len1 = num1.size();
    int len2 = num2.size();
    //对于num2的每个数
    int index2 = len2 - 1;
    while (index2 >= 0)
    {
        string temp;
        for (int i = index2; i < len2 - 1; i++)
        {
            temp += '0';
        }
        int mul = num2[index2] - '0';
        int flag = 0;
        int index1 = len1 - 1;
        while (index1 >= 0)
        {
            int temp_mul = num1[index1] - '0';
            int temp_mul_res = temp_mul * mul + flag;
            flag = temp_mul_res / 10;
            temp += ('0' + temp_mul_res % 10);
            index1--;
        }
        if (flag) temp += ('0' + flag);
        temp_sum.push_back(temp);
        index2--;
    }

    int size = temp_sum.size();
    for (int i = 0; i < size; i++)
    {
        res = add(res, temp_sum[i]);
    }
    reverse(res.begin(), res.end());
    if (*(res.begin()) == '0') return "0";
    return res;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            break;
        }
        if (target < nums[mid]) right = mid - 1;
        else left = mid + 1;
    }
    if (left > right) return res;
    left = mid - 1;
    while (left >= 0 && nums[left] == target) left--;
    res[0] = left + 1;
    right = mid + 1;
    while (right < len && nums[right] == target) right++;
    res[1] = right - 1;
    return res;
}

string removeDuplicateLetters(string s)
{
    unordered_map<char, int> s_map;
    unordered_set<char> s_set;
    int s_len = s.size();
    stack<char> s_stack;
    for (int i = 0; i < s_len; i++)
    {
        s_map[s[i]]++;
    }

    for (int i = 0; i < s_len; i++)
    {
        char temp = s[i];
        if (s_stack.empty())
        {
            s_stack.push(temp);
            s_set.insert(temp);
            s_map[temp]--;
            continue;
        }
        
        if (temp > s_stack.top())
        {
            if (!s_set.count(temp))
            {
                s_stack.push(temp);
                s_set.insert(temp);
            }
        }
        else
        {
            if (!s_set.count(temp))
            {
                while (!s_stack.empty() && temp <= s_stack.top() && s_map[s_stack.top()] > 0)
                {
                    //s_map[s_stack.top()]--;
                    s_set.erase(s_stack.top());
                    s_stack.pop();
                }
                s_set.insert(temp);
                s_stack.push(temp);
            }   
                
        }
        s_map[temp]--;
    }
    string res;
    while (!s_stack.empty())
    {
        res += s_stack.top();
        s_stack.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

//找到长度为k的最大数字
vector<int> findKMaxNumber(vector<int>& nums, int k)
{
    int len = nums.size();
    stack<int> s;
    for (int i = 0; i < len; i++)
    {
        
        while (s.size() > 0 && nums[i] > s.top() && s.size() + len - i > k)
        {
            s.pop();
        }
        if(s.size() < k)
            s.push(nums[i]);
    }
    vector<int> res(k);
    int index = k - 1;
    while (!s.empty())
    {
        res[index--] = s.top();
        s.pop();
    }
    return res;
}

int compareTwoNumber(vector<int>& nums1, int index1, vector<int>& nums2, int index2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();

    while (index1 < len1 && index2 < len2)
    {
        int diff = nums1[index1] - nums2[index2];
        if (diff != 0) return diff;
        index1++;
        index2++;
    }

    return (len1 - index1) - (len2 - index2);

}

//nums1 > nums2 true
bool compareTwoNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
    int index = 0;
    while (index < k&& nums1[index] == nums2[index]) index++;
    if (index == k) return false;
    return nums1[index] > nums2[index];
}

vector<int> combineTwoNumber(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    vector<int> res(len1 + len2, 0);
    while (index1 < len1 || index2 < len2)
    {
        int n1 = (index1 < len1) ? nums1[index1] : -1;
        int n2 = (index2 < len2) ? nums2[index2] : -1;
        if (n1 > n2)
        {
            res[index++] = n1;
            index1++;
        }
        else if(n1 < n2)
        {
            res[index++] = n2;
            index2++;
        }
        else
        {
            res[index++] = n1;
            int flag = compareTwoNumber(nums1, index1 + 1, nums2, index2 + 1);
            if (flag > 0) index1++;
            else index2++;
        }
        
    }
    return res;
}



vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
    vector<int> res(k, 0);
    int len1 = nums1.size();
    int len2 = nums2.size();
    
    int upper = min(k, len1);
    for (int m = 0; m <= upper; m++)
    {
        vector<int> temp1;
        vector<int> temp2;
        vector<int> temp_res;
        if (k - m > len2) continue;
        if (m == 0)
        {
            
            temp_res = findKMaxNumber(nums2, k);
        }
        else if(m == k)
        {
            
            temp_res = findKMaxNumber(nums1, k);
        }
        else
        {
            temp1 = findKMaxNumber(nums1, m);
            temp2 = findKMaxNumber(nums2, k - m);
            temp_res = combineTwoNumber(temp1, temp2);
        }
        if (compareTwoNumber(temp_res, res, k))
        {
            res.assign(temp_res.begin(), temp_res.end());
        }
    }
    //res = findKMaxNumber(nums2, 4);
    return res;
}

int totalFruit(vector<int>& fruits)
{
    int len = fruits.size();
    int res = 0;
    int left = 0, right = 0;
    map<int, int> fruit_map;

    vector<int> type(2, -1);

    while (left < len && right < len)
    {
        if (type[0] == -1) type[0] = fruits[left];
        while (right < len && (fruits[right] == type[0] || fruits[right] == type[1]))
        {
            fruit_map[fruits[right]]++;
            right++;
        }
        if (right < len && type[1] == -1)
        {
            type[1] = fruits[right];
            continue;
        }
        else if(right < len)
        {
            if (right - left > res) res = right - left;

            //type[0]缩小窗口
            while (fruit_map[type[0]] > 0 && fruit_map[type[1]] > 0)
            {
                fruit_map[fruits[left]]--;
                left++;
            }
            if (fruit_map[type[0]] == 0)
            {
                type[0] = fruits[right];
            }
            else
            {
                type[1] = fruits[right];
            }
            
        }
        else
        {
            if (right - left > res) res = right - left;
            break;
        }
        
    }
    return res;

}

void getNext(vector<int>& next, string& needle)
{
    int len = needle.size();
    next.resize(len + 1);
    int pre = -1;

    next[0] = pre;

    for (int post = 1; post < len; post++)
    {
        while (pre >= 0 && needle[pre + 1] != needle[post])
        {
            pre = next[pre];
        }
        if (needle[post] == needle[pre + 1])
        {
            pre++;
        }
        next[post] = pre;
    }
}


int strStr(string haystack, string needle)
{
    int hayLen = haystack.size();
    int neeLen = needle.size();
    int res = -1;
    vector<int> next;
    getNext(next, needle);

    int needleIndex = -1;
    for (int i = 0; i < hayLen; i++)
    {
        while (needleIndex >= 0 && needle[needleIndex + 1] != haystack[i])
        {
            needleIndex = next[needleIndex];
        }
        if (needle[needleIndex + 1] == haystack[i])
        {
            needleIndex++;
        }
        if (needleIndex + 1 >= neeLen)
        {
            res = i - neeLen + 1;
            break;
        }
    }
    return res;

}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> res;
    deque<int> num_queue;

    int size = nums.size();
    //int max_num = nums[0];
    for (int i = 0; i < k; i++)
    {
        while (!num_queue.empty() && nums[i] > num_queue.back())
        {
            num_queue.pop_back();
            
        }
        num_queue.push_back(nums[i]);
    }

    res.push_back(num_queue.front());

    int left = 1;
    int right = left + k - 1;
    while (right < size)
    {
        if (nums[left - 1] >= num_queue.front())
        {
            num_queue.pop_front();
        }
        if (nums[right] <= num_queue.front())
        {
            while (!num_queue.empty() && num_queue.back() < nums[right])
            {
                num_queue.pop_back();
            }
            num_queue.push_back(nums[right]);
        }
        else
        {
            while (!num_queue.empty() && num_queue.front() < nums[right])
            {
                num_queue.pop_front();
            }
            num_queue.push_back(nums[right]);
        }
        res.push_back(num_queue.front());

        left++;
        right++;
    }

    return res;
    
    
}
