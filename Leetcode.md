#### 1. [找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)

```c++
class Solution{
public:
    vector<int> findAnagrams(string s, string p){
        if(s.size() < p.size())
            return vector<int>({});
        
        int left=0, right=0, match = 0;
        vector<int> count;
        unordered_map<char, int> window, needs;
        for(char c: p) needs[c]++;
        
        while(right < s.size()){
            char c = s[right];
            if(needs.count(c)){
                window[c]++;
                if(window[c] == needs[c]){
                    match++;
                }
            }
            right++;
            
            while(match == needs.size()){
                if(right - left == p.size()){
                    count.push_back(left);
                }
                
                char c2 = s[left];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }
        return count;
    }
};
```



#### 2. [最短无序连续子数组](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)

```c++
class Solution{
public:
    int findUnsortedSubarray(vector<int>& nums){
        stack<int> asc, desc;
        int left = nums.size(), right = 0;
        for(int i=0; i<nums.size(); i++){
            while(!asc.empty() && nums[asc.top()] > nums[i]){
                left = min(left, asc.top());
                asc.pop();
            }
            asc.push(i);
            
        }
        
        for(int j=nums.size()-1; j>=0; j--){
            while(!desc.empty() && nums[desc.top()] < nums[j]){
                right = max(right, desc.top());
                desc.pop();
            }
            desc.push(j);
        }
        return right - left < 0 ? 0 : right - left + 1;
    }
};

/*class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = nums.size(), right = 0;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i; j <nums.size(); j++){
                if(nums[j] < nums[i]){
                    right = max(right, j);
                    left = min(left, i);
                }
            }
        }
        //cout << left << " " << right << endl;
        return right - left < 0 ? 0 : right - left + 1;
    }
};*/
```

