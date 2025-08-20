class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //The median element of two arrays of size m and n will be the (m+n)/2 smallest element between the two of them
        //Walk through both arrays, stepping only on the one with the current smallest element, until (m+n)/2 steps have been taken
        int m = nums1.size(), n = nums2.size();
        int totalSize = m + n;
        int targetIndex = totalSize/2;
        int lower1 = 0, lower2 = 0;
        int lastLowest;
        
        while (lower1 + lower2 < targetIndex) {
            if (lower1 < m && lower2 < n) { //Both arrays are still in bounds
                if (nums1[lower1] < nums2[lower2]) {
                    // total[totalIndex] = nums1[lower1];
                    lastLowest = nums1[lower1];
                    lower1++;
                } else {
                    // total[totalIndex] = nums2[lower2];
                    lastLowest = nums2[lower2];
                    lower2++;
                }
            } else if (lower1 >= m) { //nums1 out of bounds, only advance nums2
                // total[totalIndex] = nums2[lower2];
                lastLowest = nums2[lower2];
                lower2++;
            } else { //nums2 out of bounds, only advance nums1
                // total[totalIndex] = nums1[lower1];
                lastLowest = nums1[lower1];
                lower1++;
            }
        }

        if (totalSize % 2 == 1) { //Combined arrays will have single middle element
            if (lower1 < m && lower2 < n) { //Both arrays are still in bounds
                return min(nums1[lower1], nums2[lower2]);
            } else if (lower1 >= m) { //nums1 out of bounds, return from nums2
                return nums2[lower2];
            } else { //nums1 out of bounds, return from nums2
                return nums1[lower1];
            }
        } else { //Even number of elements, need to average middle two
            if (lower1 < m && lower2 < n) { //Both arrays are still in bounds
                return (min(nums1[lower1], nums2[lower2]) + lastLowest)/2.0;
            } else if (lower1 >= m) { //nums1 out of bounds, return from nums2
                return (nums2[lower2] + lastLowest)/2.0;
            } else { //nums1 out of bounds, return from nums2
                return (nums1[lower1] + lastLowest)/2.0;
            }
        }
    }
};
