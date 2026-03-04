class SmallestInfiniteSet {
    vector<int>nums;
    int i=1;
public:
    
    SmallestInfiniteSet() {
        nums=vector<int>(1001,1);
    }
    
    int popSmallest() {
        nums[i]=0;
        int ans=i;
        // i++;
        for(int j=i+1;j<=1000;j++){
            if(nums[j]==1){
                i=j; break;
            }
        }
        return ans;
    }
    
    void addBack(int num) {
        if(nums[num]==0){nums[num]=1;
        if(num<i) i=num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */