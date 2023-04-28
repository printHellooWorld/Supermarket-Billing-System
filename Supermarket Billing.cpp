#include<iostream>
#include<fstream> // Program consists of file handling operations. 
using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping :: menu()
{
    // label Helps to jump to main menu(function)
    m: 
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t..................................\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t      SuperMarket Main Menu       \n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t..................................\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t|    1. Administrator            |\n";
    cout<<"\t\t\t\t|                                |\n";
    cout<<"\t\t\t\t|    2. Buyer                    |\n";
    cout<<"\t\t\t\t|                                |\n";
    cout<<"\t\t\t\t|    3. Exit                     |\n";
    cout<<"\t\t\t\t|                                |\n";
    cout<<"\t\t\t\t      Please Select:";

    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email \n";
            cin>>email;
            cout<<"\t\t\t Password      \n";
            cin>>password;

            if(email=="anevase@gmail.com" && password=="anevase27")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid Email/Password";
            }
            break;
    
        case 2:
        {
            buyer();
        }

        case 3:
        {
            exit(0);
        }

        default:
        {
            cout<<"Please select from the given options";
        }
    }

    goto m;  // Goes to main function.  

}

void shopping ::administrator()
{
        m:
        int choice;
        cout<<"\n\n\n\t\t\t Administrator Menu";
        cout<<"\n\t\t\t|___1. Add the Product_________|";
        cout<<"\n\t\t\t|                              |";
        cout<<"\n\t\t\t|___2. Modify the Product______|";
        cout<<"\n\t\t\t|                              |";
        cout<<"\n\t\t\t|___3. Delete the Product______|";
        cout<<"\n\t\t\t|                              |";
        cout<<"\n\t\t\t|___4. Return to Main Menu_____|";

        cout<<"\n\n\t Please Enter your choice:   ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                add();
                break;

            case 2:
                edit();
                break;

            case 3:
                rem();
                break;

            case 4:
                menu();
                break;
            
            default:
                cout<<"Invalid Choice";
        }
        goto m;
}

void shopping :: buyer()
{
    m:
    int choice; 
    cout<<"\t\t\t       Buyer       \n";
    cout<<"\t\t\t___________________\n";
    cout<<"                         \n";
    cout<<"\t\t\t   1.Buy Product   \n";
    cout<<"                         \n";
    cout<<"\t\t\t   2.Go Back       \n";
    cout<<"\t\t\t   Enter your choice:   ";

    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;

        default:
            cout<<"Invalid Choice";
        
    }

    goto m;

}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int tokens = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t\t\t Product code of the product: ";
    cin>>pcode;

    cout<<"\n\n\t\t\t Name of the Product: ";
    cin>>pname;

    cout<<"\n\n\t\t\t Price of the product: ";
    cin>>price;

    cout<<"\n\n\t\t\t Discount of the product: ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<"\t"<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        data.close();

    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c == pcode)
            {
                tokens++;
            }
            data>>c>>n>>p>>d;

        }
        data.close();   
    }

    if(tokens == 1)
    goto m;

    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<"\t"<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record Inserted!";
        
}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int tokens = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product Code: ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File does not exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code: ";
                cin>>c;
                cout<<"\n\t\t Name of the product: ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
                tokens++;
            }
            else
            {
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(tokens == 0)
        {
            cout<<"\n\n Record not found, Sorry!";
        }
    }
}

void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int tokens = 0;

    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code: ";
    cin>>pkey;
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"File Does not Exist";
    }
    else{
        data1.open("dataabse1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\nProduct deleted successfully";
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }

            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(tokens == 0)
        {
            cout<<"\n\n Record not found, Sorry!";
        }
        
    }

}

void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);

    cout<<"\n\n____________________________________________\n";
    cout<<"ProNo \tName \tPrice\n";
    cout<<"\n\n____________________________________________\n";
    data>>pcode>>pname>>price>>dis;

    while(!data.eof())
    {
        cout<<pcode<<"\t"<<pname<<"\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"File Does not Exist";
    }
    else
    {
        data.close();

        list();
        cout<<"\n____________________________________________\n";
        cout<<"\n|                                           \n";
        cout<<"\n|          Please place the order           \n";
        cout<<"\n|                                           \n";
        cout<<"\n____________________________________________\n";

        do
        {
            m:
            cout<<"\n\n Enter Product Code: ";
            cin>>arrc[c];
            cout<<"\n\n Enter Product Quantity: ";
            cin>>arrq[c];

            for(int i=0;i<c;i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code, Please Try Again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If Yes then press Y else N";
            cin>>choice;

        }

        while(choice == 'Y');
        {
            cout<<"\n\n\t\t\t_____________________RECEIPT__________________ ";
            cout<<"\nProduct No \tProduct Name \tProduct Quantity \tPrice \tAmount \tAmount with Discount \n";

        }
        for(int i=0;i<c;i++)
        {
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total+dis;
                    cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;

                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();

    }
    cout<<"\n\n_____________________________________";
    cout<<"\n Total Amount: "<<total;
        
}

int main()
{
    shopping s;
    s.menu();
}





    
