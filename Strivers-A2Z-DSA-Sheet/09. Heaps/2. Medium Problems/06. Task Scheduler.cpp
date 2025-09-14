/*
QUESTION:
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

APPROACH:
To minimize the total time, we need to consider the task with the maximum frequency. Let's assume the maximum frequency is maxfreq. The CPU will need at least (maxfreq - 1) intervals of cooldown time between the executions of the tasks with the maximum frequency.

1. Create a frequency map to count the occurrences of each task.
2. Find the maximum frequency maxfreq.
3. Calculate the total number of intervals required by multiplying (maxfreq - 1) with the cooldown period n.
4. Iterate through the frequency map and count the number of tasks with the maximum frequency. Add this count to the total number of intervals.
5. Return the maximum of the total number of intervals and the total number of tasks.

The leastInterval function implements this approach.

TIME COMPLEXITY:
The time complexity of the leastInterval function is O(N), where N is the number of tasks. We iterate through the tasks twice: once to calculate the frequencies and find the maximum frequency, and once to count the number of tasks with the maximum frequency. Both iterations take O(N) time.

SPACE COMPLEXITY:
The space complexity is O(1) because the frequency map has a fixed number of unique tasks (26 lowercase letters).
*/

int leastInterval(vector<char>& tasks, int n) {
    int siz = tasks.size();
    unordered_map<char, int> mp;
    for (auto it : tasks)
        mp[it]++;
    int maxfreq = INT_MIN;
    for (auto it : mp)
        maxfreq = max(maxfreq, it.second);
    // A _ _ A _ _ A _ _ A _ _ A _ _ A
    int ans = (maxfreq - 1) * (n + 1);
    // number of elements having maxfreq
    for (auto it : mp) {
        if (it.second == maxfreq)
            ans++;
    }
    return max(ans, siz);
}

/*
Why not just return ans instead of max(ans, siz);

🔹 Example where ans < siz
Say:
tasks = [A, A, A, B, C, D, E, F, G, H, I], n = 2
Count: A=3, others = 1.
maxfreq = 3.
(maxfreq - 1) * (n+1) = (3-1)*3 = 6.
Only one task has maxfreq, so ans = 6 + 1 = 7.

But siz = 11 (we must execute all 11 tasks).
👉 If we just return ans = 7, it’s wrong. The CPU must spend at least 11 units, one per task.
So we take max(ans, siz) = max(7, 11) = 11.

🔹 Example where ans >= siz
tasks = [A, A, A, B, B, B], n = 2
A=3, B=3, maxfreq=3.
(maxfreq - 1) * (n+1) = 6.
count(maxfreqTasks)=2.
ans=8.
siz=6.
Here ans > siz (because we need idle slots). So the correct answer is 8.

🔹 Conclusion
ans = theoretical minimum schedule length based on the bottleneck (maxfreq tasks).
siz = total tasks (we can’t do fewer than this).
So the true minimum time = max(ans, siz).

*/
