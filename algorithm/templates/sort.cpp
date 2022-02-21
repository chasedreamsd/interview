void quick_sort(vector<int>& arr, int st, int ed){
    if(st >= ed) {
        return; 
    }

    int left = st, right = ed;
    int pivot = arr[(st+ed)/2];

    // left <= right guarantee will end with left = right + 1
    // left < right will lead to dead loop 
    // like [1, 2], left = 0, right = 1
    while(left <= right){
        // arr[left] < pivot make arr[left] == pivot to spread evenly in both sides
        while(left <= right && arr[left] < pivot){
            ++left;
        }
        while(left <= right && arr[right] > pivot){
            --right;
        }
        if(left <= right){
            swap(arr[left++], arr[right--]);
        }
    }

    quick_sort(arr, st, right);
    quick_sort(arr, left, ed);
}
