#include <bits/stdc++.h>
using namespace std;
int main()
{
	string com;
	cout << "enter the comment" << endl;
	cin >> com;
	int c = com.size();
	//	getline(com,stdin);
	if (com[0] == '/')
	{
		if (com[1] == '/')
		{
			cout << "it is a comment" << endl;
		}
		if (com[1] == '*')
		{
			if (com[c - 1] == '/' && com[c - 2] == '*')
			{
				cout << "it is a comment" << endl;
			}
			else
			{
				cout << "it is not a comment" << endl;
			}
		}
		else{
			cout<<"it is not a comment"<<endl;
		}
	}
	else
	{
		cout << "it is not a comment" << endl;
	}

	return 0;
}