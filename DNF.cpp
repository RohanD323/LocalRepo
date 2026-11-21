#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin>>n;
    
    vector<int> nums(n);

    for(int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }

    int low = 0, mid = 0, high = n - 1;

    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }

    }
   
    for(int val : nums)
    {
        cout<<val<<" ";
    }
}