/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
Count of Smaller Numbers After Self
Hard

1704

67

Add to List

Share
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
class Solution {
public:
    vector<int> coordinateCompress(const vector<int> &v)
	{
	    set<int> s;
	    unordered_map<int, int> m;
	    for (int i = 0; i < v.size(); i++)
	    {
	        s.insert(v[i]);
	    }
	
	    for (int i = 1; !s.empty(); i++)
	    {
	        m[*s.begin()] = i;
	        s.erase(s.begin());
	    }
	
	    vector<int> ans(v.size());
	    for (int i = 0; i < ans.size(); i++)
	    {
	        ans[i] = m[v[i]];
	    }
	
	    return ans;
	}
	
	vector<int> BIT;
	
	void update(int i, int inc)
	{
	    i++;
	    while (i < BIT.size())
	    {
	        BIT[i] += inc;
	        i += i & (-i);
	    }
	}
	
	int query(int i)
	{
	    int sum = 0;
	    while (i > 0)
	    {
	        sum += BIT[i];
	        i -= i & (-i);
	    }
	    return sum;
	}
	
	vector<int> countSmaller(vector<int> &nums)
	{
	    BIT.clear();
	    BIT.resize(nums.size() + 5, 0);
	
	    vector<int> v = coordinateCompress(nums);
	
	    vector<int> ans(v.size());
	    for (int i = v.size() - 1; i >= 0; i--)
	    {
	        ans[i] = query(v[i]);
	        update(v[i], 1);
	    }
	
	    return ans;
	}
};
