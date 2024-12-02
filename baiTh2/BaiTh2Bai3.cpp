#include<iostream>

using namespace std;

int gcd(int a, int b);
int modInverse(int a, int m);
string encryptMessage(string msg, int a, int b);
string decryptMessage(string msg, int a, int b);

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
	int y = 0; 
	int x = 1;
	
	if(m==1){
		return 0;
	}
	
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


string encryptMessage(string msg, int a, int b){
	string cipher = "";
	for(int i = 0; i<msg.length(); i++){
		if(msg[i] != ' ')
			cipher = cipher + (char)((((a * (msg[i] - 'A') ) + b)% 26) + 'A');
		else
			cipher += msg[i];
	}
	return cipher;
}

string decryptMessage(string msg, int a , int b){
	string cipher = "";
	int a_inv = 0;
	int flag = 0;
	
	for(int i = 0; i< 26; i++){
		flag = (a * i)%26;
		
		if(flag == 1)
			a_inv = i;
	}
	
	for(int i = 0; i< cipher.length(); i++){
		if(cipher[i] != ' ')
			msg = msg + (char)(((a_inv * ((cipher[i] + 'A' - b)) %26 )) + 'A');
		else
			msg += cipher[i];
	}
	return msg;
	
}


int main(){
	int a;int b;
	do{
		cout<<"nhap khoa K(a,b): "<<endl;
		cout<<"a= ";cin>>a;
		cout<<"b= ";cin>>b;
	}
	while(gcd(a,26) != 1);
	cin.ignore();
	string cipher;
	cout<<"Nhap chuoi msg: ";
	getline(cin,cipher);
	cout<<"encrypt Message: " <<encryptMessage(cipher, a,b)<<endl;
	cout<<"dencrypt Message: " <<decryptMessage(cipher, a,b)<<endl;

	return 0;
}