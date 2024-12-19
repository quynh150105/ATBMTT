#include<iostream>

using namespace std;

//tinh dinh thuc ma tran
int determinant(int K[2][2]) {
	return (K[0][0] * K[1][1] - K[0][1]*K[1][0]) % 26;
}

//tim phan tu nghich dao a^-1 mod 26
int modInverse(int a, int m) {
	a = a%m;
	for(int x = 1; x < m; x++) {
		if((a*x)%m == 1)
			return x;
	}
	return -1;//neu khong tim thay
}

// tim ma tran nghich dao 2x2
void inverseMatrix(int K[2][2], int invK[2][2], int detK_inv) {
	invK[0][0] =  K[1][1] * detK_inv % 26;
	invK[0][1] = -K[0][1] * detK_inv % 26;
	invK[1][0] = -K[1][0] * detK_inv % 26;
	invK[1][1] =  K[0][0] * detK_inv % 26;

	//dieu chinh gia tri trong [0,25]
	for(int i = 0; i< 2; i++) {
		for(int j = 0; j < 2; j++) {
			if(invK[i][j] < 0)
				invK[i][j] += 26;
		}
	}
}

// tao khoa tu chuoi dau vao và key
void getKeyMatrix(int keyMatrix[2][2]) {
	for(int i = 0; i< 2; i++) {
		for(int j = 0; j< 2; j++) {
			cin>>keyMatrix[i][j];
		}
	}
	cin.ignore();
}

// ma hoa
void encrypt(int cipherMatrix[][1],int keyMatrix[][2],int messageVector[][1]) {
	int x,i,j;
	for(int i = 0; i< 2; i++) {
		for(int j = 0; j< 1; j++) {
			cipherMatrix[i][j] = 0;
			for(x = 0; x < 2; x++)
				cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

bool check(string message,int keyMatrix[2][2], string cipher) {
	int messageVector[2][1];
	for(int i = 0; i< 2; i++)
		messageVector[i][0] = (message[i]) % 65;

	int cipherMatrix[2][1];
	encrypt(cipherMatrix,keyMatrix,messageVector);

	string CipherText;
	for(int i = 0; i< 2; i++)
		CipherText += cipherMatrix[i][0] + 65;

	return CipherText == cipher;
}

int main() {
	string message;
	string cipher; 
	int keyMatrix[2][2]; 
	getKeyMatrix(keyMatrix);
	cout<<"nhap xau 1: ";	                       
	cin>>message;
	cout<<"nhap xau 2: ";
	cin>>cipher; 
	if (check(message, keyMatrix, cipher)) 	   
		cout << "Ban da nhap DUNG.\n";
	else{
		cout<<"ban da nhap sai";
	}
	return 0;	                
}                      