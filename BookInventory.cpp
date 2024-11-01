#include<iostream>
using namespace std;
class book{
    public:
    string name,author,publisher;
    float price;
    int stock;
    void info(int x){
        cout<<"Book "<<x+1<<" Details:"<<endl;
        cout<<"Enter Book Name:";
        cin>>name;
        cout<<"Enter Book Author:";
        cin>>author;
        cout<<"Enter Book Publisher:";
        cin>>publisher; 
        cout<<"Enter Book Price:";
        cin>>price;   
        cout<<"Enter Book Available Stock:";
        cin>>stock;   
    }
    void display(){
        cout<<name<<"\t"<<author<<"\t"<<publisher<<"\t\t"<<price<<"\t"<<stock<<endl;
    }
};

int main(){
    book b[20];
    int i,c,ch,n=0,temp,flag=0,temp_stock;
    float temp_price;
    string temp_name,temp_author;
    do{
        cout<<"1.Insert Details\n2.Display\n3.Search\nEnter your choice:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"Enter size of Lot:";
                cin>>temp;
                for(i=n;i<n+temp;i++){
                    b[i].info(i);
                }
                n+=temp;
                break;
            case 2:cout<<"Name\tAuthor\tPublisher\tPrice\tStock"<<endl;
                for(i=0;i<n;i++){
                    b[i].display();
                }
                break;
            case 3:cout<<"Enter Book Name to be ordered:";
                cin>>temp_name;
                cout<<"Enter Book Author:";
                cin>>temp_author;
                flag=0;
                for(i=0;i<n;i++){
                    if(temp_name==b[i].name && temp_author==b[i].author){
                        cout<<"Book Name:"<<b[i].name<<"\nBook Author:"<<b[i].author<<"\nBook Publisher:"<<b[i].publisher<<"\nBook Price:"<<b[i].price<<"\nStock:"<<b[i].stock<<endl;
                        cout<<"Enter no. of copies required:";
                        cin>>temp_stock;
                        if(temp_stock<=b[i].stock){
                            b[i].stock-=temp_stock;
                            cout<<"Copies are available:"<<endl;
                            temp_price=temp_stock*b[i].price;
                            cout<<"Total Price:"<<temp_price<<endl;
                        }
                        else{
                            cout<<"Copies are not available(Order Exceeds!)"<<endl;
                        }   
                        flag=1;
                    }
                }
                if(flag==0){
                    cout<<"Book is not available";
                    break;
                }
                break;
            default:cout<<"Invalid Choice";
        }
        cout<<"\n[Press 1 to continue]:";
        cin>>c;
    }while(c==1);
    return 0;
}