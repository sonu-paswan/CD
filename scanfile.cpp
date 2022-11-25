// write a c program to scan word line and character in a sentence 
#include<bits/stdc++.h>
using namespace std;
int main(){
	FILE *file;
	char path[100];
	char ch;
	int characters,words,lines;
	
	// input source file path
	cout<<"enter source file path: ";
	scanf("%s",path);
	
	//open source file in read mode
	file=fopen(path,"r");
	
	// check if file opened successfully 
	if(file==NULL){
		cout<<"unable to open file"<<endl;
		exit(1);
	}
	
	//logic to count characters, words and lines
	characters=words=lines=0;
	while((ch=fgetc(file))!=EOF){
		characters++;
		//check line
		if(ch=='\n'||ch=='\0')
		lines++;
		//check words
		if(ch==' '||ch=='\t'||ch=='\n'||ch=='\0')
		words++;
	}
		//increment words and lines for last word
		if(characters>0){
			words++;
			lines++;
		}
		// print file statistics
		cout<<endl;
		cout<<"total characters: "<<characters<<endl;
		cout<<"total words: "<<words<<endl;
		cout<<"total lines: "<<lines<<endl;
		
		// close the open file 
		fclose(file);
		return 0;
}