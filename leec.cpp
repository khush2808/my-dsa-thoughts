#include <bits/stdc++.h>
using namespace std;

vector<long long> sieve(long long limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<long long> primes;

    is_prime[0] = is_prime[1] = false;

    for (long long p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            for (long long multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
            primes.push_back(p*p);
        }
    }
    return primes;
}

bool isTripletExist(vector<long long> &nums, long long target)
{
    long long n = nums.size();
    unordered_map<long long, long long> map;
 
    for (long long i = 0; i < n; i++) {
        map[nums[i]] = i;
    }

    for (long long i = 0; i < n - 1; i++)
    {
        for (long long j = i + 1; j < n; j++)
        {
            long long val = target - (nums[i] + nums[j]);
            if (map.find(val) != map.end())
            {
                if (map[val] != i && map[val] != j) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    vector<long long> primes = sieve(sqrt(n)+1);
    	if(isTripletExist(primes , n)){
    	    cout<<"Yes\n";
    	}
    	else{
    	    cout<<"No\n";
    	}
	    
	}

}