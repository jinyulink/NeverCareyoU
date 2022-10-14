O(log min(a,b)) 找最大公因數
-------------------------------------------------------
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}