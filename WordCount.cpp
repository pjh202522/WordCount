#include<iostream>
using namespace std;

FILE* readFile(string filePath);
int countChars(string filePath);
int countWords(string filePath);

int main() {
	string op;
	string filePath;
	cout<<"请选择统计模式:<-c|-w>并输入文件路径\n";
	cin>>op>>filePath;
	
	int result = 0;
	if(op == "-c") {
		if((result = countChars(filePath)) != -1) 
			cout<<"经统计，共有 "<<result<<" 个字符。"<<endl;
	} else if(op == "-w") {
		if((result = countWords(filePath)) != -1) 
			cout<<"经统计，共有 "<<result<<" 个单词。"<<endl;
	} else {
		cout<<"Error Input!";
	}
	return 0;
}

FILE* readFile(string filePath) {
	FILE* file;
	if((file = fopen(filePath.data(), "r")) == NULL) {
		cout<<"File not find!";
		return NULL;
	}
	return file;
}

int countChars(string filePath) {
	FILE* file;
	if((file = readFile(filePath)) == NULL) {
		return -1;
	}
	int count = 0;
	char ch;
	while((ch = fgetc(file)) != EOF) {
		if(isalnum(ch) || ch == 9 || ch == 10 || ch == 32) count++; 
	}
	return count;
}

int countWords(string filePath) {
	FILE* file;
	if((file = readFile(filePath)) == NULL) {
		return -1;
	}
	int count = 0, tmp = 0;
	char ch;
	while((ch = fgetc(file)) != EOF) {
		if(isalpha(ch)) tmp++;
		else if(tmp > 0) tmp = 0, count++;
	}
	if(tmp > 0) count++;
	return count;
}
