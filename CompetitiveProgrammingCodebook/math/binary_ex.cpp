O(logn)的時間計算a^b的方法(a^b%m)
-------------------------------------------------------
long long binpow(long long a,long long b){//long long m
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;//res = res * a % m;
        a = a * a;//a = a * a % m;
        b >>= 1;
    }
    return res;
}