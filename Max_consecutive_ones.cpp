/* ### 1. Brute Force

**Idea:**
Start from every index and count how many consecutive `1`s follow it. Keep track of the maximum count.

**Time:** O(n²)

---

### 2. Counting Streaks (Optimal)

**Idea:**
Traverse the array once.

* If current element is `1`, increase the streak count.
* If current element is `0`, reset the streak count.
* Update the maximum streak after every `1`.

**Time:** O(n)
**Space:** O(1)

---

### 3. Sliding Window / Two Pointers

**Idea:**
Maintain a window containing only `1`s.

* Extend the window while encountering `1`s.
* When a `0` appears, move the start of the window after that `0`.
* Track the largest window size.

**Time:** O(n)
**Space:** O(1)

---

### 4. Segment / Grouping Approach

**Idea:**
Treat each continuous block of `1`s as a segment.

* Find the length of every segment.
* Return the maximum segment length.

Example:

```text
1 1 0 1 1 1 0 1
```

Segments:

```text
[2], [3], [1]
```

Answer = `3`

**Time:** O(n)
**Space:** O(n) (if storing segment lengths)
*/

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Main Code 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
           if(nums[i]==1 ){
            count ++;
            maxcount = max(maxcount, count);
           }
           else{
            count = 0;
           }
        }
        return maxcount;
    }
};