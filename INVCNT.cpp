// C++ program to count inversions using Binary Indexed Tree
#include<bits/stdc++.h>
using namespace std;
 #define ll long long int
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
ll getSum(ll BITree[], int index)
{
    ll sum = 0; // Initialize result
 
    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(ll BITree[], int n, int index, ll val)
{
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
 
       // Update index to that of parent in update View
       index += index & (-index);
    }
}
 
// Returns inversion count arr[0..n-1]
ll getInvCount(ll arr[], int n)
{
    ll invcount = 0; // Initialize result
 
    // Find maximum element in arr[]
    ll maxElement = 0;
    for (int i=0; i<n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];
 
    // Create a BIT with size equal to maxElement+1 (Extra
    // one is used so that elements can be directly be
    // used as index)
    ll BIT[maxElement+1];
    for (int i=1; i<=maxElement; i++)
        BIT[i] = 0;
 
    // Traverse all elements from right.
    for (int i=n-1; i>=0; i--)
    {
        // Get count of elements smaller than arr[i]
        invcount += getSum(BIT, arr[i]-1);
 
        // Add current element to BIT
        updateBIT(BIT, maxElement, arr[i], 1);
    }
 
    return invcount;
}
 
// Driver program
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		ll ar[n];
		for(int i=0;i<n;i++)
		{
			cin >> ar[i];
		}
		ll ans = getInvCount(ar,n);
		cout << ans << endl;
		
	}/*
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr)/sizeof(int);
    cout << "Number of inversions are : " << getInvCount(arr,n);
    */return 0;
}