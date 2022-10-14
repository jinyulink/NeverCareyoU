priority_queue< int, vector<int>, less<int> > pq; 
//降排序
priority_queue< int, vector<int>, greater<int> > pq; 
//升排序

less<type>()    //从小到大排序 <
grater<type>()  //从大到小排序 >
less_equal<type>()  //  <=
gtater_equal<type>()//  >=

int numbers[]={20,40,50,10,30};
sort(numbers, numbers+5, greater<int>());