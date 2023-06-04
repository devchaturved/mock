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
    cout << "Entr PRN and marks" << endl;
    cin >> rec.prn >> rec.marks;
    int index = hash_function(rec.prn);
    int last_index = -1;
    while(table[index].prn!=-1){
        if(hash_function(table[index].prn)==hash_function(rec.prn)){
            last_index = index;
            while(table[index].link!=-1){
                index= table[index].link;
                last_index = index;
            }
            index = (index+1)%size;
        } else{
            last_index = index;
            node initial_recond = table[index];
            while(table[index].prn!=-1){
                index=(index+1)%size;
            }
            table[index] = initial_recond;
            for(int i = 0;i<size;i++){
                if(table[i].link==last_index) {table[i].link = index;}
            }
            cout << "Insertion Successful" << endl;
            return;
        }
    }
    table[last_index].link = index;
    table[index]=rec;
    cout << "Insertion Successful" << endl;
}

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