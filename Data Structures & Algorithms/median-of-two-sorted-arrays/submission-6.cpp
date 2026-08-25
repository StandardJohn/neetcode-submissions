class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        int m = nums1.size(), n = nums2.size(), h = (m + n - 1) / 2;
        if (m == 0) {
            if (n == 0)
                return 0.0;
            else if (n % 2 == 0) 
                return (double)(nums2[n / 2 - 1] + nums2[n / 2]) / 2;
            else
                return (double)nums2[n / 2];
        }

        int l = 0, r = min(m, h), x = 0;
        while (l <= r) {
            x = l + (r - l) / 2;
            // cout << l << " " << r << " " << x << endl;
            int left1 = x == 0 ? INT_MIN : nums1[x - 1],
                right1 = x == m ? INT_MAX : nums1[x],
                left2 = h - x == 0 ? INT_MIN : nums2[h - x - 1],
                right2 = h - x == n ? INT_MAX : nums2[h - x];
            if (left1 > right2) {
                r = x - 1;
            }
            else if (left2 > right1) {
                l = x + 1;
            }
            else
                break;
        }

        // cout << "m = " << m << ", n = " << n << endl;
        // cout <<  "x = " << x << ", h - x = " << h - x << ", h = " << h << endl;
        if ((m + n) % 2 == 0) {
            int first = INT_MIN, second = INT_MIN;
            int i = x, j = h - x;
            while (i < m && j < n && i + j < h + 2) {
                if (nums1[i] <= nums2[j]) {
                    if (first == INT_MIN) {
                        first = nums1[i];
                    }
                    else {
                        second = nums1[i];
                    }
                    i++;
                }
                else {
                    if (first == INT_MIN) {
                        first = nums2[j];
                    }
                    else {
                        second = nums2[j];
                    }
                    j++;
                }
            }
            while (second == INT_MIN) {
                if (i < m) {
                    if (first == INT_MIN) {
                        first = nums1[i];
                    }
                    else {
                        second = nums1[i];
                    }
                    i++;
                }
                else if (j < n) {
                    if (first == INT_MIN) {
                        first = nums2[j];
                    }
                    else {
                        second = nums2[j];
                    }
                    j++;
                }
            }
            return (double) (first + second) / 2;
        }
        else {
            if (x == m)
                return nums2[h - x];
            return min(nums1[x], nums2[h - x]);
        }
    }
};
