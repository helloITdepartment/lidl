class FrontMiddleBackQueue {
public:
    vector<int> bottomHalf;
    vector<int> topHalf;

    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        bottomHalf.insert(bottomHalf.begin(), val);
        rebalance();
    }
    
    void pushMiddle(int val) {
        bottomHalf.push_back(val);
        rebalance();
    }
    
    void pushBack(int val) {
        topHalf.push_back(val);
        rebalance();
    }
    
    int popFront() {
        if (bottomHalf.size()) {
            //pull first in bottom half
            int first = bottomHalf.front();
            //remove first in bottom half
            bottomHalf.erase(bottomHalf.begin());
            //rearrange if necessary
            rebalance();
            //return first
            return first;
        } else if (topHalf.size()) {
            //return first in top half
            int first = topHalf.front();
            //remove first in top half
            topHalf.erase(topHalf.begin());
            //rebalance if necessary
            rebalance();
            //return first
            return first;
        } else {
            return -1;
        }
    }
    
    int popMiddle() {
        if (topHalf.size() > bottomHalf.size()) {
            //return first in top half
            int middle = topHalf.front();
            //remove first in top half
            topHalf.erase(topHalf.begin());
            //rebalance if necessary
            rebalance();
            //return middle
            return middle;
        } else if (bottomHalf.size()) {
            //pull last in bottom half
            int middle = bottomHalf.back();
            //remove last in bottom half
            bottomHalf.pop_back();
            //rearrange if necessary
            rebalance();
            //return middle
            return middle;
        } else {
            return -1;
        }
    }
    
    int popBack() {
        if (topHalf.size()) {
            int last = topHalf.back();
            topHalf.pop_back();
            rebalance();
            return last;
        } else if (bottomHalf.size()) {
            int last = bottomHalf.back();
            bottomHalf.pop_back();
            rebalance();
            return last;
        } else {
            return -1;
        }
    }

    void rebalance() {
        int diff = topHalf.size() - bottomHalf.size();
        if (diff == 0 || diff == 1) {
            return;
        } else if (diff == 2) {
            //move from bottom of topHalf to top of bottomHalf
            bottomHalf.push_back(topHalf.front());
            topHalf.erase(topHalf.begin());
        } else if (diff == -1) {
            //move from top of bototmHalf to bottom of topHalf
            topHalf.insert(topHalf.begin(), bottomHalf.back());
            bottomHalf.pop_back();
        }
    }
};
