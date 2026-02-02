class Solution {
    long long Sum=0;
    multiset<int> small, large;

    void add(int x, int m) {
        small.insert(x);
        Sum+=x;
        if (small.size()>m) {// small should have at most m elements
            int toMove=*small.rbegin();
            Sum-=toMove;
            large.insert(toMove);
            small.erase(prev(small.end()));
        }
    }

    void remove(int x) {
        auto it=small.find(x);
        if (it!=small.end()) {
            Sum-=x;
            small.erase(it);
            if (!large.empty()) {
                auto lit=large.begin(); // Use iterator 
                int toMove=*lit;
                Sum+=toMove;
                small.insert(toMove);
                large.erase(lit); // removal by iterator
            }
        } 
        else {
            auto itL=large.find(x);
            large.erase(itL); //remove
        }
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int n=nums.size();
        k--; // Need k-1 more elements after nums[0]

        // Initialize the first window [1, dist+1]
        const int iN=dist+2;
        vector<int> win(nums.begin()+1, nums.begin()+iN);
    
        // the (k-1)-th smallest element at its sorted position
        nth_element(win.begin(), win.begin()+k, win.end());
        small=multiset<int>(win.begin(), win.begin()+k);
        Sum=accumulate(win.begin(), win.begin()+k, 0LL);
        large=multiset<int>(win.begin()+k, win.end());
    
        long long minCost=nums[0]+Sum;

        // Slide the window starting from index 1.
        // Elements in current window: nums[l...r]
        for (int l=1, r=dist+2; r<n; l++, r++) {
            remove(nums[l]);
            add(nums[r], k);

            // Update 
            minCost=min(minCost, nums[0]+Sum);
        }
        return minCost;
    }
};