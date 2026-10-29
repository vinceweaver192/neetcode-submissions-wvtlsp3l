class TimeMap {
private:
    unordered_map<string, map<int, string>> u_map;
public:
    TimeMap() {
       ;
    }
   
    void set(string key, string value, int timestamp)
    {
        // cout << "Test 1" << endl;
        u_map[key][timestamp] = value;    
    }
   
    string get(string key, int timestamp)
    {
        // cout << "Test 2" << endl;
        // cout << "Value: " << ((u_map[key].upper_bound(timestamp))--)->second << endl;
        if(u_map[key].size() == 0)
        {
            return "";
        }

        auto it = (u_map[key].upper_bound(timestamp));
        if(it != u_map[key].begin())
        {
            it--;
        }

        if(it == u_map[key].begin() && timestamp < it->first)
        {
            return "";
        }
        return it->second;
    }
};
