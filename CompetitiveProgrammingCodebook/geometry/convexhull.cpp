凸包 O(NlogN) 
-------------------------------------------------------
vt<Point> arr; //存入所有點
arr=convex_hull(arr); //順時鐘 凸包點
-------------------------------------------------------
struct Point{
	double x, y;
	Point operator+(const Point& _p){
		return {(x+_p.x), (y+_p.y)};
	}
	Point operator-(const Point& _p){
		return {(x-_p.x), (y-_p.y)};
	}
	double operator^(const Point& _p){
		return {_p.x*y-x*_p.y};
	}
	bool operator<(const Point& _p){
		if(x==_p.x) return y<_p.y;
		return x<_p.x;
	}
};
double cross(Point o, Point a, Point b){
	return (a-o) ^ (b-o);
}
vector<Point> convex_hull(vector<Point> pt){
	sort(pt.begin(), pt.end());
	int top = 0;
	vector<Point> stk(2*pt.size());
	for(int i = 0; i<(int)pt.size();i++){
		while(top>=2&&cross(stk[top-2], stk[top-1], pt[i])<=0)
				top--;
		stk[top++] = pt[i];
	}
	for(int i=pt.size()-2,t=top+1;i>=0;i--){
		while(top>=t&&cross(stk[top-2],stk[top-1],pt[i])<=0)top--;
		stk[top++]=pt[i];
	}
	stk.resize(top-1);
	return stk;
}