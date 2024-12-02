#include<bits/stdc++.h>

using namespace std;

//#define N 101 // prime modulo value

// base ^ exp mod N

/* Cach 1: de quy
long int exponentiation(long int base, long int exp, long int N){
	if(exp ==0 )
		return 1;
		
	if(exp == 1)
		return base % N;
		
	long int t = exponentiation(base, exp/2);
	t = (t*t)%N;
	
	//if exponent is even value
	if(exp %2 ==0)
		return t;
		
	//if exponent is odd value
	else
		return ((base%N)*t) %N;
	
}
*/

// Cach 2: khong de quy

long exponentiation(long base, long exp, long N){
	long t = 1L;
	while(exp > 0){
		//for cases where exponent
		//is not an even value
		if(exp %2 !=0)
			t = (t*base) % N;
		
		base = (base*base) %N;
		exp /= 2;	
	}
	return t % N;
}

int main(){
	long base, exp, N;
	cout<<"Base= ";cin>>base;
	cout<<"exp= ";cin>>exp;
	cout<<"N= ";cin>>N;
	long int modulo = exponentiation(base,exp,N);
	cout<<modulo<<endl;
	return 0;
}