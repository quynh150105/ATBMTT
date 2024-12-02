#include<bits/stdc++.h>

using namespace std;

int modInverse(int a, int m){
	//a^-1 mod m
	int m0 = m;
	int y = 0, x = 1;
	
	if(m == 1)
		return 0;
		
	while(a > 1){
		// q is quotient
		int q = a/m;
		int t = m;
		
		// m is remainder now, process same as
		// Euclid's algo
		m = a % m, a = t;
		t = y;
		
		//Update y and x
		y = x-q*y;
		x = t;
	}
	
	// make x positive
	if(x < 0)
		x += m0;
	return x;
}

int main(){
	int a,m;
	cout<<"a= ";cin>>a;
	cout<<"m= ";cin>>m;
	cout<<"Modular multiplicative inverse is: " << modInverse(a,m);
	return 0;
}