class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();  // No cooldown, just execute sequentially

        unordered_map<char, int> freqMap;
        for (char task : tasks) {
            freqMap[task]++;
        }

        // Max heap (priority queue) to process most frequent tasks first
        priority_queue<int> maxHeap;
        for (auto& entry : freqMap) {
            maxHeap.push(entry.second);
        }

        int cycles = 0;

        while (!maxHeap.empty()) {
            vector<int> temp;
            int tasksProcessed = 0;

            // Process up to (n + 1) tasks per cycle
            for (int i = 0; i < n + 1; i++) {
                if (!maxHeap.empty()) {
                    temp.push_back(maxHeap.top() - 1);
                    maxHeap.pop();
                    tasksProcessed++;
                }
            }

            // Reinsert remaining tasks back into the max heap
            for (int count : temp) {
                if (count > 0) {
                    maxHeap.push(count);
                }
            }

            // If heap is empty, no more idle time needed, otherwise, we process full cycle
            cycles += maxHeap.empty() ? tasksProcessed : (n + 1);
        }

        return cycles;        
    }
};
