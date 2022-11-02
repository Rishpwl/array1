#include<iostream>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

// reverse the array problem
void reverse(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;

    }
}

// find maximum and minimum element in array
int getmax(int arr[],int n){
    int ans=INT16_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);

    }
    return ans;
}

int getmin(int arr[],int n){
    int ans=INT16_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,arr[i]);

    }
    return ans;
}

// sort 0,1,2 without using any sorting algorithm
void sort012(int arr[],int n){
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }else if(arr[i]==1){
            count1++;
        }else{
            count2++;
        }
    }
    int i=0;
    while(count0--){
        arr[i]=0;
        i++;
    }

     while(count1--){
        arr[i]=1;
        i++;
    }

     while(count2--){
        arr[i]=2;
        i++;
    }
}

// move negative element to one side of array
void movenegative(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
}


// union of two sorted array

void unionofarray(int arr1[],int n,int arr2[],int m){
    set<int> s;

    for(int i=0;i<n;i++){
        s.insert(arr1[i]);
    }

    for(int i=0;i<m;i++){
        s.insert(arr2[i]);
    }

    for(auto j=s.begin();j!=s.end();j++){
        cout<<*j<<" ";
    }

}

// find intersection between two sorted arrays

void intersection(int arr1[],int n,int arr2[],int m){
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
             i++;
             j++;
        }else if(arr1[i]<arr2[j]){
            i++;
        }else{
            j++;
        }
    }
}

// cyclically rotate an array by one element
void rotate(int arr[],int n){
    int x=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=x;
}


// kadane algorithm-to find largest sum contiguous subarray
int getmaxsubarray(int arr[],int n){
    int ans=INT16_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }
    }
    return ans;

}

// minimise the height 2 gfg problem
int getmindiff(int arr[],int n,int k){
    sort(arr,arr+n);
    int ans=arr[n-1]-arr[0];

    int tempmin,tempmax;
    tempmin=arr[0];
    tempmax=arr[n-1];

    for(int i=1;i<n;i++){
        if(arr[i]-k<0){
            continue;
        }
        tempmin=min(arr[0]+k,arr[i]-k);
        tempmax=max(arr[i-1]+k,arr[n-1]-k);
        ans=min(ans,tempmax-tempmin);
    }
    return ans;
}


int main(){
    /*int arr[]={1,2,3,4,5};
    reverse(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<" max element "<<getmax(arr,5);
    cout<<endl;
    cout<<" min element "<<getmin(arr,5);*/

   /* int arr[8]={1,0,2,1,0,0,1,2};
    sort012(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }

    int arr[]={2,-1,8,-2,-5,8,1,-3};
    movenegative(arr,8);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }*/

   /* int arr1[]={1,2,3,5,6,7};
    int arr2[]={1,2,3,6};

    unionofarray(arr1,4,arr2,3);
    cout<<endl;

    intersection(arr1,6,arr2,4);

    int arr[]={1,2,3,4,5};
    rotate(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    int arr[]={-1,-2,-3,-4};
    cout<<"answer is "<<getmaxsubarray(arr,4);*/

    int arr[]={3,9,12,16,20};
    cout<<"minimum difference "<<getmindiff(arr,5,3);

    return 0;
}