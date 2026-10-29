class TimeMap {
private:
    unordered_map<string, map<int, string>> u_map;
public:
    TimeMap() {
       ;
    }
   
    void set(string key, string value, int timestamp)
    {
        u_map[key][timestamp] = value;    
    }
   
    string get(string key, int timestamp)
    {
        if(u_map[key].size() == 0)
        {
            return "";
        }

        auto it = (u_map[key].upper_bound(timestamp));
        if(it == u_map[key].begin())
        {
            return "";
        }
        it--;
        return it->second;
    }
};
