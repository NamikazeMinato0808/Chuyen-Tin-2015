#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	long n;
	cin>>n;
	vector<long>a(n);
	for(long i=0;i<n;i++){
		cin>>a[i];
	}
	long k=sqrt(n);
	vector<long>b;
	for(long i=2;i<=k;i++){
		if(n%i==0){
			b.push_back(i);
			if(i!=n/i) b.push_back(n/i);
		}
	}
	sort(b.begin(), b.end());
	vector<long>ans;
	vector<long>ans1;
	vector<long>ans2;
	for(int i=0;i<b.size();i++){
		bool no=false;
		int res1=0;
		int res2=0;
		int j=0;
		vector<long>l1(b[i]);
		vector<long>l2(b[i]);
		vector<long>l3(b[i]);
		bool e1=false;
		bool e2=false;
		while(j<n){
			if(!e1){
				for(int z=j;z<j+b[i];z++){
					l1[z-j]=a[z];
				}
				j=j+b[i];
				sort(l1.begin(), l1.end());
				e1=true;
				res1=1;
			}
			else if(!e2){
				for(int z=j;z<j+b[i];z++){
					l2[z-j]=a[z];
				}
				j=j+b[i];
				sort(l2.begin(), l2.end());
				e2=true;
				res2=1;
			}
			else{
				for(int z=j;z<j+b[i];z++){
					l3[z-j]=a[z];
				}
				sort(l3.begin(),l3.end());
				bool p1=true;
				bool p2=true;
				for(int z=0;z<b[i];z++){
					if(l3[z]!=l1[z]){
						p1=false;
						break;
					}
				}
				if(p1==true){
					res1++;
				}
				else{
					for(int z=0;z<b[i];z++){
						if(l3[z]!=l2[z]){
							p2=false;
							break;
						}
					}
					if(p2==true) res2++;
					else no=true;
				}
				j=j+b[i];
			}
			if(no==true) break;
		}
		if(!no && e1 && e2){
			ans.push_back(b[i]);
			if(res1>res2) {
				ans1.push_back(res1);
				ans2.push_back(res2);
			}
			else {
				ans2.push_back(res1);
				ans1.push_back(res2);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" "<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	system("pause");
}
