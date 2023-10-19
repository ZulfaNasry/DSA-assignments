#include <bits/stdc++.h>
using namespace std;

//Comparison Function to sort array according to price/weight ratio
static bool rtio(vector<int>& a,vector<int>& b){
    return (double)((double)a[0]/(double)a[1]) > (double)((double)b[0]/(double)b[1]);
}

int main() {

    int n = 10; //no.of vegetables and fruits
    
    int W = 30; //Total weights 

    //declare 2*2 array (price,weight)
    vector<vector<int>> arr = {{1500,5},{1050,1},{600,6},{400,8},{800,4},{1800,6},{300,1},{900,2},{600,3},{1000,5}};
    
    //Sorting array according to price/weight ratio  
        sort(arr.begin(),arr.end(),rtio);

        double t_price = 0;  //count price
    
    //Iterating through given array untill the the given weight is filled
        for(int i=0;i<n;i++){
            
            if(W>=arr[i][1]){
                t_price += arr[i][0]; //increase price according to sorted array
                W -= arr[i][1];      //decrement weight
            }
            
        }
    
        cout<<"Total price of item from : "<<t_price;
}
