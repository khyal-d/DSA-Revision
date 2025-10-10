/*
Question:
Given a directed graph, perform Breadth First Traversal (BFS) of the graph starting from vertex 0 and visit all the nodes directly or indirectly connected to Node 0.

Explanation:
- We initialize an empty vector 'ans' to store the BFS traversal.
- We also initialize a vector 'vis' to keep track of visited nodes, initialized with 'false' for all nodes.
- We use a queue 'q' to perform BFS. We start by pushing vertex 0 into the queue and mark it as visited.
- While the queue is not empty, we pop the front element and add it to the 'ans' vector.
- For each adjacent vertex of the current node, if it has not been visited, we push it into the queue and mark it as visited.
- We continue this process until the queue becomes empty and all connected nodes are visited.
- Finally, we return the 'ans' vector containing the BFS traversal.

Time Complexity:
- The time complexity is O(V + E), where V is the number of vertices and E is the number of edges in the graph. In the worst case, we visit all the vertices and edges.

Space Complexity:
- The space complexity is O(V), where V is the number of vertices, as we use extra space for the 'vis' vector and the 'q' queue.

*/

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> vis(V, false);

    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto i : adj[node]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }

    return ans;
}


// Striver solution 

/*
Question:
Given a directed graph, perform Breadth First Traversal (BFS) of the graph starting from vertex 0 and visit all the nodes directly or indirectly connected to Node 0.

Explanation:
- We maintain an adjacency list to represent the graph.
- We use an integer array 'vis' of size V, initialized with 0, to mark visited nodes.
- We use a queue 'q' to perform BFS. BFS works in a FIFO manner.
- Start by marking node 0 as visited and pushing it into the queue.
- While the queue is not empty:
    - Pop the front node and add it to the answer.
    - Traverse all adjacent nodes of this node. If any neighbor has not been visited:
        - Mark it visited.
        - Push it into the queue.
- Continue until the queue is empty. This ensures all nodes reachable from node 0 are visited.
- Finally, return the BFS traversal order.

Time Complexity:
- O(V + E), where V is the number of vertices and E is the number of edges, since each vertex and edge is processed once.

Space Complexity:
- O(V), for the visited array and queue.
*/
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

// if V is not given then use int V = adj.size();        
        int vis[V] = {0};      // visited array initialized to 0
        vis[0] = 1;            // mark starting node as visited
        queue<int> q;          // BFS queue
        q.push(0);             // push starting node
        vector<int> bfs;       // result vector

        // iterate until queue is empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            // traverse all adjacent nodes
            for (auto it : adj[node]) {
                if (!vis[it]) {    // if not visited
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
