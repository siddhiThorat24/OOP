#include<iostream>
#include <string>
using namespace std;
class Bank
{
    private:
        string acc_hold;
        float bal_amt,dpst_amt,with_amt;
    public:
        int acc_no;
        void get_info(int x)
        {
            cout<<"Account Holder "<<x+1<<" Details:"<<endl;
            cout<<"Enter Account Holder Name:";
            cin>>acc_hold;
            cout<<"Enter Account No. :";
            cin>>acc_no;
            cout<<"Enter Total Amount:";
            cin>>bal_amt;
        }
        void deposit()
        {
        cout<<"Enter Amount to be Deposited:";
        cin>>dpst_amt;
        bal_amt+=dpst_amt;
        cout<<"Amount "<<dpst_amt <<" Deposited Successfully!\n";
        cout<<"Total Amount = " <<bal_amt;
        }
        void withdraw()
        {
        cout<<"Enter Amount to be Withdraw:";
        cin>>with_amt;
        if(bal_amt>=with_amt)
        {
            bal_amt-=with_amt;
            cout<<"Amount "<<with_amt <<" Withdraw Successfully\n";
            cout<<"Total Amount = " <<bal_amt<<"\n";   
        }
        else
        {
            cout<<"\nAmount Exceed!";
        }
        }
        void display()
        {
                cout<<acc_hold<<"\t"<<acc_no<<"\t\t"<<bal_amt<<"\n";   
        }

};
int main()
{
    Bank a[20];
    int ch,c,n=0,temp,pos,i,flag=0,tem;
    do
    {
       cout<<"1.Insert Details\n2.Deposit an Amount\n3.Withdraw an Amount\n4.Display\nEnter your choice:";
       cin>>ch;
       switch(ch)
       {
            case 1:cout<<"Enter no. of Account Holders:";
                cin>>tem;
                for(i=n;i<n+tem;i++){
                    a[i].get_info(i);
                }
                n+=tem;
                break;
            case 2:cout<<"Enter Account No.:";
                cin>>temp;
                for(i=0;i<n;i++){
                    if(temp==a[i].acc_no){
                        pos=i;
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    a[pos].deposit();
                }
                else{
                    cout<<"Not Found";
                }
                flag=0;
                break;
            case 3:cout<<"Enter Account No.:";
                cin>>temp;
                for(i=0;i<n;i++){
                    if(temp==a[i].acc_no){
                        pos=i;
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    a[pos].withdraw();
                }
                else{
                    cout<<"Not Found";
                }
                flag=0;
                break;
            case 4:cout<<"Name\t"<<"Account No.\t"<<"Balance\n";
                for(i=0;i<n;i++){
                    a[i].display();
                }
                break;
            default:cout<<"Invalid choice\n";
       }
       cout<<"\n[Press 1 to Continue] ";
       cin>>c;  
    }while(c==1);
    return 0;

}