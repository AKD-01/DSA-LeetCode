class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto it = _map.lower_bound(value);
        bool merged = false;
        if(it != _map.begin()) {
            auto prev = it;
            --prev;
            if(prev->second + 1 >= value) {
                merged = true;
                prev->second = max(prev->second, value);
            }
        }

        if(it != _map.end()) {
            if(it->first - 1 <= value) {
                if(merged) {
                    auto prev = it;
                    --prev;
                    if(prev->second >= it->first - 1) {
                        prev->second = max(prev->second, it->second);
                        _map.erase(it);
                    }
                } else {
                    merged = true;
                    if(it->first != value) {
                        pair<int, int> p = *it;
                        p.first = min(p.first, value);
                        it = _map.insert(it, p);
                        ++it;
                        if(it != _map.end())
                            _map.erase(it);
                    }
                }
            }
        }
        if(!merged)
            _map.insert(it, {value, value});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for(auto const & p : _map)
            intervals.push_back({p.first, p.second});
        return intervals;
    }

    map<int, int> _map;
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */