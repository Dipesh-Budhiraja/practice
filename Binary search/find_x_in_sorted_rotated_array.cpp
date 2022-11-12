class Solution{
    public:
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        
        //find pivot point
        int pivot = -1;
        int mid = (l + h)/2;
        
        pivot = find_pivot(A, l, h);
        // cout << pivot << endl;
        if (pivot == -1) {
            // no pivot 
            return bs(A, l, h, key);
        } else {
            if (key >= A[l] && key <= A[pivot]) {
                return bs(A, l, pivot, key);
            } else {
                return bs(A, pivot+1, h, key);
            }
        }
    }
    
    int find_pivot(int arr[], int l, int h) {
        if(l>h) {
            return -1;
        }
        int mid = (l+h)/2;
        if (arr[mid] > arr[mid+1]) {
            return mid;
        } else if (arr[mid-1] > arr[mid]) {
            return mid - 1;
        }
        else if (arr[mid] > arr[h]) {
            return find_pivot(arr, mid+1, h);
        } else {
            return find_pivot(arr, l, mid-1);
        }
        
    }
    
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
};