int kthElement(int arr1[], int arr2[], int n, int m, int K)
    {
        int i=0,j=0;
        int k =0;
        int sum=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                if(k==(K-1)){return arr1[i];} //THIS POSITIONING IS VERY IMP!!!BEFORE INCREMENTING ANY 
                i++;k++;
            }
            else{
                if(k==(K-1)){return arr2[j];}//THIS POSITIONING IS VERY IMP!!!BEFORE INCREMENTING ANY 
                j++;k++;
            }
        }
        while(i<n){
            if(k==(K-1)){return arr1[i];} //THIS POSITIONING IS VERY IMP!!!BEFORE INCREMENTING ANY 
            i++,k++;
        }
        while(j<n){
            if(k==(K-1)){return arr2[j];} //THIS POSITIONING IS VERY IMP!!!BEFORE INCREMENTING ANY 
            j++,k++;
        }
        
    }