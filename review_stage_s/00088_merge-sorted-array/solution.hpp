#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_ptr = 0;
        int nums2_ptr = 0;
        queue<int> nums1_wait_que;
        int i;
        for (i = 0; i < m+n; ++i) {
            if (nums1_ptr >=m || nums2_ptr >= n) break;
            if (nums1_wait_que.empty()) {
                if (nums1.at(nums1_ptr) > nums2.at(nums2_ptr)) {
                    nums1_wait_que.push(nums1.at(nums1_ptr));
                    nums1.at(nums1_ptr++) = nums2.at(nums2_ptr++);
                }
                else ++nums1_ptr;
            } else {
                if (nums1_wait_que.front() > nums2.at(nums2_ptr)) {
                    nums1_wait_que.push(nums1.at(nums1_ptr));
                    nums1.at(nums1_ptr++) = nums2.at(nums2_ptr++);
                }
                else {
                    nums1_wait_que.push(nums1.at(nums1_ptr));
                    nums1.at(nums1_ptr++) = nums1_wait_que.front();
                    nums1_wait_que.pop();
                }
            }
        }
        if (nums1_ptr >= m) {
            while (!nums1_wait_que.empty() && nums2_ptr < n) {
                if (nums1_wait_que.front() > nums2.at(nums2_ptr))
                    nums1.at(nums1_ptr++) = nums2.at(nums2_ptr++);
                else {
                    nums1.at(nums1_ptr++) = nums1_wait_que.front();
                    nums1_wait_que.pop();
                }
            }
            if (nums1_wait_que.empty())
                while (nums2_ptr < n) nums1.at(nums1_ptr++) = nums2.at(nums2_ptr++);
            else {
                while (!nums1_wait_que.empty()) {
                    nums1.at(nums1_ptr++) = nums1_wait_que.front();
                    nums1_wait_que.pop();
                }
            }
        } else {
            for (int i=0;i<m-nums1_ptr;++i) {
                nums1[m+n-1-i] = nums1[m-1-i];
            }
            while (!nums1_wait_que.empty()) {
                nums1[nums1_ptr++] = nums1_wait_que.front();
                nums1_wait_que.pop();
            }
        }
    }
};
