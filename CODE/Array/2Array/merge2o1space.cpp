// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

//Function to merge the arrays.
void merge(int ar1[], int ar2[], int n, int m)
{ 
    for (int i = n - 1; i >= 0; i--)
    {
        /* Find the smallest element greater than ar2[i].
        Move all elements one position ahead till the
        smallest greater element is not found */
        int j, last = ar1[m - 1];
        for (j = m - 2; j >= 0
             && ar1[j] > ar2[i]; j--)
            ar1[j + 1] = ar1[j];
 
        // If there was a greater element
        if (j != m - 2 || last > ar2[i])
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
    }
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int *arr1;
		arr1 = (int*)malloc(n * sizeof(int));
		for(int i=0;i<n;i++)
    		scanf("%d", &arr1[i]);
		int *arr2;
		arr2 = (int*)malloc(m * sizeof(int));
		for(int i=0;i<m;i++)
    		scanf("%d", &arr2[i]);
    	
    	merge(arr1,arr2,n,m);
    	for(int i=0;i<n;i++)
    		printf("%d ", arr1[i]);
		for(int i=0;i<m;i++)
    		printf("%d ", arr2[i]);
    	printf("\n");
	}
	return 0;
}  // } Driver Code Ends