#include<bits/stdc++.h>

using namespace std;

main(){
  long long n;
  int q;
  long long maxElement=0,sum=0;
  cin>>n>>q;
  
  vector< pair<long long,long> > query; //stores the index, value pairs in each query
 
  //Let us consider the array to be filled with only zeroes initially (a[i]=0)
  //The queries are processed in such a way that a[i] will be the prefix sum of the array elements
  // (sum of elements from 1st to ith position). This can be achieved by storing the queries in the 
  // form of (lower index,value) and (upper index + 1,-value) pairs. Intially all elements are zero.
  // After processing the first query, elements in positions lower index to upper index will be equal to value 
  // because a[i] is the prefix sum and elements before lower index and after upper index will be 0
  //(because we stored -value in  upper index+1 so prefix sum becomes 0 again). 
  // Since n can be very large we can only traverse the vector of queries.
  
  for(int i=0; i<q; i++){
  	
	  long long L,R;
	  long v;
  	  cin>>L>>R>>v;
  	  query.push_back(make_pair(L,v));
  	  query.push_back(make_pair(R+1,-v));
  }
  
  //This is done to consider the case when all queries are on indices less than the size of the array
  //(so as to consider the elements after the maximum upper bound in all queries put together - 
  // to consider all the elements of the array basically)
  
  if(query[query.size()-1].first < n+1)
    query.push_back(make_pair(n+1,0));
    
  //Sorting (index,value) pairs based on index 
  sort(query.begin(),query.end());
  
  //Variable to store prefix sum
  sum=0;
  
  //Now the vector of (index,value) pairs denote the sets of elements that have the same value
  // in the a[i]=0 array. So if queries stores (2,2),(4,-2),(4,3),(5,-3),(5,5),(6,-5) 
  // altered array is 0,2,2,3,5 which means the elements between the indices of two successive queries have the same value.
  // But since our actual array is such that a[i]=i we will have to consider the value stored in the last index of that set
  // as in if queries are (2,2),(4,-2) we will have to consider the element at 3rd position while processing the first
  // pair as a candidate for maxElement (in a[i]=i array) because that is the maximum value in that set.
  // So basically we consider the maximum value in each sets of elements between two queries and 
  // compare all such maximums in all sets.
   
  for(int i=0; i+1<query.size(); i++){
  
  	sum += query[i].second; //prefix sum value in a[i]=0 array
  	
  	//Finding maximum value in each set. We consider the max value in each set of elements since we did not account for a[i]=i before.
  	// We can't disturb sum value because it computes the prefix sum values assuming the array is a zero array.
  	// Only while computing maxElement, a[i]=i is taken into account. 
	// Everywhere else a[i]=0 is considered as the initial array
  	
  	if(query[i+1].first==query[i].first)
  	   	maxElement = max(maxElement, sum+query[i].first );
  	else
	    maxElement = max(maxElement, sum+query[i].first + (query[i+1].first-query[i].first-1));
  }
  
  //Maximum element in the altered array
  cout<<maxElement;
}
