#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class Television
{
public:
    int model_no;
    int screen_size;
    float price;
    Television()
    {
        model_no = 0;
        screen_size = 0;
        price = 0.0;
    }
    friend istream &operator>>(istream &input, Television &T)
    {
        cout << "Enter Modal no:";
        input >> T.model_no;
        if (T.model_no>9999) 
        {
            throw 1;
        }
        cout << "Enter Screen Size (in inches):";
        input >> T.screen_size;
        if (T.screen_size < 12 || T.screen_size > 70)
        {
            throw 2;
        }
        cout << "Enter Price:";
        input >> T.price;
        if (T.price < 0 || T.price > 5000)
        {
            throw 3;
        }
    }
    friend ostream &operator<<(ostream &output, Television &T)
    {
        output<<"Model No.\tScreen Size\tPrice"<<endl;
        output<<T.model_no<<"\t\t"<<T.screen_size<<"\t\t"<<T.price<<endl;
    }
    void reset()
    {
        model_no = 0;
        screen_size = 0;
        price = 0.0;
    }
};
int main()
{
    Television T;
    try
    {
        cin >> T;
        cout << "Details of Television:" << endl;
        cout << T << endl;
    }
    catch (int i)
    {
        cout << "Invalid Television Details. Error in code " << i << endl;
        cout << "Resetting all values to zero" << endl;
        T.reset();
        cout << T;
    }
}
