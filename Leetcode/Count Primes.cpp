class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<bool> sieve(n+1,0);
        int ans=1;
        for(int i=3;i<=n;i+=2)sieve[i]=1;
        for(long long i=3;i<=n;i+=2){
            if(sieve[i]){
                ans++;
                for(long long j=i*i;j<=n;j+=2*i)sieve[j]=0;
            }
        }
        return ans-sieve[n];
    }
};
