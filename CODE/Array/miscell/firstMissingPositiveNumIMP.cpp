void swap(int *a,int*b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    int findMissingPositiveNumberinPositiveOnlyArray(int arr[],int n){
        for(int i =1;i<=n;i++){
            if ( (arr[i-1])<=n && (arr[i-1])>=1)
                arr[arr[i-1]-1]*=-1;
        }
        int ans=0;
        for(int i =1;i<=n;i++){
            
            if(arr[i-1]<0);
            else{ ans=i;break;}
        }
        return ans==0?n+1:ans;
    }
    int segregate(int arr[],int n){
        int i=0,j=0;
        for(int i =0;i<n;i++){
            if(arr[i]<=0){
                swap(&arr[i],&arr[j]);
                j++;
            }
        }
        return j;
    }
    int missingNumber(int arr[], int n) 
    { 
        int shift = segregate(arr,n);
        return findMissingPositiveNumberinPositiveOnlyArray(arr+shift,n-shift);
    } 