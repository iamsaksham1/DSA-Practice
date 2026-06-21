// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
//Return the array in the form [x1,y1,x2,y2,...,xn,yn].

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>res;
        for(int i=0; i<n; i++){
            res.push_back(nums[i]);
            res.push_back(nums[i+n]);
        }
        return res;
    }
};


/*
## Approaches

### 1. Extra Array Approach (Most Intuitive)
**Idea:** Create a new array and alternately insert elements from the first half (`x`) and second half (`y`) of the array.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 2. Two Pointer Approach
**Idea:** Use two pointers:
- `i = 0` for the first half (`x` values)
- `j = n` for the second half (`y` values)

Insert elements alternately into the result array.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### 3. Bit Manipulation (In-Place)
**Idea:** Store both the old and new values in the same array element using bit manipulation, then extract the required values later.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 4. Mathematical Encoding (In-Place)
**Idea:** Encode two numbers into a single array element using multiplication and modulo operations, then decode them after rearrangement.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 5. Queue-Based Approach
**Idea:** Store the first half and second half of the array in separate queues and then dequeue alternately to build the shuffled array.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)
*/

