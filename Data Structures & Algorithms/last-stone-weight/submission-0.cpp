class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            int rem = abs(stone1 - stone2);

            if (rem != 0) 
                pq.push(rem);
        }

        if (pq.empty())
            return 0;

        return pq.top();
    }
};
