#include <iostream>
using namespace std;
vector<vector<int> > solve(vector<int> nums, vector<vector<int> > ans, int index = 0)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return ans;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, ++index);
       // swap(nums[index], nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ans;
        cin >> ans;
        nums.push_back(ans);
    }
    vector<vector<int> > ans;
    solve(nums, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<endl;
        }
    }
}