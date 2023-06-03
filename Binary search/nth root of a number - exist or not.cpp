#include "header.h"
#define ll long long

class Solution{
	public:
	int NthRoot(int n, int m)
	{
	   ll l = 1;
	   ll h = m;
	   
	   while(l <= h) {
	       ll mid = (l + h)/2;
	       
	       //ll midToPowerN = pow(mid, n); // keeping this variable was not working
	       if (pow(mid, n) == m) {
	           return mid;
	       } else if (pow(mid, n)  > m) {
	           h = mid - 1;
	       } else {
	           l = mid + 1;
	       }
	   }
	   
	   return -1;
	}  
};