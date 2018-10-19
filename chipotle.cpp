//Indra Bhurtel

#include<iostream>
#include<fstream>
#include<cstdlib>

    using namespace std;

    ifstream myfile("chipotle.txt"); //Opening chipotle.txt having names of delivery persons

    class Delivery // Delivery class
{
        string first_name;
        string last_name;
        string full_name;
        static double total_money_made;

    public:
    void Creating_Delivery(double totalPrice) // Getting name of delivery person from chipotle.txt
{
        myfile>>first_name;
        myfile>>last_name;

    cout<<"\nOk, "<<first_name<<" will be delivering your order. Thank you";
}
    void apply()// Adding a delivery person in file chipotle.txt which is called by main function.

{
    ofstream add_name("chipotle.txt", ios::app);
    fflush(stdin);
    cout<<"\nEnter your full name: ";
    getline(cin, full_name);
    add_name<<"\n";
    add_name<<full_name;
    cout<<"Newest delivery person: "<<full_name;
    add_name.close();

}
    void add_to_total_money_made(double Delivery_Charge) // Adding delivery charge to the total_money_made
{
        total_money_made += Delivery_Charge;
}
        double gettotal_money_made()
{
        return total_money_made;
}
};

        double Delivery::total_money_made = 0;
        class Customer: public Delivery // Derived class Customer
{
    string chipotle_selection;
    string pick_one;
    string pick_two;
    string pick_three;
    string  options;
    double total_order;
    double price;

    public:
    void placeOrder()
{
    cout<<"\n*****Place your order*****";
    cin.ignore();
    cout<<"\nBurrito or Bowl?\n";
    fflush(stdin);
    getline(cin,chipotle_selection);

    if(chipotle_selection == "burrito" || chipotle_selection == "Burrito")
    total_order = 6.75;

    if(chipotle_selection == "bowl" || chipotle_selection == "Bowl")
    total_order = 5.49;

    cout<<"Price will be: $"<<total_order;
    cout<<"\n-Pick: Tofu, Steak, Chicken\n";
    getline(cin,pick_one);

    if(pick_one != "none")
    total_order += 1.99;//add $1.99 to total_order

    cout<<"\n-Pick: Cilantro-Lime Brown, Cilantro-Lime White\n";
    getline(cin,pick_two);

    if(pick_two != "none")
    total_order += 1.29;//add $1.29 to total_order

    cout<<"\n-Pick: Queso, Sour Cream, Fresh Tomato Salsa\n";
    getline(cin,pick_three);

    if(pick_three != "none")
    total_order += 0.39;//add $0.39 to total_order

    add_to_total_money_made(total_order*0.25);//Adding delivery charges to total_money_made
    total_order += (total_order*0.25);//Including 25% delivery charge

    cout<<"\nConfirm order (yes or no)\n";
    cout<<chipotle_selection<<": ";

    if(pick_one != "none")
    cout<<pick_one<<", ";

    if(pick_two != "none")
    cout<<pick_two<<", ";

    if(pick_three != "none")
    cout<<pick_three;

    cin>>options;

    if(options == "no")
    return;

    Creating_Delivery(total_order);
}
};

    int main()
{
    int options = 0;
    ofstream my_file("chipotle.txt", ios::app);// stores total made
    Customer Cus;

    cout<<"\n~~~~~~Ronnie's Delivery Service~~~~~~\n";

    while(options != 3)
{
    cout<<"\nPick from the following menu: ";
    cout<<"\n1. Customer";
    cout<<"\n2. Apply";
    cout<<"\n3. Exit\n";
    cin>>options;

    switch(options)
{
    case 1: Cus.placeOrder();
    break;

    case 2: Cus.apply();
    break;

    case 3: cout<<"\nExiting...\n";
    cout<<"Total Made: $"<<Cus.gettotal_money_made();

    my_file<<Cus.gettotal_money_made();
    my_file<<"\n";
    my_file.close();
    exit(0);
    break;

    default: cout<<"\nInvalid input";
}
}
    myfile.close();
    return 0;
}
