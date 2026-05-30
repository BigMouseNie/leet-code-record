#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_ptr = m-1;
        int nums2_ptr = n-1;
        int total_ptr = m+n-1;

        while (total_ptr >= 0) {
            if (nums1_ptr < 0) nums1[total_ptr--] = nums2[nums2_ptr--];
            else if (nums2_ptr < 0) nums1[total_ptr--] = nums1[nums1_ptr--];
            else if (nums1[nums1_ptr] > nums2[nums2_ptr]) nums1[total_ptr--] = nums1[nums1_ptr--];
            else nums1[total_ptr--] = nums2[nums2_ptr--];
        }
    }
};
