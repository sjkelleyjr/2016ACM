#include <iostream>

using namespace std;

int PP;

//int move(string map, int loc, int size){
//	cout << loc << endl;
//	//CHECK SIZE - 1
//	if(loc > (size-1) || loc < 0){
//		return -1;
//	}
//	if(map[loc] == '-'){
//		return loc;
//	}
//	//left first
//	int right = move(map,loc++,size);
//	int left  = move(map,loc--,size);
//	if(abs(PP - right) > abs(PP-left)){
//		return right;
//	}else{
//		return left;
//	}
//}
int move(string map, int loc, int size){
	int left = -999999;
	int right = -999999;
	for(int i = loc;i>0;i--){
		if(map[i]=='-'){
			left = i;
			break;
		}

	}
	//check the minus 1
	for(int i = loc;i<size;i++){
		if(map[i]=='-'){
			right = i;
			break;
		}
	}
	if(PP-left<=right-PP){
		return left;
	}else{
		return right;
	}
}

int main(){
	int size;
	int playerPos;
	string map;
	cin >> size;
	cin >> playerPos;
	playerPos--;
	PP = playerPos;
	for(int i = 0;i <size;i++){
		cin >> map[i];
	}
	int mv = move(map,playerPos,size);
	if(mv>playerPos){
		cout << "RIGHT";
	}else if(mv == playerPos){
		cout << "SAFE";
	}
	else{
		cout << "LEFT";
	}
}
