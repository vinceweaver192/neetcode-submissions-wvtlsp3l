// Approach:
// 1. MUST create a frequency map 
//    - to indentify all chars and the number of duplicates
// 2. use freq map to create maxHeap (sorted high to low, push O(log(n)) )
//    * maxHeap is default nature for priority queues
// 3. MUST create cooldownQueue
//    - Purpose: to keep track of next available occurrence for duplicate char (follows n rule)
// 4. Return number of cycles/time of iterations
// 
// * NO NEED to focus on any specifics of chars
//   - We only care about occurences: Ex. if every char has 1 duplicate, then it doesnt matter what comes first

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // freq map
        unordered_map<char, int> freqMap;

        for (char c : tasks) {
            freqMap[c]++;
        }

        // maxHeap
        priority_queue<int> maxHeap;

        for (auto& pair : freqMap) {
            maxHeap.push(pair.second); // greatest to least
        }

        // create cooldown queue
        queue<pair<int, int>> cooldownQueue; // occurences remaining, time for next available

        // keep track of time/num of cycles
        // * ALWAYS start counter at 0
        int time = 0;

        // now iterate until both maxHeap AND cooldownQueue are empty
        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            // first always increment cycle time
            time++;

            // check maxHeap
            // 1. if empty, then cooldown is not empty, set time in cooldown to current time
            //    - it will be caught in cooldown check
            // 2. if NOT empty, 
            //    - subtract 1 from the top of heap occurences
            //    * POP from maxHeap!
            //    - check if there are more occurences, if so, then add them to cooldownQueue
            if (maxHeap.empty()) {
                time = cooldownQueue.front().second;
            }
            else {
                int remaining = maxHeap.top() - 1;
                maxHeap.pop();
                // check if there are more occurences/duplicates
                // - if > 0 : then add to cooldown
                if (remaining > 0) {
                    cooldownQueue.push({remaining, time + n}); // can be n+1 but would need to modify time in other places.
                                                               // It is better/simpler to let loop handle time increments
                }
            }

            // cooldown catch
            // 1. if not empty
            // 2. if times are equal
            if (!cooldownQueue.empty() && cooldownQueue.front().second == time) {
                // 1. add back into maxHeap
                // 2. pop front of cooldownQueue
                maxHeap.push(cooldownQueue.front().first); // push occurences
                cooldownQueue.pop(); 
            }
        }

        // return num of cycles (time)
        return time;
    }
};
