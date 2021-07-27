// https://leetcode.com/problems/design-browser-history/submissions/

class BrowserHistory {
public:
    string record[5000];
    int top_idx, current;
    
    BrowserHistory(string homepage) {
        record[0] = homepage;
        top_idx = 0;
        current = 0;
    }
    
    void visit(string url) {
        record[++current] = url;
        top_idx = current;
    }
    
    string back(int steps) {
        current = max(current-steps, 0);
        
        return record[current];
    }
    
    string forward(int steps) {
        current = min(current+steps, top_idx);
        
        return record[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
