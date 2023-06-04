#include<bits/stdc++.h>
using namespace std;

#define size 10

struct node{
public:
    int prn=-1;
    int marks=-1;
    int link = -1;
};

node table[size];

int hash_function(int key){
    return key%size;
}

void insert(){
    node rec;
    cout<<"Enter PRN and marks:";
    cin>>rec.prn>>rec.marks;
    int index=hash_function(rec.prn);
    int last_indx=-1;
    while(table[index].prn!=-1){
         if(hash_function(table[index].prn)==hash_function(rec.prn)){
            last_indx=index;
            while(table[index].link!=-1){ 
                index = table[index].link;
                last_indx=index;
            }index=(index+1)%size;
        }else index=(index+1)%size;
    }
    table[last_indx].link=index;
    table[index]=rec;
    cout<<"Insertion Successful"<<endl;}

int search(int key){
    int hash_index = hash_function(key);
    int cmp = 0;
    int index = hash_index;
    while(table[index].prn!=key){
        if(table[index].link==-1) return -1;
        else{
            cmp++;
            index = table[index].link;
        }
    }
    cout << cmp << endl;
    return index;
}

void display(){
    cout << "Index " << "PRN " << "Marks" << "Link" << endl;
    for(int i = 0; i< size;i++){
        cout << i << " " << table[i].prn << " " << table[i].marks << " " << table[i].link << endl;
    }
}

int main(){
    int choice;
    int ans;
    cout << "Linear Probing without replacement" << endl;

    do{
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch(choice){
        case 1:
            insert();
            break; 
        case 2:
            int key;
            cout << "Enter the prn you want to insert"<< endl;
            cin >> key;
            ans = search(key);
            if(ans>0){
                cout << "Found " << ans << endl;
            } else{
                cout << "Not Found" << endl;
            }
            cout << endl;
            break;
        case 3:
            display();
            cout << endl;
            break;
        }
    } while(choice > 0);
}