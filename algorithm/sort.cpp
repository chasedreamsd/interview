

void rainbowSort(vector<int>& colors, int color_st, int color_ed, int idx_st, int idx_ed){
    if(color_st == color_ed || idx_st == idx_ed){
        return;
    }

    int color_mid = (color_st + color_ed) / 2;
    int left = idx_st, right = idx_ed;
    while(left <= right){
        while(left <= right && colors[left] <= color_mid){
            ++left;
        }
        while(left <= right && colors[right] > color_mid){
            --right;
        }
        if(left <= right){
            swap(colors[left], colors[right]);
        }
    }

    rainbowSort(colors, color_st, color_mid, idx_st, right);
    rainbowSort(colors, color_mid+1, color_ed, left, idx_ed);
}
