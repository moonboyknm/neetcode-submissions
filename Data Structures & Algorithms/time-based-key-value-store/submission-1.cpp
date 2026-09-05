class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>>keyStore;

public:
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int l = 0, r = values.size() - 1;
        string res = "";

        while (l <= r){
            int mid = l + (r - l) / 2;

            if (timestamp >= values[mid].first){
                res = values[mid].second; // string
                l = mid + 1; // there could be more to the right
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
