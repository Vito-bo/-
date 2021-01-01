
#include <iostraem>
using namespace std;

// 剑指offer40-最小的k个数
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		/*
		// 方法1：排序。时间复杂度O(N*logN) 空间复杂度O(logN)
		vector<int> ret(k,0);
		sort(arr.begin(),arr.end());
		for(int i=0;i<k;i++)
		{
		ret[i]=arr[i];
		}
		return ret;
		*/
		// 方法2：优先级队列。时间复杂度O(N*logk) 空间复杂度O(logK)
		vector<int> ret(k, 0);
		if (k == 0)
		{
			return ret;
		}
		priority_queue<int> q;
		for (int i = 0; i<k; i++)
		{
			q.push(arr[i]);
		}

		for (int i = k; i<arr.size(); i++)
		{
			if (q.top() > arr[i])
			{
				q.pop();
				q.push(arr[i]);
			}
		}
		for (int i = 0; i<k; i++)
		{
			ret[i] = q.top();
			q.pop();
		}
		return ret;

	}
};

// 剑指offer30-包含min函数的栈
class MinStack {
public:
	/** initialize your data structure here. */

	// 定义一个数据栈和一个辅助栈
	stack<int> data, help;
	MinStack() {

	}

	void push(int x) {
		data.push(x);
		// 如果x是data和help的第一个元素，或者x小于等于help的最小元素，入栈
		if (help.empty() || x <= help.top())
		{
			help.push(x);
		}
		if (x>help.top())
		{
			// 如果x大于help中的最小元素，向help中再压入一遍该最小元素，保持两个栈元素个数相等
			int tmp = help.top();
			help.push(tmp);
		}
	}

	// 出栈(移除栈顶元素)
	void pop() {
		if (!data.empty() && !help.empty())
		{
			data.pop();
			help.pop();
		}
	}

	// 查找栈顶元素
	int top()
	{
		return data.top();
	}

	int min() {
		return help.top();
	}
};

// 剑指offer42-连续子数组的最大和
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// 动态规划
		// 状态(子问题)：dp[i]表示以nums[i]为结尾的连续子数组最大和
		// 转移策略(自带剪枝)：若dp[i-1]<0,说明dp[i-1]对dp[i]产生负贡献，即dp[i-1]+nums[i]<=nums[i]
		// 状态转移方程：当dp[i-1]>0,dp[i]=dp[i-1]+nums[i]
		//              当dp[i-1]<=0,dp[i]=nums[i]
		int ret = nums[0];
		for (int i = 1; i<nums.size(); i++)
		{
			nums[i] += max(nums[i - 1], 0);
			ret = max(nums[i], ret);
		}
		return ret;
	}
};


int main()
{
	return 0;
}
