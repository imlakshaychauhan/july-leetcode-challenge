// https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    static bool comp(const vector<int> &v1, const vector<int> &v2) {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0, n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), comp);
        for(int i = 0; i < n; i++) {
            int numOfBoxes = boxTypes[i][0];
            int numOfUnits = boxTypes[i][1];
            if(numOfBoxes <= truckSize) {
                truckSize -= numOfBoxes;
                ans += (numOfBoxes * numOfUnits);
            }
            else if(numOfBoxes > truckSize) {
                ans += (truckSize * numOfUnits);
                break;
            }
        }
        return ans;
    }
};