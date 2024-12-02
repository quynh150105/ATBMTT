#include<iostream>

using namespace std;

int gcd(int a, int b){
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a== b)
		return a;
	if(a > b)
		return gcd(a-b,b);
	return gcd(a,b-a);
	
}

int modInverse(int a, int m){
	int m0 = m;
	int y = 0; int x = 1;
	
	if(m==1)
		return 0;
	
	while(a > 1){
		int q = a/m;
		int t = m;
		
		m = a % m;
		a = t;
		t = y;
		
		y = x - q*y;
		x = t;
	}
	
	if(x < 0)
		x += m0;
	return x;
	
}

int main(){
	int a, b,c,d;
	cout<<"a= ";cin>>a;
	cout<<"b= ";cin>>b;
	cout<<"c= ";cin>>c;
	cout<<"d= ";cin>>d;
	
	if(gcd(a,26)==1){
		if(c == modInverse(a,26) && d == b)
			cout<<"do la khoa giai ma!"<<endl;
		else
			cout<<"do khong la khoa giai ma!"<<endl;
	}
		
	return 0;
}