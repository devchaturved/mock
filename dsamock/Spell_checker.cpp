#include<bits/stdc++.h>
using namespace std;

class node
{
string wd;
node* next;
public:
node(string w)
{
this->wd=w;
}
friend class sep_chaining;
};


class sep_chaining
{
node* Htable[23];
public:
sep_chaining()
{
	for(int i=0;i<23;i++)
	{
	Htable[i]=NULL;
	}
}

int hashf(string w);
void insert(string w);
void display();
void search(string w);
void del(string w);

};


int sep_chaining :: hashf(string w)
{
int y = w.size();
int z = 10;
int sum=0;
for(int i=0;i<y;i++)
{
sum+=int(w[i])*pow(z,y-1);
y--;
}
return sum%23;
}

void sep_chaining :: insert(string w)
{
node* p=new node(w);
int ind = hashf(w);
if(Htable[ind]==NULL)
{
Htable[ind]=p;
}

else
{
p->next = Htable[ind];
Htable[ind]=p;
}
}

void sep_chaining :: search(string w){
    int ind=hashf(w);
    if(Htable[ind]==NULL){
        cout<<"Word does not exist !!!"<<endl;
    }
    else{
        node *t=Htable[ind];
        int ct=0;
       while (t != NULL)
	    {
	      if(t->wd == w) { 
	          cout<<"Word Found !!"<<endl;
	          ct++;
	          break;
	      }
	      else t = t->next;
	    }
	    if(ct==0) cout<<"Word does not exist !!! "<<endl;
    }
}

void  sep_chaining :: del(string w){
    int ind=hashf(w);
     if(Htable[ind]==NULL){
        cout<<"Word does not exist !!!"<<endl;
    }
    else{
        node *l=Htable[ind];
        node *t=Htable[ind];
        int ct=0;
       while (t != NULL)
	    {
	      if(t->wd == w) { 
	         if(t==Htable[ind]){
	             Htable[ind]=t->next;
	             delete(t);
	             break;
	         }
	         l->next=t->next;
	         delete(t);
	          break;
	      }
	      else {
	          l=t;
	          t = t->next;
	      }
	    }
	    if(ct==0) cout<<"Word does not exist !!! "<<endl;
    }
}

void sep_chaining :: display()
{

cout << "Index " << "Word " << endl;
  for (int i = 0; i < 23; i++)
    {
      if (Htable[i] != NULL)
	{
	  cout << " " << i << " ";
	  node *t=Htable[i];
	  while (t != NULL)
	    {
	        if(t!=Htable[i]) cout<<",";
	      cout << t->wd << " ";
	      t = t->next;
	    }
	  cout << endl;
	}
      else
	cout << " " << i << " " << ".." << endl;
    }
}

int main()
{
	string word;
	int k;
	sep_chaining a;
  ifstream in;
  ofstream out;  
in.open("sample.txt");                         
while(!in.eof())
{
getline(in,word);
a.insert(word);
}
in.close();

int choice;
while(true)
{
        cout<<"1. Add entries to the hash table"<<endl;
		cout<<"2. Display the hash table"<<endl;
	    cout<<"3. Search a Word"<<endl;
	    cout<<"4. EXIT !!!"<<endl;
    	cout<<"Enter the choice.... : ";
	cin>>choice;
    switch(choice)
    {
        	case 1:
					cout<<"Enter the number of elements to be added : ";
					cin >> k;
					for(int i=0;i<k;i++)
					{
						cout << "Enter the word to be inserted : ";
						cin >> word;
					        out.open("sample.txt", ios :: app);
                                                out << word << endl;
					        a.insert(word);
						a.display();
					}
					break;
			case 2: a.display();
					break;
			case 3: 
			        cout<<"Enter the word to be Searched : ";
			        cin>>word;
			        a.search(word);
			        break;
			case 4:
			        exit(0);
    }

}



}
