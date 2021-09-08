void swap(int * a ,int * b){
    int temp =*a;
    *a=*b;
    *b=temp;
}
int partion(int *arr,int l ,int r){
    int i =l-1;
    int high =arr[r];
    for(int j =l;j<=r;i++){
        if(arr[j]<=high){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
int quickSort(int *arr,int l ,int r, int k){
    if(l>=r)return 0;
    int p =partion(arr,l,r);
    if(p-l ==k-1)return p;
    if(p-l>k-1) return quickSort(arr,l,p-1,k);
    return quickSort(arr,p+1,r, k-1-(p-l) );
    
}

/*
int quickSelect(int A[], int l, int h,int k)
{
    int p = partition(A, l, h); 
    if(p==(k-1)) return A[p];
    else if(p>(k-1)) return quickSelect(A, l, p - 1,k);  
    else return quickSelect(A, p + 1, h,k);

}
*/

//can be done using map also with o(n) time and o(n) space