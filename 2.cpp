class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int mh = max(hc[0] - 0, h - hc[hc.size() - 1]);
        for(int i = 1; i < hc.size(); i++) 
            mh = max(mh, hc[i] - hc[i - 1]);
        
        int mv = max(vc[0] - 0, w - vc[vc.size() - 1]);
        for(int i = 1; i < vc.size(); i++)
            mv = max(mv, vc[i] - vc[i - 1]);
        
        long ans = 1L * mh * mv;
        return (int) (ans % (1000000007));
    }
};