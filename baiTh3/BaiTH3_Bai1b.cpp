#include<iostream>

using namespace std;

/*
//tim uoc chung lon nhat
int gcd(int a, int b){
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a==b)
		return a;
	if(a > b)
		return gcd(a-b,b);
	return gcd(a,b-a);	
}

//tim phan tu nghich dao / (zn = 26) a^-1 mod m
int modInverse(int a, int m){
	int m0 = m;
	int y = 0, x = 1;
	
	if(m==1)
		return 0;
	
	while(a > 1){
		int q = a/m;
		int t = m;
		
		m = a % m;
		a = t;
		t = y;
		
		y = x-q*y;
		x = t;
	}
	
	if(x < 0)
		x += m0;
	
	return x;
}
*/

//tạo khóa từ chuỗi đầu vào string key thành ma trận 3x3
void getKeyMatrix(string key,int keyMatrix[][3]){ // keyMatrix để lưu trữ khóa
	int k = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			keyMatrix[i][j] = (key[k]) % 65; // trừ đi 65 để lấy giá trị từ 0 đến 25
			k++;
		}
	}
}

// cipherMatrix[][]: ma trận lưu trữ kết quả mã hóa,
// keyMatrix[][3]: Ma trận khóa
// messageVector[][1]: vector thông điệp cần mã hóa
void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]){
	int x,i,j;
	for(int i = 0; i< 3; i++){
		for(int j = 0; j < 1; j++){
			cipherMatrix[i][j] = 0;
			for(x = 0; x < 3; x++){
				cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
			}
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

void HillCipher(string message, string key){
	int keyMatrix[3][3];
	getKeyMatrix(key,keyMatrix);
	
	int messageVector[3][1];
	for(int i = 0; i< 3; i++)
		messageVector[i][0] = (message[i]) % 65;
		
	int cipherMatrix[3][1];
	
	encrypt(cipherMatrix,keyMatrix,messageVector);	
	string CipherText;
	
	for(int i = 0; i< 3; i++)
		CipherText += cipherMatrix[i][0] + 65;
	
	cout<<"Cipher: "<<CipherText;
}

int main(){
	string message,key;
	cout<<"nhap message: ";
	getline(cin,message);
	cout<<"nhap key: ";
	getline(cin,key);
	HillCipher(message,key);
	return 0;
}