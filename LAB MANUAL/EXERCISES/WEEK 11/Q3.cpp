#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

void bubbleSort(vector<int>& arr){
	int n = arr.size();
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(){
    int n;
    cout<<"Enter number of integers: ";
    cin>>n;

    vector<int> arr1, arr2;
    cout<<"Enter "<<n<<" Integers: ";
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr1.push_back(num);
        arr2.push_back(num);
    }
    //Bubble sort
    clock_t start1 = clock();
    bubbleSort(arr1);
    clock_t end1 = clock();
    double time1 = double(end1 - start1);

    //STL sort
    clock_t start2 = clock();
    sort(arr2.begin(),arr2.end());
    clock_t end2 = clock();
    double time2 = double(end2 - start2);

    cout<<"Bubble Sort time: "<<time1<<endl;
    cout<<"STL Sort time: "<<time2<<endl;
    
    return 0;
}