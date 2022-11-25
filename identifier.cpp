#include<bits/stdc++.h>
using namespace std;
int main(){
	// keyword list
	string Keys[]={"int","main","double","float","char","string","long","max","min","exit"}; // will add more later
	string s;
	cout<<"enter a valid identifier"<<endl;
	cin>>s;
	bool flag;
	// first letter should be letter
	if(isalpha(s[0])||s[0]=='_'){
		flag=true;
	}else{
		cout<<"not a valid identifier"<<endl;
	}
	// checking for special characters
	int count=s.size();
	while(count--){
		if(!isalpha(s[count])&&!isdigit(s[count])&&s[count]!='_'){
			flag=false;
			break;
		}
	}
	// checking for a keyword
	for(auto e:Keys){
		if(e==s){
			flag=false;
		}
	}
	if(flag==true){
		cout<<"it is valid identifier"<<endl;
	}else{
		cout<<"it is not a valid identifier"<<endl;
	}
	return 0;
}