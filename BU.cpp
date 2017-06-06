#include <bits/stdc++.h>
#define mod 1000000007
 using namespace std;
int  _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
 
/* This function sorts the input array and returns the
   number of inversions in the array */
long long int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
long long int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid;
  long long int inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
 
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count = (inv_count%mod +  _mergeSort(arr, temp, mid+1, right)%mod)%mod;
 
    /*Merge the two parts*/
    inv_count  =  (inv_count%mod + merge(arr, temp, left, mid+1, right)%mod)%mod;
  }
  return inv_count;
}
 
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
long long int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  long long int  inv_count = 0;
 
  i = left; /* i is index for left subarray*/
  j = mid;  /* j is index for right subarray*/
  k = left; /* k is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
 
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = (inv_count%mod + (mid - i)%mod)%mod;
    }
  }
 
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
 
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
 
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}
 
/* Driver program to test above functions */
int main(int argv, char** args)
{
  int t;
  cin >> t;
  while(t--)
  {
      int n;
      cin >> n;
      int ar[n];
      for(int i=0;i<n;i++)
        cin >> ar[i];
      long long int ans = mergeSort(ar, n);
      cout << ans << endl;
  }
  return 0;
}