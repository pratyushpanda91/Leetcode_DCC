class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int e=0,w=0,cn=0,cs=0;
        int ans=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='E'){
                e++;
            }
            else if(c=='W'){
                w++;
            }else if(c=='N'){
                cn++;
                
            }else if(c=='S'){
                cs++;
            }
            int ne1=(e+cn) - (w+cs);
            int ne2=w+cs;
            int ne3=ne1+2*min(k,ne2);
            
            int nw1=(w+cn)-(e+cs);
            int nw2=e+cs;
            int nw3=nw1 + 2* min(k,nw2);
            
            int se1=(e+cs)-(w+cn);
            int se2=w+n;
            int se3=se1+2*min(k,se2);
            
            int sw1=(w+cs)-(e+cn);
            int sw2=e+n;
            int sw3=sw1+2*min(k,sw2);
            
            int best=max({ne3,nw3,se3,sw3});
            best=max(best,0);
            best=min(best,i+1);
            
            ans=max(ans,best);
        }
        return ans;
    }
};class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int e=0,w=0,cn=0,cs=0;
        int ans=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='E'){
                e++;
            }
            else if(c=='W'){
                w++;
            }else if(c=='N'){
                cn++;
                
            }else if(c=='S'){
                cs++;
            }
            int ne1=(e+cn) - (w+cs);
            int ne2=w+cs;
            int ne3=ne1+2*min(k,ne2);
            
            int nw1=(w+cn)-(e+cs);
            int nw2=e+cs;
            int nw3=nw1 + 2* min(k,nw2);
            
            int se1=(e+cs)-(w+cn);
            int se2=w+n;
            int se3=se1+2*min(k,se2);
            
            int sw1=(w+cs)-(e+cn);
            int sw2=e+n;
            int sw3=sw1+2*min(k,sw2);
            
            int best=max({ne3,nw3,se3,sw3});
            best=max(best,0);
            best=min(best,i+1);
            
            ans=max(ans,best);
        }
        return ans;
    }
};
