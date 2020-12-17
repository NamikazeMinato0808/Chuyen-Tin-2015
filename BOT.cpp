#include <iostream>
#include <vector>
using namespace std;

long A[1000100];
long ans_l, ans_r;
long res;
long cur;
long cur_l;

int main() {
	long n;
	cin>>n;
	for(long i=0;i<n;i++){
		cin>>A[i];
	}
	ans_l=0;
	ans_r=0;
	res=A[0];
	cur=A[0];
	cur_l=0;
	for(long i=1;i<n;i++){
		if(cur>=0) cur=cur+A[i];
		else {
			cur=A[i];
			cur_l=i;	
		}
		if(res<cur){
			ans_l=cur_l;
			ans_r=i;
			res=cur;
		}
	}
	cout<<ans_l+1<<" "<<ans_r+1<<" "<<res<<endl;
}
