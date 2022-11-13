
#include <bits/stdc++.h>

using namespace std;

// this fuction return the index of a given value from original array.
int search(int pies[], int value, int size){
    for(int i=0;i<size;i++){
        if(pies[i]==value){
            return i;
        }
    }
}

void combination(vector<int>& ans, vector<int>& myPies, int start, int sum, int ds, int pies[], int size){
    
    //if the sum equals to the desired sweetness, we print the values in the vector.
    if(sum==ds){
        cout << endl;
        for(int j: ans){
            cout << j << " ";
        }
    }
    
    //  we push the elements to the ans vector for sum less than desired sweetness and pop_back(remove) them after call the recursive function.
    for(int j=start; j<myPies.size();j++){
        if(sum>ds){
            continue;
        } 
        // find index for the current element
        int a = search(pies, myPies[j], size );
        // pushed the index to the ans vector
        ans.push_back(a);
        combination(ans, myPies, j+1, sum+myPies[j], ds, pies, size);
        ans.pop_back();
    }
}
int main()
{
    // these are two cases which you can use. 
    // 5 1 2 3 2 1 6
    // 6 8 4 3 2 6 5 6
    
    cout << "enter size: " ;
    int size;
    cin >> size;
    int pies[size];               
    for(int i=0;i<size;i++){
        cout << i << ":";
        cin >> pies[i];
    }
    
    cout << "Enter the desired sweetness: ";
    int ds;                         
    cin >> ds;
    
    cout << "pies " ;
    for(int i=0;i<size;i++){
        cout << pies[i] << " ";
    }
    cout << endl;
    
    // copying all the elements in a vector form the array. because i don't want to update original array.
    vector<int> temp;
    for(int i=0;i<size;i++){
        temp.push_back(pies[i]);
    }
    
    // sort the vector.
    sort(temp.begin(),temp.end());
    
    // printing the sorting vector
    cout << "temp " ;
    for(int i=0;i<size;i++){
        cout << temp[i] << " ";
    }
    cout << endl;
    
    // create one more vector with stores unique values in sorted order.
    vector<int> myPies;
    myPies.push_back(temp[0]);
    for(int i=1;i<size;i++){
        if(temp[i]!=temp[i-1]){
            myPies.push_back(temp[i]);
        }
    }
    
    // printing the vector.
    cout << "myPies " ;
    for(int i=0;i<myPies.size();i++){
        cout << myPies[i] << " ";
    }
    cout << endl;
    
    // declared a vector to store answer. 
    vector<int> ans;
    combination(ans, myPies, 0, 0, ds, pies, size);
    
    return 0;
}
