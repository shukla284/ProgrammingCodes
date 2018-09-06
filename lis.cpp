#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

#define vcll vector<long long>
#define vcii vector<int>
#define var auto

int getLIS(vcll num,vcii &prnt,vcii &incs){
	var len=0;
	for(var i=0;i<num.size();i++){
		var lo=1,hi=len;
		while(lo<=hi){
			var mid=ceil((lo+hi)/2);
			if(num[incs[mid]]<num[i])
			   lo=mid+1;
			else
			   hi=mid-1;   
		}
		var pos=lo;
		prnt[i]=incs[pos-1];
		incs[pos]=i;
		len=max(len,pos);
	}
	return len;
}
void printLIS(vcll num,vcii &prnt,vcii &incs){
	var len=getLIS(num,prnt,incs);
	vcii lis(len);
	var idx=incs[len];
	for(var x=len-1;x>=0;x--){
		lis[x]=num[idx];idx=prnt[idx];
	}
	cout<<"Length "<<len<<" elements "<<endl;
	for(var x:lis) cout<<x<<" ";
	return;
}
int main(int argc,char** argv){
	int n;cin>>n;vcll num(n);
	for(var x=0;x<n;x++) cin>>num[x];
	vcii prnt(n);vcii incs(n);

    //cout<<getLIS(num,prnt,incs);
	printLIS(num,prnt,incs);
	return 0;
}
