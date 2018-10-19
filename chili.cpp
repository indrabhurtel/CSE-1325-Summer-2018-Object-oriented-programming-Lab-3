//Indra Bhurtel

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>


using namespace std;

class Customer{         // Customer class

    string customer_name; // customer name
    string cup_size;       // cup size

    public:
    Customer (string customer_name, string cup_size) // constructor
    {
        this->customer_name=customer_name;
        this->cup_size=cup_size;
    }

    string get_name()
    {
        return customer_name;

    }

    string get_size()
    {
        return cup_size;
    }


};
class Order{
    vector <Customer> nameAndsize;

    public:
    void reading_file()
    //void reading_file(string filename)
    {
        ifstream inFile;
        string nam;
        string siz;
        string line;
        inFile.open("chili.txt");
        //inFile.open(filename);
        int number;

        if(!inFile)
        {
            cout<<"File can't be opened.\n"<<endl;
            exit(1); //exiting

        }
        while(!inFile.eof())
        {
            inFile>>nam>>siz;//reading from the file


            number=line.find(",");
            nam=line.substr(0,number);
            siz=line.substr(number+1);

            nameAndsize.push_back(Customer(nam,siz));

        }
        inFile.close();
    }
    vector <Customer>get_name_size()
    {
        return nameAndsize;
    }

};
class Chili_Basket{

    int totalNumOfChilis;

    public:
        Chili_Basket(int NumChili)
        {

            this->totalNumOfChilis= NumChili;
        }

    int  Chili()
    {
        int returned = 0;

        if(totalNumOfChilis==0)
        {
            cout<<"This batch of chili done."<<endl;
            returned =0;

        }
        else{
                if(totalNumOfChilis==1)
        {
            cout<<"Not much chili left"<<endl;
            returned=1;
        }
         else if(totalNumOfChilis==3||totalNumOfChilis==2)
        {
            cout<<"We still have plenty chilis"<<endl;
            returned =2;
        }
        totalNumOfChilis-=1;
        }
         return returned;

    }
};
class Store{
    public:
    void checking_continue(string ConTinue, int b)//checking  if the typed word is continue or not
    {
        Chili_Basket chiBa(b);
        if (ConTinue=="continue")
        {
           chiBa.Chili();
        }
    }
};

    int main(int argc, char ** argv)
{
    int NumberOfBatch;
    string Ans="hi";

    int c=0;
    int d=1;
    Order Ordr;
    Store Stre;
    //Ordr.reading_file(argv[1]);

    vector<Customer>list=Ordr.get_name_size();//listing the name and sizes

    cout<<"---Welcome Louise---\nChecking today's customers....done!"<<endl;
    cout<<"\n\n How many batches of your famous chili are you making today?";  // Getting number of Batches
    cin>>NumberOfBatch;
    cout<<"\nStarting orders...."<<endl;


    while(Ans!="exit" || Ans!="Exit")
    {
        cout<<"Customer "<< d <<" "<< list[c].get_name()<<"'s Order is "<<list[c+1].get_size()<<endl;


        cout<<"Continue with orders or take a break?";
        cin>>Ans;

        if (Ans=="break" || Ans=="Break")
        {
            cout<<"OK\nPress enter when you are done with the break\n";
            cin.get();
        }
        else if (Ans=="continue" || Ans=="Continue")
        {
            Stre.checking_continue(Ans,c);
            c=c+2;
            d++;
        }
    }
        return 0;
    }
