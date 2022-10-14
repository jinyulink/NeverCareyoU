cout << fixed << setprecision(2) << x << "\n"; 
//四捨五入到小數點後第2位
//fixed 取消科學記號
cout << ceil(x) << "\n";//無條件進位
cout.unsetf(ios::fixed);//關閉固定小數位格式
cout<<x<<endl;