class RandomizedCollection {
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {
        bool found = trackCollection.find(val) != trackCollection.end();
        trackCollection[val].insert(collection.size());
        collection.push_back(val);
        return !found;
    }
    
    bool remove(int val) {
        auto it = trackCollection.find(val);
        if (it == trackCollection.end() || it->second.empty()) {
            return false;
        }
        
        int indexToRemove = *(it->second.begin());
        it->second.erase(it->second.begin());

        int lastElement = collection.back();
        collection[indexToRemove] = lastElement;

        if (indexToRemove != collection.size() - 1) {
            trackCollection[lastElement].erase(collection.size() - 1);
            trackCollection[lastElement].insert(indexToRemove);
        }
        
        collection.pop_back();
        
        if (it->second.empty()) {
            trackCollection.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % collection.size();
        return collection[randomIndex];
    }

private:
    unordered_map<int, unordered_set<int>> trackCollection;
    vector<int> collection;
};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */