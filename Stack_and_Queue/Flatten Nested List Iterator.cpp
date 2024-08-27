class NestedIterator {
private:
    int curIdx = 0;
    vector<int> flattenedList;

    void helper(vector<NestedInteger> &nestedList, int index){
        if (index >= nestedList.size()) return;

        NestedInteger cur = nestedList[index];
        if (cur.isInteger()) {
            flattenedList.push_back(cur.getInteger());
        } else {
            helper(cur.getList(), 0);
        }
        helper(nestedList, ++index);
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList, 0);
    }
    
    int next() {
        return flattenedList[curIdx++];
    }
    
    bool hasNext() {
        return curIdx < flattenedList.size();
    }
};