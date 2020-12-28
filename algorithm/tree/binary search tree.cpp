// 1D
class BIT{
public:
    BIT(int n): bit(n+1) {
    }
    void update(int idx, int diff){
        while(idx < bit.size()){
            bit[idx] += diff;
            idx += lowbit(idx);
        }
    }
    int get(int idx){
        int ans = 0;
        while(idx){
            ans += bit[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
    
private:
    vector<int> bit;
    int lowbit(int x){
        return x & (-x);
    }
};

// 2D
