#include<iostream>
#include<string>
using namespace std;
int i,n;
class PIS{
    static int cnt;
    string name;
    int prn,ht,wt;
    public:

        /*PIS(){
        ht=0;
        wt=0;
        name=new char;
        }
        ~PIS(){
        delete name;
        }*/
        //----- for Default constructor:------//
       PIS(){
            name="";
            prn=0;
            ht=0;
            wt=0;
       }
       ~PIS(){

       }
        //----- for Parameterised constructor:------//
        PIS(string nam,int pn,int h,int w){
            name=nam;
            prn=pn;
            ht=h;
            wt=w;
        }
        //----- for Copy constructor:------//
        PIS(PIS &ss){
            name=ss.name;
            prn=ss.prn;
            ht=ss.ht;
            wt=ss.wt;
        }

        static void discnt(){
            cout<<"\nTotal Record:"<<cnt;
        }

        void accept(){
            cnt++;
            cout<<"Enter Name:";
            cin>>name;
            cout<<"Enter PRN:";
            cin>>prn;
            cout<<"Enter height and weight:";
            cin>>ht>>wt;
        }

        void Update();
        void Delete();
        friend void search();
        void display();
}s[100];

int PIS::cnt;

void search(){
    int pp,f=0;
    cout<<"\nEnter PRN to search:";
    cin>>pp;
    for(i=0;i<n;i++){
        if(pp==s[i].prn){
            f=1;
            cout<<"\nRecord found";
            break;
        }
    }
    if(f==0){
        cout<<"\nRecord not found";
    }
}

void PIS::Update(){
    int pp,f=0,ch;
    cout<<"\nEnter PRN to modify:";
    cin>>pp;
    for(i=0;i<n;i++){
        if(pp==s[i].prn){
            f=1;
            cout<<"\nRecord found";
            cout<<"\nWhat you want to update\n";
            cout<<"1.Name\n2.PRN\n3.Height\n4.Weight\n5.All\nEnter your choice:";
            cin>>ch;
            switch(ch){
                case 1:cout<<"\nEnter new name:";
                    cin>>s[i].name;
                    break;
                case 2:cout<<"\nEnter new prn:";
                    cin>>s[i].prn;
                    break;    
                case 3:cout<<"\nEnter new height:";
                    cin>>s[i].ht;
                    break;  
                case 4:cout<<"\nEnter new weight:";
                    cin>>s[i].wt;
                    break;       
                case 5:s[i].accept();
                    break;   
                default:cout<<"Invalid choice";
            }
            break;
        }
    }
    if(f==0){
        cout<<"\nRecord not found";
    }
}

void PIS::Delete(){
    int pp,f=0,ch;
    cout<<"\nEnter PRN to delete:";
    cin>>pp;
    for(i=0;i<n;i++){
        if(pp==s[i].prn){
            f=1;
            cout<<"\nRecord found";
            cout<<"\nWhat you want to delete\n";
            cout<<"1.Name\n2.PRN\n3.Height\n4.Weight\n5.All\nEnter your choice:";
            cin>>ch;
            switch(ch){
                case 1:s[i].name="";
                    cout<<"Name deleted";
                    break;
                case 2:s[i].prn=0;
                    cout<<"PRN deleted";
                    break;    
                case 3:s[i].ht=0;
                    cout<<"Height deleted";
                    break;  
                case 4:s[i].wt=0;
                    cout<<"Weight deleted";
                    break;       
                case 5:do{
                    s[i]=s[i+1];
                    i++;
                    }while(i<n-1);
                    n--;
                    break;   
                default:cout<<"Invalid choice";
            }
            break;
        }
    }
    if(f==0){
        cout<<"\nRecord not found";
    }
}

inline void PIS::display(){
    cout<<name<<"\t"<<prn<<"\t"<<ht<<"\t"<<wt<<endl;
}

int main(){
    int c,ch;
    PIS s3;
    s3.display();
    PIS s1("Ram",100,10,20);
    s1.display();
    PIS s2(s1);
    s2.display();
    cout<<"\nEnter the no. of students:";
    cin>>n;

    do{
        cout<<"\n1.Accept\n2.Search\n3.Update\n4.Delete\n5.Display count\n6.Display\nEnter your choice:";
        cin>>ch;
        switch(ch){
            case 1:for(i=0;i<n;i++){
                    s[i].accept();
                }
                break;
            case 2:search();
                break;
            case 3:s[i].Update();
                break;
            case 4:s[i].Delete();
                break;
            case 5:PIS::discnt();
                break;
            case 6:cout<<"Name\tPRN\tHeight\tWeight"<<endl;
                for(i=0;i<n;i++){
                    s[i].display();
                }
                break;
            default:cout<<"\nInvalid choice";
        }
        cout<<"\nEnter 1 to continue:";
        cin>>c;
    }while(c==1);
    return 0;
}