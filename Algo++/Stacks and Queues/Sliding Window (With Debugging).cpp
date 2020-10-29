#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> q){
    cout << "     Deque : ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front() ; 
    }
    cout << endl ;
}

int main() {
    int n;
    int a[100000];
    int k;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    
    //We have to process first k elements separtely
    deque<int> Q(k);
    int i;
    for(i=0;i<k;i++){
        
        while(!Q.empty() &&a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
        
        cout << " i = "<<i<<"   a[i]="<<a[i] ;
        printDeque(Q);
        
    }
    cout << endl ; 
    //Process the remaining elements 
    for(;i<n;i++){
        cout << " i = "<<i<<"   a[i]="<<a[i] ;
        printDeque(Q);

        cout<<"Print - "<<a[Q.front()]<<" \n";
        
        //1. Remove the elements which are not the part of the window(Contraction)
        while((!Q.empty() && (Q.front()<=i-k))){
            Q.pop_front();
        }

        cout << "After contaction -" ;
        printDeque(Q);

        //2. Remove the elements which are not useful and are in window
        while(!Q.empty() && a[i]>=a[Q.back()]){
            Q.pop_back();   
        }

        cout << "Removing useless elements - ";
        printDeque(Q);

        //3. Add the new elements(Expansion)
        Q.push_back(i);
        
        cout << "After expansion -" ;
        printDeque(Q) ; 

        cout << endl ;
    }
    
    cout<<a[Q.front()]<<endl;
    
    
    return 0;
}

