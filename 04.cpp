#include<iostream>
#include<vector>
using namespace std;

bool Findtarget(){
    int n,m,target;
    cin>>n>>m;
    cin>>target;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    for(int i = 0;i<n ;++i){
        for(int j = 0; j< m;++j){
            cin>>matrix[i][j];
        }
    }
    int col = 0;
    int row = n-1;
    while(row>=0&&col<m){
        if(matrix[row][col]>target){
            col++;
        }
        else if(matrix[row][col]<target){
            row--;
        }
        else{
            //cout<<row<<" "<<col<<endl;
            return true;
        }
    }

    return false;
}

int main(){
    cout<<Findtarget()<<endl;
    return 0;
}