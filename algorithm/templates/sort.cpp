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

void merge_sorted_array(vector<int>& arr, int st, int ed){
    int mid = (st + ed) / 2;
    vector<int> tmp(ed-st+1);
    int idx1 = st, idx2 = mid+1, idx = 0;
    while(idx1 <= mid && idx2 <= ed){
        if(arr[idx1] <= arr[idx2]){
            tmp[idx++] = arr[idx1++];
        }
        else{
            tmp[idx++] = arr[idx2++];
        }
    }

    while(idx1 <= mid){
        tmp[idx++] = arr[idx1++];
    }

    while(idx2 <= ed){
        tmp[idx++] = arr[idx2++];
    }

    for(int i = 0; i < ed-st+1; ++i){
        arr[st+i] = tmp[i];
    }
}

void merge_sort(vector<int>& arr, int st, int ed){
    if(st >= ed){
        return;
    }

    int mid = (st + ed) / 2;
    merge_sort(arr, st, mid);
    merge_sort(arr, mid+1, ed);
    merge_sorted_array(arr, st, ed);
}

