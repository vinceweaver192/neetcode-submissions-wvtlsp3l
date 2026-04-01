class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create adjList of prereqs for directed graph
        // find cycles using bfs
        // calc indegree to determine starting points for bfs
        // - everything with no prereqs will get iterated first
        // - if the course corresponds with a prereq and if that prereq becomes decremented to 0 then add it to the queue for bfs

        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adjList; // prereq : coursesToTake

        for (int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]); // a prereq can have many courses
            indegree[prerequisites[i][0]]++; // count the course to take how many prereqs it has left
        }

        queue<int> q; // courses to take
        //vector<bool> visited(numCourses, false);

        // add all 0s courses from indegree as starting positions for bfs
        for (int i = 0; i < indegree.size(); i++) {
            int preReqCtr = indegree[i];
            if (preReqCtr == 0) {
                q.push(i);
            }
        }

        // bfs
        // count the courses that have been taken
        int coursesTaken = 0;
        while (!q.empty()) {
            //int size = q.size();
            //for (int i = 0; i < size; i++) {
            coursesTaken++;
            int course = q.front();
            
            q.pop();
            //if (adjList.count(course) && !visited[course]) {
                // decrement all courses for this prereq
                // vector adjList[course];
                //visited[course] = true;

            for (auto c : adjList[course]) {
                indegree[c]--;
                if (indegree[c] == 0) { // check if no more prereqs
                    q.push(c);
                }
            }
            //}
            //}
        }

        // return if coursesTaken == numCourses
        return (coursesTaken == numCourses);
    }
};
