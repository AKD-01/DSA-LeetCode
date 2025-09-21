class MovieRentingSystem {
    unordered_map<int, set<pair<int, int>>> available;
    unordered_map<int, unordered_map<int, int>> prices;
    set<vector<int>> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i = 0; i < entries.size(); i++) {
            available[entries[i][1]].insert({entries[i][2], entries[i][0]});
            prices[entries[i][0]][entries[i][1]] = entries[i][2]; 
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        for(auto &[price, shop]: available[movie]) {
            ans.push_back(shop);
            if(ans.size() == 5) return ans;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        rented.insert({prices[shop][movie], shop, movie});
        available[movie].erase({prices[shop][movie], shop});
    }
    
    void drop(int shop, int movie) {
        rented.erase({prices[shop][movie], shop, movie});
        available[movie].insert({prices[shop][movie], shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto element: rented) {
            ans.push_back({element[1], element[2]});
            if(ans.size() == 5) {
                return ans;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */