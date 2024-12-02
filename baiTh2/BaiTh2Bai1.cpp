#include<iostream>

using namespace std;

int gcd(int a, int b){
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a==b)
		return a;
	if(a>b)
		return gcd(a-b,b);
	return gcd(a,b-a);
	
}

int modInverse(int a, int m){
	int m0 = m;
	int y = 0;int x = 1;
	
	if(m == 1)
		return 0;
	
	while(a > 1){
		int q = a/m;
		int t = m;
		
		m = a % m; a = t;
		t = y;
		
		y = x-q*y;
		x = t;	
	}
	
	if(x < 0)
		x+= m0;		
	return x;	
	
}

int main(){
	int a, b;
	cout<<"a= ";cin>>a;
	cout<<"b= ";cin>>b;
	
	if(gcd(a,26) == 1){
		cout<<"ton tai khoa K(a^-1,b)!"<<endl;
		cout<<"K(a^-1,b): ("<<modInverse(a,26)<<","<<b<<")"<<endl;
	}
	else{
		cout<<"khong ton tai khoa giai ma!"<<endl;
	}
	
//	cout<<modInverse(a,m);
	return 0;
}