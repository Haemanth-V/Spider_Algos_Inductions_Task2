#include<bits/stdc++.h>

using namespace std;

main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		string str;
		cin>>str;
		
		//Logic : Let '<' denote +1 and '>' denote -1
		// We traverse the string and add +1 or -1 to tagSum depending on the tag
		// Whenever sum=0 there is a proper prefix, we store its length in longestPrefix.
		// If at some point sum<0 then we should stop traversing the string
		// because there can't be anymore proper prefixes
		
		int tagSum = 0,longestPrefix = 0;
		for(int j=0; j<str.length(); j++){
		   if(str[j]=='<')
		      tagSum++;
		    else tagSum--;
		    if(tagSum < 0)
		       break;
		    else if(tagSum==0)
		       longestPrefix = j+1;
		}
		cout<<longestPrefix<<"\n";
	}
}

