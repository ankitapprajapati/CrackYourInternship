class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    unordered_map<char, int> freq;
    
    // Count the frequency of each task
    for (char task : tasks) {
        freq[task]++;
    }
    
    // Get the max frequency of any task
    int maxFreq = 0;
    for (auto it : freq) {
        maxFreq = std::max(maxFreq, it.second);
    }
    
    // Count how many tasks have the maximum frequency
    int maxFreqCount = 0;
    for (auto it : freq) {
        if (it.second == maxFreq) {
            maxFreqCount++;
        }
    }
    
    // Calculate the minimum intervals needed
    int partCount = maxFreq - 1;
    int partLength = n - (maxFreqCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasks.size() - maxFreq * maxFreqCount;
    int idles = std::max(0, emptySlots - availableTasks);
    
    return tasks.size() + idles;
    }
};