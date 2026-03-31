class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count the frequency of each task using an unordered_map
        unordered_map<char, int> freqMap;
        for (char task : tasks) {
            freqMap[task]++;
        }
        
        // Step 2: Use a max heap (priority queue) to always process the most frequent task first
        priority_queue<int> maxHeap;
        for (auto& entry : freqMap) {
            maxHeap.push(entry.second);  // Push task frequencies into max heap
        }
        
        int time = 0;  // Tracks total CPU cycles needed
        
        // Step 3: Queue to manage tasks that are in the cooldown period
        queue<pair<int, int>> cooldownQueue;  // Stores {remaining count, time it can be reinserted}
        
        // Step 4: Process tasks in a greedy manner
        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            time++;  // Increment CPU cycle count
            
            // If maxHeap is empty, skip directly to the next available task in cooldown
            if (maxHeap.empty()) {
                time = cooldownQueue.front().second;  // Jump to the time when the next task is available
            } else {
                // Process the most frequent task
                int remainingCount = maxHeap.top() - 1;  // Decrease task frequency
                maxHeap.pop();
                
                // If the task still has occurrences left, push it into the cooldown queue
                if (remainingCount > 0) {
                    cooldownQueue.push({remainingCount, time + n});
                }
            }
            
            // If a task in cooldown has completed its wait time, reinsert it into the heap
            if (!cooldownQueue.empty() && cooldownQueue.front().second == time) {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }
        
        // Step 5: Return the total time required to complete all tasks
        return time;        
    }
};
