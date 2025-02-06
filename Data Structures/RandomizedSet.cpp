/**
 * @author : Rohit
 * @date   : 2025-01-29  // (Ensure to update dynamically)
 * @problem: Insert Delete GetRandom O(1)
 * @link   : https://leetcode.com/problems/insert-delete-getrandom-o1/
 * @level  : Medium
 *
 * @description
 * This class implements a **RandomizedSet** that supports three operations in **O(1)** time:
 * 1. **Insert(val)**: Inserts `val` if it's not already present.
 * 2. **Remove(val)**: Removes `val` if it exists.
 * 3. **getRandom()**: Returns a random element from the set.
 *
 * @approach
 * - **Efficient Lookup & Deletion with `unordered_map<int, int>`:**
 *   - Stores **value-to-index mappings** for quick access.
 * - **Vector `vec<int>` for O(1) random access:**
 *   - Stores elements for fast retrieval and swaps for O(1) deletion.
 * - **How Deletion is O(1)**:
 *   - Swap the last element with the one to be removed, update its index in `mpp`, and pop back.
 *   - This avoids costly shifting operations in vectors.
 *
 * @complexity
 * - **Time Complexity:** O(1) for `insert`, `remove`, and `getRandom()`.
 * - **Space Complexity:** O(n) (where `n` is the number of elements).
 *
 * @example
 * **Input:**
 * RandomizedSet* obj = new RandomizedSet();
 * obj->insert(1);   // Returns true (inserted successfully)
 * obj->remove(2);   // Returns false (not found)
 * obj->insert(2);   // Returns true
 * obj->getRandom(); // Returns either 1 or 2 randomly
 * obj->remove(1);   // Returns true
 * obj->getRandom(); // Returns 2 (as 1 is removed)
 *
 * **Output:**
 * [true, false, true, 1/2, true, 2]
 */

class RandomizedSet
{
public:
    vector<int> vec;
    unordered_map<int, int> mpp;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mpp.find(val) != mpp.end())
            return false;

        vec.push_back(val);
        mpp[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (mpp.find(val) == mpp.end())
            return false;

        int idx = mpp[val];
        int lastEl = vec.back();
        vec.back() = val;

        vec[idx] = lastEl;
        mpp[lastEl] = idx;

        vec.pop_back();
        mpp.erase(val);
        return true;
    }

    int getRandom()
    {
        int n = vec.size();
        int randomIndex = rand() % n;
        return vec[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */