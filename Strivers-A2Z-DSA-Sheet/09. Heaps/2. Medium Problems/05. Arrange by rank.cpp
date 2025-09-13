/*
QUESTION:
Given an array of integers arr, replace each element with its rank.

APPROACH:
To assign ranks to the elements in the array, we can use a min-heap (priority queue) to sort the elements in ascending order along with their indices.
1. Create a min-heap to store pairs of (element, index) in ascending order.
2. Push each element along with its index into the min-heap.
3. Initialize the rank as 0 and the previous element as INT_MIN (an arbitrary value that never matches any element).
4. While the min-heap is not empty, extract the minimum element from the min-heap.
5. If the current element is different from the previous element, increment the rank.
6. Assign the rank to the element at its corresponding index in the result array.
7. Repeat steps 4-6 until all elements are processed.

The arrayRankTransform function implements this approach. It uses a min-heap to assign ranks to the elements in the array.

TIME COMPLEXITY:
The time complexity of the arrayRankTransform function is O(N log N), where N is the size of the array. Inserting elements into the min-heap and extracting the minimum element take O(log N) time, and we do this for N elements. The overall time complexity is dominated by the heap operations.

SPACE COMPLEXITY:
The space complexity is O(N) as we need to store N elements in the min-heap and the result array.

🔹 Dry Run
arr = [40, 10, 20, 20, 30]
Push → heap = {10,1}, {20,2}, {20,3}, {30,4}, {40,0}
Pop {10,1} → new value ≠ prev → rank=1 → ans[1]=1
Pop {20,2} → new value ≠ 10 → rank=2 → ans[2]=2
Pop {20,3} → same as prev (20) → rank stays 2 → ans[3]=2
Pop {30,4} → new value ≠ 20 → rank=3 → ans[4]=3
Pop {40,0} → new value ≠ 30 → rank=4 → ans[0]=4
Final result: ans = [4,1,2,2,3]


*/

vector<int> arrayRankTransform(vector<int>& arr) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push({arr[i], i});
    }
    vector<int> ans(arr.size());
    int rank = 0;
    int prev = INT_MIN; // an arbitrary value which never matches
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (top.first != prev) {
            rank++;
        }
        ans[top.second] = rank;
        prev = top.first;
    }
    return ans;
}
