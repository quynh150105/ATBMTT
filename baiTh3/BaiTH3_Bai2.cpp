#include<iostream>

using namespace std;

//tinh dinh thuc ma tran
int determinant(int K[2][2]){
	return (K[0][0] * K[1][1] - K[0][1]*K[1][0]) % 26;
}

//tim phan tu nghich dao a^-1 mod 26
int modInverse(int a, int m){
	a = a%m;
	for(int x = 1;x < m; x++){
		if((a*x)%m == 1)
			return x;
	}
	return -1;//neu khong tim thay
}

// tim ma tran nghich dao 2x2
void inverseMatrix(int K[2][2], int invK[2][2], int detK_inv){
	invK[0][0] =  K[1][1] * detK_inv % 26;
	invK[0][1] = -K[0][1] * detK_inv % 26;
	invK[1][0] = -K[1][0] * detK_inv % 26;
	invK[1][1] =  K[0][0] * detK_inv % 26;
	
	//dieu chinh gia tri trong [0,25]
	for(int i = 0; i< 2; i++){
		for(int j = 0; j < 2; j++){
			if(invK[i][j] < 0)
				invK[i][j] += 26;
		}
	}
}

int main(){
	int K[2][2];
	int invK[2][2];
	//nhap K tu ban phim
	for(int i = 0; i< 2; i++){
		for(int j = 0; j < 2; j++){
			cin>>K[i][j];
		}
	}
	
	//tinh dinh thuc K
	int detK = determinant(K);
	if(detK < 0)
		detK += 26;
	
	//tim phan tu nghich dao
	int detK_inv = modInverse(detK,26);
	if(detK_inv == -1){
		cout<<"khong ton tai khoa giai ma!";
		return 0;
	}
	
	//tinh ma tran nghich dao
	inverseMatrix(K,invK,detK_inv);
	
	cout<<"Khoa giai ma la: "<<endl;
	for(int i= 0; i< 2; i++){
		for(int j = 0; j< 2; j++){
			cout<<invK[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}