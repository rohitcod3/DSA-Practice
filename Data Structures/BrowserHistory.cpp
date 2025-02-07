/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Ensure to update dynamically)
 * @problem: Design Browser History
 * @link   : https://leetcode.com/problems/design-browser-history/
 * @level  : Medium
 *
 * @description
 * This class **implements a browser history system** where users can:
 * 1. **visit(url)** → Visit a new page (clears forward history).
 * 2. **back(steps)** → Move back `steps` times (if possible).
 * 3. **forward(steps)** → Move forward `steps` times (if possible).
 *
 * @approach
 * - **Uses two stacks (`past` and `future`)** to efficiently track history.
 * - `curr` stores the **current webpage**.
 * - **Stack-based navigation**:
 *   - **Visiting a new page**:
 *     - Push current `curr` into `past`, update `curr`, and clear `future` (no redo after new visit).
 *   - **Back operation**:
 *     - Moves back up to `steps`, popping from `past` and pushing into `future`.
 *   - **Forward operation**:
 *     - Moves forward up to `steps`, popping from `future` and pushing into `past`.
 *
 * @complexity
 * - **Time Complexity:** O(steps) for `back()` and `forward()`, O(1) for `visit()`.
 * - **Space Complexity:** O(n), where `n` is the number of visited URLs.
 *
 * @example
 * **Input:**
 * ```
 * BrowserHistory* obj = new BrowserHistory("leetcode.com");
 * obj->visit("google.com");
 * obj->visit("facebook.com");
 * obj->visit("youtube.com");
 * cout << obj->back(1);  // "facebook.com"
 * cout << obj->back(1);  // "google.com"
 * cout << obj->forward(1);  // "facebook.com"
 * obj->visit("linkedin.com");
 * cout << obj->forward(2);  // "linkedin.com" (can't move forward)
 * cout << obj->back(2);  // "google.com"
 * ```
 *
 * **Output:**
 * ```
 * facebook.com
 * google.com
 * facebook.com
 * linkedin.com
 * google.com
 * ```
 */

class BrowserHistory
{
public:
    stack<string> past;
    stack<string> future;

    string curr;

    BrowserHistory(string homepage)
    {
        curr = homepage;
    }

    void visit(string url)
    {
        past.push(curr);
        curr = url;

        future = stack<string>();
    }

    string back(int steps)
    {
        while (steps > 0 && !past.empty())
        {
            future.push(curr);
            curr = past.top();
            past.pop();
            steps--;
        }
        return curr;
    }

    string forward(int steps)
    {
        while (steps > 0 && !future.empty())
        {
            past.push(curr);
            curr = future.top();
            future.pop();
            steps--;
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */