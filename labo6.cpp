#include <iostream>

using namespace std;

int FASTEST_WAY(int a[2][6],int t[2][5],int e[2],int x[2],int n){
    int f1[n];
    int f2[n];
    int pasos[n];
    int final=0;
    string r1="e1=>";
    string r2="e2+ ";
   
    f1[0]=e[0]+a[0][0];
    cout<<f1[0]<<endl;
    f2[0]=e[1]+a[1][0];
    cout<<f2[0]<<endl;
   
    for(int j=1 ;j<n; j++){
        if(f1[j-1]+a[0][j]<=f2[j-1]+t[1][j-1]+a[0][j]){
            f1[j]=f1[j-1]+a[0][j];
            r1 = r1+ "=>a1"+to_string(j+1);
        }
        else{
            f1[j]=f2[j-1]+t[1][j-1]+a[0][j];
            r1 = r1 + "=>a2"+to_string(j+1);
        }
        if(f2[j-1]+a[1][j]<=f1[j-1]+t[0][j-1]+a[1][j]){
            f2[j]=f2[j-1]+a[1][j];
            r2 = r2 +"=>a2"+ to_string(j+1);
        }
        else{
            f2[j]=f1[j-1]+t[0][j-1]+a[1][j];
            r2=r2+"=>a1" + to_string(j+1);
        }
    }
    if(f1[n-1]+x[0]<=f2[n]+x[1]){
        final=f1[n-1]+x[0];
        for(int i=0;i<n;i++){
            cout<<f1[i]<<",";
        }
        cout << final<<endl;
        cout<<r1<<"=>x1";
       
    }
    else{
        final=f2[n-1]+x[0];
        for(int i=0;i<n;i++){
            cout<<f2[i]<<",";
        }
        cout << final<<endl;
        cout<<r2<<"=>x2";
    }
}

int main()
{
    int a[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};
    int t[2][5]={{2,3,1,3,4},{2,1,2,2,1}};
    int e[2]={2,4};
    int x[2]={3,2};
    FASTEST_WAY(a,t,e,x,6);

    return 0;
}

