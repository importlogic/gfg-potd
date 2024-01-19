vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        unordered_map<int, int> freq;
        auto comp = [&](const int& a, const int& b) {
            return freq[a] == freq[b] ? a > b : freq[a] < freq[b];
        };
        set<int, decltype(comp)> topK(comp);

        vector<vector<int>> result;

        for (int i = 0; i < N; ++i) {
            // If element is already in topK, remove it to update
            if (topK.find(arr[i]) != topK.end()) {
                topK.erase(arr[i]);
            }
            // Update frequency
            freq[arr[i]]++;

            // Add element back to set
            topK.insert(arr[i]);

            // If size exceeds K, remove the least frequent / smallest element
            if (topK.size() > K) {
                auto it = topK.begin(); // Element to be removed
                topK.erase(it);
            }

            vector<int> currentTopK;
            for (auto it = topK.rbegin(); it != topK.rend(); ++it) {
                currentTopK.push_back(*it);
            }
            result.push_back(currentTopK);
        }

        return result;
    }
