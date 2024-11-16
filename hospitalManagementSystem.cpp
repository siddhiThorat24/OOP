#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
        int id;
        string name;
        float salary;
        long int cont_no;

    public:
        void details(int x)
        {
            cout<<"Detail No. "<<x+1<<endl;
            cout << "Enter the id: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter salary: ";
            cin >> salary;
            cout << "Enter contact no: ";
            cin >> cont_no;
        }
        void display()
        {
            cout << id << "\t" << name << "\t" << salary << "\t" << cont_no;
        }
};

class doctor : virtual public Person
{
    public:
        string specialization;
        string experience;
        
        void doctor_details()
        {

            cout << "Enter doctor's specialization: ";
            cin >> specialization;
            cout << "Enter doctor's experience: ";
            cin >> experience;
        }
        void doctor_display()
        {

            cout << "\t" << specialization << "\t\t" << experience << endl;
        }
};

class nurse : virtual public Person
{
    public:
        string experience;
        void nurse_details()
        {
            cout << "Enter nurse's experience: ";
            cin >> experience;
        }

        void nurse_display()
        {

            cout << "\t" << experience << endl;
        }
};

class admin : public doctor, public nurse
{
    public:
        void search(admin a[], admin b[], int D, int N)
        {
            int i, ch, id1, flag=0, k;
            do
            {
                cout << "Menu\n1. Search Doctor\n2. Search Nurse\n3. Exit\nEnter your choice: ";
                cin >> ch;
                switch (ch)
                {
                case 1: cout << "Enter the id of the doctor you want to search: ";
                    cin >> id1;
                    flag = 0; 
                    for (i = 0; i < D; i++)
                    {
                        if (id1 == a[i].id)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1)
                    {
                        cout << "Doctor is found:\n";
                        a[i].display();
                        a[i].doctor_display();
                    }
                    else
                    {
                        cout << "Doctor is not found" << endl;
                    }
                    break;

                case 2:cout << "Enter the id of the nurse you want to search: ";
                    cin >> id1;
                    flag = 0; 
                    for (i = 0; i < N; i++)
                    {
                        if (id1 == b[i].id)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1)
                    {
                        cout << "Nurse is found:\n";
                        b[i].display();
                        b[i].nurse_display();
                    }
                    else
                    {
                        cout << "Nurse is not found" << endl;
                    }
                    break;
                case 3:return;

                default:
                    cout << "Wrong choice" << endl;
                }
                cout << "If you want to continue searching, enter 1: ";
                cin >> k;
            } while (k == 1);
        }
};

int main()
{
   admin a[20],b[20],c;

    int ch, k, i;
    int d, D = 0;
    int n, N = 0;
    int A = 0;
    do
    {
        cout << "Menu\n1. Doctors data\n2. Nurse data\n3. Admin data\n4. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:cout << "Enter the number of doctors: ";
            cin >> d;
            for (i = D; i < d + D; i++)
            {
                a[i].details(i);
                a[i].doctor_details();
            }
            D += d;
            cout << "Id\tName\tSalary\tContact No.\tSpecialization\tExperience"<< endl;
            for (i = 0; i < D; i++)
            {
                a[i].display();
                a[i].doctor_display();
            }
            break;

        case 2:cout << "Enter the number of nurses: ";
            cin >> n;
            for (i = N; i < n+ N; i++)
            {
                b[i].details(i);
                b[i].nurse_details();
            }
            N += n;
            cout << "Id\tName\tSalary\tContact No.\tExperience"<< endl;;
            for (i = 0; i < N; i++)
            {
                b[i].display();
                b[i].nurse_display();
            }
            break;

        case 3:c.search(a, b, D, N);
             break;

        case 4:break;

        default:
            cout << "Wrong choice" << endl;
        }
        cout << "If you want to continue, enter 1: ";
        cin >> k;
    } while (k == 1);

    return 0;
}
