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
            if (nums1[max(0, x - 1)] > nums2[min(n - 1, h - x)]) {
                r = x - 1;
            }
            else if (nums2[max(0, h - x - 1)] > nums1[min(m - 1, x)]) {
                l = x + 1;
            }
            else
                break;
        }

        // cout << "m = " << m << ", n = " << n << endl;
        // cout <<  "x = " << x << ", h - x = " << h - x << ", h = " << h << endl;
        if ((m + n) % 2 == 0) {
            vector<int> res;
            int i = x, j = h - x;
            while (i < m && j < n && i + j < h + 2) {
                if (nums1[i] <= nums2[j]) {
                    res.push_back(nums1[i]);
                    i++;
                }
                else {
                    res.push_back(nums2[j]);
                    j++;
                }
            }
            while (res.size() < 2) {
                if (i < m) {
                    res.push_back(nums1[i]);
                    i++;
                }
                else if (j < n) {
                    res.push_back(nums2[j]);
                    j++;
                }
            }
            double median = 0.0;
            for (int i : res) {
                median += i;
            }
            return (double) median / 2;
        }
        else {
            if (x == m)
                return nums2[h - x];
            return min(nums1[x], nums2[h - x]);
        }
    }
};
