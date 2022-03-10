#two-sum problem

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}                # creating a hashmap
        for i in range(len(nums)):  
            hashmap[nums[i]] = i    # setting values of array as the key, the index as the value
            print(hashmap)          
        for i in range(len(nums)):  
            complement = target - nums[i]   # find the complement by subtracting each value in the array from the target
            if complement in hashmap and hashmap[complement] != i:  # look for complement as a key, make sure it's not the value itself
                return [i, hashmap[complement]] 
