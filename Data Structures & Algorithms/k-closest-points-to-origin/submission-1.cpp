class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // dist, index

        for (int i = 0; i < points.size(); i++) {
            auto point = points[i];
            int x = (point[0] - 0);
            int y = (point[1] - 0);
            int dist = (x*x) + (y*y);

            pq.push({dist,i});
        }

        vector<vector<int>> results;

        while (k > 0) {
            results.push_back(points[pq.top().second]);
            pq.pop();
            k--;
        }

        return results;
    }
};
