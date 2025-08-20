class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Combine both arrays by creating a new one... 
        int totalSize = nums1.size() + nums2.size();
        int total[totalSize];
        int lower1 = 0;
        int lower2 = 0;
        int totalIndex = 0;

        //and starting at the beginning of the original two, inserting whichever value of the two is lower, then moving ahead
        //Since the originaly two were already sorted the new array will be sorted
        while (lower1 < nums1.size() || lower2 < nums2.size()) {
            if (lower1 < nums1.size() && lower2 < nums2.size()) {
                if (nums1[lower1] < nums2[lower2]) {
                    total[totalIndex] = nums1[lower1];
                    lower1++;
                } else {
                    total[totalIndex] = nums2[lower2];
                    lower2++;
                }
            } else if (lower1 >= nums1.size()) {
                total[totalIndex] = nums2[lower2];
                lower2++;
            } else {
                total[totalIndex] = nums1[lower1];
                lower1++;
            }
            totalIndex++;
        }

        //Jump to the middle of the array and return the value (or average of middle values)
        if (totalSize % 2 == 1) {
            return total[totalSize/2];
        } else {
            return (total[totalSize/2-1] + total[totalSize/2])/2.0;
        }
    }
};
