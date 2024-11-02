#include<iostream>
using namespace std;
class complex{
    public:
    int real;
    int imag;
    complex(){
        real=0;
        imag=0; 
    }
    complex(complex &obj1,complex &obj2){
        real=obj1.real;
        imag=obj2.imag;
    }
    void input(){
        cout<<"Enter the value of real part:";
        cin>>real;
        cout<<"Enter the value of imag part:";
        cin>>imag;

    }
    void display(){
        cout<<"Complex Number is :"<<real<<" + "<<imag<<" i "<<endl;
    }

    complex operator+(complex &x){
        complex temp;
        temp.real=real+x.real;
        temp.imag=imag+x.imag;
        return temp;
    }
    complex operator-(complex &x){
        complex temp;
        temp.real=real-x.real;
        temp.imag=imag-x.imag;
        return temp;
   }
    complex operator*(complex &x){
        complex temp;
        temp.real= real * x.real - imag * x.imag;
        temp.imag= real * x.imag + imag * x.real;
        return temp;
   }
   complex operator/(complex &x){
        complex temp;
        temp.real= (real * x.real + imag * x.imag)/((x.real*x.real)+(x.imag*x.imag));
        temp.imag= (imag * x.real - real * x.imag)/((x.real*x.real)+(x.imag*x.imag));
        return temp;
   }
};
 
int main(){
    complex obj1,obj2,obj3;
    int ch,c;
    do{
        cout<<"\nMenu\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter your Choice:";
        cin>>ch;
        switch(ch){
            case 1:obj1.input();
                   obj2.input();
                   obj3=obj1+obj2;
                   obj3.display();
                   break;
            case 2:obj1.input();
                   obj2.input();
                   obj3=obj1-obj2;
                   obj3.display();
                   break;
            case 3:obj1.input();
                   obj2.input();
                   obj3=obj1*obj2;
                   obj3.display();
                   break;
            case 4:obj1.input();
                   obj2.input();
                   obj3=obj1/obj2;
                   obj3.display();
                   break;
            default:cout<<"Invalid Choice"<<endl;
        }
        cout<<"If you want to continue Enter 1:";
        cin>>c;
    }while(c==1);
    return 0;
}