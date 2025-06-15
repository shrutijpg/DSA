class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int Lmax=0,Rmax=0;
        long long total=0;
        long l=0;
        long r=n-1;
        while(l<r){
            if(height[l]<height[r]){
                if(Lmax>height[l]){
                    total+= Lmax-height[l];
                }
                else{
                    Lmax = height[l];
                }
                l = l+1;
            }
            else{
                if(Rmax>height[r]){
                    total+= Rmax-height[r];
                }
                else{
                    Rmax = height[r];
                }
                r = r-1;
            }
        }
        return total;

    }
};