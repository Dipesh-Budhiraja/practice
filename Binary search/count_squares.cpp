int bs(int arr[], int beg, int end, int k) {
    if (beg > end) {
        return -1;
    }
    
    int mid = (beg+end)/2;
    
    if(arr[mid] == k) {
        return mid;
    } else if (arr[mid] > k) {
        return bs(arr, beg, mid-1, k);
    } else {
        return bs(arr, mid + 1, end, k);
    }
}