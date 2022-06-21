#include <iostream>
using namespace std;
struct Address
{
    string *City;
    string *Location;
    int OutletID[10];
};
struct Flavor
{
    string flavorname;
    int Price[2];
};

struct Customer
{
    char name[127];
    int custID;
    float purchase = 0;
    int age;
    int weekdayscount = 1;
    int weekly_purchase = 0;
    int week_number = 1;
    bool week_checker = false;
    bool having_discount = false;
};
struct ICEOutlet
{
    int *storing_the_subscriptvalue_of_customers = new int[1];
    void increasing_the_size_of_array(int *&oldArr, const int count)
    {
        int *newArr = new int[count];
        copy(oldArr, oldArr + (count - 1), newArr);
        delete[] oldArr;
        oldArr = newArr;
    }
    float purchase = 0;
    Customer TopCus[10];
    int customercount = 0;
};
void increasing_size_of_array(Customer *&oldArr, const int count)
{
    Customer *newArr = new Customer[count];
    copy(oldArr, oldArr + (count - 1), newArr);
    delete[] oldArr;
    oldArr = newArr;
}
void sorting(Customer customer_data[], ICEOutlet outlets_and_their_data[], Address cities_and_their_locations[])
{
    int highest = 0, secoundhighest = 2147483647, max, count = 0, count_discount = 0;
    bool idcheck = false;
    for (int i = 0; i < 50; i++)
    {
        for (int k = 0; k < outlets_and_their_data[i].customercount; k++)
        {

            if (outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k] >= 0 && customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].having_discount)
            {
                highest = customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[0]].weekly_purchase;
            }
        }
        for (int count=0;count< outlets_and_their_data[i].customercount;count++)
        {
            if (customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[count]].having_discount)
            count_discount++;
        }
        for (int l = 0; l < count_discount; l++)
        {
            for (int k = 0; k < outlets_and_their_data[i].customercount; k++)
            {
                if (customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].having_discount)
                {
                    if (k == 0)
                    {
                        if (highest <= customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].weekly_purchase)
                        {

                            highest = customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].weekly_purchase;
                            outlets_and_their_data[i].TopCus[count] = customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]];
                        }
                    }
                    else
                    {
                        max = customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].weekly_purchase;
                        if (highest <= customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].weekly_purchase && max < secoundhighest)
                        {

                            highest = customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].weekly_purchase;
                            outlets_and_their_data[i].TopCus[count] = customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]];
                        }
                    }
                }
            }
            count++;

            for (int k = 0; k < outlets_and_their_data[i].customercount; k++)
                if (outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k] >= 0 && customer_data[outlets_and_their_data[i].storing_the_subscriptvalue_of_customers[k]].having_discount)
                {
                    secoundhighest = highest;
                    highest = 0;
                }
        }
        count = 0;
        secoundhighest = 2147483647;
    }
}
void cities_and_their_Outlets(Address cities_and_their_locations[], string cities[], string islamabad_loactions[], string lahore_loactions[], string Rawalpindi_loactions[], string Karachi_loactions[], string faisalabad_loactions[])
{
    cities_and_their_locations[0].City = &cities[0];
    cities_and_their_locations[1].City = &cities[1];
    cities_and_their_locations[2].City = &cities[2];
    cities_and_their_locations[3].City = &cities[3];
    cities_and_their_locations[4].City = &cities[4];
    cities_and_their_locations[0].Location = islamabad_loactions;
    cities_and_their_locations[1].Location = Rawalpindi_loactions;
    cities_and_their_locations[2].Location = lahore_loactions;
    cities_and_their_locations[3].Location = Karachi_loactions;
    cities_and_their_locations[4].Location = faisalabad_loactions;
}
void function_for_customers(Address cities_and_their_locations[], ICEOutlet outlets_and_their_data[], int &pick, int &choose, Customer *&customer_data, int &countforcustomers, Flavor flavor_of_icecreams[])
{
    int pack = 0, old_customer_id_check, old_customer_id_store;
    int input_of_menu_for_new_or_old_customer;
    bool old_customer_checker = false, new_customer_checker = false;
    bool  weekly_purchase_checker;

    if (outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].customercount != 0)
    {
        cout << "Choose from the options : \n\t1.New Customer \n\t2.Old Customer \n";
        cin >> input_of_menu_for_new_or_old_customer;
        while (input_of_menu_for_new_or_old_customer != 1 && input_of_menu_for_new_or_old_customer != 2)
        {
            cout << "Not choosing from the menu !, Choose again !\n";
            cin >> input_of_menu_for_new_or_old_customer;
        }
        if (input_of_menu_for_new_or_old_customer == 1)
        {
            cout << "\n\n************" << cities_and_their_locations[choose - 1].Location[pick - 1] << "************\n\n";
            cout << "Hello new customer ! \n";
            cout << "Enter the id of customer : ";
            cin >> customer_data[countforcustomers - 1].custID;
            while (new_customer_checker == false)
            {
                for (int i = 0; i < countforcustomers - 1; i++)
                {
                    if (customer_data[countforcustomers - 1].custID == customer_data[i].custID)
                    {
                        cout << "Id already in use, Enter id again : ";
                        cin >> customer_data[countforcustomers - 1].custID;
                        break;
                    }
                }
                new_customer_checker = true;
            }
            cout << "Enter the name of the customer : ";
            cin.ignore();
            cin.clear();
            cin.getline(customer_data[countforcustomers - 1].name, 127);
            cout << "Enter the age of the customer : ";
            cin >> customer_data[countforcustomers - 1].age;
            outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].customercount++;
        }
        else if (input_of_menu_for_new_or_old_customer == 2)
        {

            while (old_customer_checker == false)
            {
                cout << "Enter your id to continue : ";
                cin >> old_customer_id_check;
                for (int i = 0; i < countforcustomers; i++)
                {
                    if (old_customer_id_check == customer_data[i].custID)
                    {
                        old_customer_checker = true;
                        cout << "Welcome back! " << customer_data[i].name << endl;
                        old_customer_id_store = i;
                    }
                }
                if (old_customer_checker == false)
                    cout << "Invalid Id, Enter id again\n";
            }
            if (customer_data[old_customer_id_store].weekly_purchase > 2000)
            {
                weekly_purchase_checker = true;
                
            }
            if (customer_data[old_customer_id_store].weekdayscount == 0)
            {
                customer_data[old_customer_id_store].purchase = 0;
                customer_data[old_customer_id_store].weekly_purchase = 0;
               if (customer_data[old_customer_id_check].week_checker) 
                customer_data[old_customer_id_store].having_discount = false;
            }
            customer_data[old_customer_id_store].weekdayscount++;
        }
    }
    else
    {
        cout << "\n\n************" << cities_and_their_locations[choose - 1].Location[pick - 1] << "************\n\n";
        cout << "Hello new customer ! \n";
        cout << "Enter the id of customer : ";
        cin >> customer_data[countforcustomers - 1].custID;
        while (new_customer_checker == false)
        {
            for (int i = 0; i < countforcustomers - 1; i++)
            {
                if (customer_data[countforcustomers - 1].custID == customer_data[i].custID)
                {
                    cout << "Id already in use, Enter id again : ";
                    cin >> customer_data[countforcustomers - 1].custID;
                    break;
                }
            }
            new_customer_checker = true;
        }
        cout << "Enter the name of the customer : ";
        cin.ignore();
        cin.clear();
        cin.getline(customer_data[countforcustomers - 1].name, 127);
        cout << "Enter the age of the customer : ";
        cin >> customer_data[countforcustomers - 1].age;
        outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].customercount++;
        cout << customer_data[countforcustomers - 1].name << endl;
    }
    int choose1 = 0;
    while (choose1 != 5)
    {
        cout << "Choose from the menu :\n\t1.Mango\n\t2.Strawberry\n\t3.Chocolate\n\t4.Vanilla\n";
        if (choose1 != 0)
            cout << "Select another from the menu or press 5" << endl;
        cin >> choose1;
        if (choose1 != 5 && (choose1 > 0 && choose1 < 5))
        {
            cout << "Great Choice ! " << flavor_of_icecreams[choose1 - 1].flavorname << endl;
            cout << "The price for this flavor of Ice Cream is : \n";
            cout << "1. " << flavor_of_icecreams[choose1 - 1].Price[0] << " for the small pack \n";
            cout << "2. " << flavor_of_icecreams[choose1 - 1].Price[1] << " for the large pack \n";
            cout << "Choose your pack : ";
            cin >> pack;
            while (pack != 1 && pack != 2)
            {
                cout << "Not choosing from the menu !" << endl;
                cin >> pack;
            }
            if (weekly_purchase_checker == true && pack == 2)
            {
                customer_data[old_customer_id_store].purchase = customer_data[old_customer_id_store].purchase + (flavor_of_icecreams[choose1 - 1].Price[pack - 1] - ((flavor_of_icecreams[choose1 - 1].Price[pack - 1] / 100) * 5));
                outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].purchase = (flavor_of_icecreams[choose1 - 1].Price[pack - 1] - ((flavor_of_icecreams[choose1 - 1].Price[pack - 1] / 100) * 5)) + outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].purchase;
            }
            else if (old_customer_checker == true)
            {
                customer_data[old_customer_id_store].purchase = customer_data[old_customer_id_store].purchase + flavor_of_icecreams[choose1 - 1].Price[pack - 1];
                outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].purchase = flavor_of_icecreams[choose1 - 1].Price[pack - 1] + outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].purchase;
            }
            else
            {
                cout<<"hello"<<endl;
                customer_data[countforcustomers - 1].purchase = customer_data[countforcustomers - 1].purchase + flavor_of_icecreams[choose1 - 1].Price[pack - 1];
                outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].purchase = flavor_of_icecreams[choose1 - 1].Price[pack - 1] + outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].purchase;
            }
        }
    }

    if (old_customer_checker == false)
    {
        if (customer_data[countforcustomers - 1].weekly_purchase > 2000)
            customer_data[countforcustomers - 1].having_discount = true;
        customer_data[countforcustomers - 1].weekly_purchase = customer_data[countforcustomers - 1].purchase;
        if (customer_data[countforcustomers - 1].weekly_purchase > 2000)
            customer_data[countforcustomers - 1].having_discount = true;
        customer_data[countforcustomers - 1].weekdayscount++;
        cout << "The purchase of this customer is " << customer_data[countforcustomers - 1].purchase << endl;
        outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].storing_the_subscriptvalue_of_customers[outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].customercount - 1] = countforcustomers - 1;        countforcustomers++;
        outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].increasing_the_size_of_array(outlets_and_their_data[cities_and_their_locations[choose - 1].OutletID[pick - 1]].storing_the_subscriptvalue_of_customers, countforcustomers);
        increasing_size_of_array(customer_data, countforcustomers);
    }
    else
    {
        cout << "The purchase of " << customer_data[old_customer_id_store].name << " is " << customer_data[old_customer_id_store].purchase << endl;
        customer_data[old_customer_id_store].weekly_purchase = customer_data[old_customer_id_store].purchase;
        if (customer_data[old_customer_id_store].weekly_purchase > 2000)
            customer_data[old_customer_id_store].having_discount = true;
        if (customer_data[old_customer_id_store].weekdayscount == 7 && old_customer_checker == true)
        {
            customer_data[old_customer_id_store].weekdayscount = 0;
            customer_data[old_customer_id_store].week_number++;
            if (customer_data[old_customer_id_store].having_discount)
            customer_data[old_customer_checker].week_checker = false;
            else 
            customer_data[old_customer_checker].week_checker = true;

        }
    }
}

void function_for_outlets(Address cities_and_their_locations[], ICEOutlet outlets_and_their_data[], int &choose, int &countforcustomers, Customer *&customer_data, Flavor flavor_of_icecreams[])
{
    int pick = 0;
    if (choose == 1)
    {
        while (pick != 11)
        {
            cout << "City Name : " << *(cities_and_their_locations[0].City) << endl;
            for (int i = 0; i < 10; i++)
                cout << i + 1 << ". Outlet (id):" << cities_and_their_locations[0].OutletID[i] << " location : " << cities_and_their_locations[0].Location[i] << endl;
            cout << "11.Exit\n";
            cin >> pick;
            if (pick != 11 && (pick > 0 && pick < 11))
                function_for_customers(cities_and_their_locations, outlets_and_their_data, pick, choose, customer_data, countforcustomers, flavor_of_icecreams);
        }
    }
    else if (choose == 2)
    {
        while (pick != 11)
        {
            cout << "City Name : " << *(cities_and_their_locations[1].City) << endl;
            for (int i = 0; i < 10; i++)
                cout << i + 1 << ". Outlet (id):" << cities_and_their_locations[1].OutletID[i] << " location : " << cities_and_their_locations[1].Location[i] << endl;
            cout << "11.Exit\n";
            cin >> pick;
            if (pick != 11 && (pick > 0 && pick < 11))
                function_for_customers(cities_and_their_locations, outlets_and_their_data, pick, choose, customer_data, countforcustomers, flavor_of_icecreams);
        }
    }
    else if (choose == 3)
    {
        while (pick != 11)
        {
            cout << "City Name : " << *(cities_and_their_locations[2].City) << endl;
            for (int i = 0; i < 10; i++)
                cout << i + 1 << ". Outlet (id):" << cities_and_their_locations[2].OutletID[i] << " location : " << cities_and_their_locations[2].Location[i] << endl;
            cout << "11.Exit\n";
            cin >> pick;
            if (pick != 11 && (pick > 0 && pick < 11))
                function_for_customers(cities_and_their_locations, outlets_and_their_data, pick, choose, customer_data, countforcustomers, flavor_of_icecreams);
        }
    }
    else if (choose == 4)
    {
        while (pick != 11)
        {
            cout << "City Name : " << *(cities_and_their_locations[3].City) << endl;
            for (int i = 0; i < 10; i++)
                cout << i + 1 << ". Outlet (id):" << cities_and_their_locations[3].OutletID[i] << " location : " << cities_and_their_locations[3].Location[i] << endl;
            cout << "11.Exit\n";
            cin >> pick;
            if (pick != 11 && (pick > 0 && pick < 11))
                function_for_customers(cities_and_their_locations, outlets_and_their_data, pick, choose, customer_data, countforcustomers, flavor_of_icecreams);
        }
    }
    else if (choose == 5)
    {
        while (pick != 11)
        {
            cout << "City Name : " << *(cities_and_their_locations[4].City) << endl;
            for (int i = 0; i < 10; i++)
                cout << i + 1 << ". Outlet (id):" << cities_and_their_locations[4].OutletID[i] << " location : " << cities_and_their_locations[4].Location[i] << endl;
            cout << "11.Exit\n";
            cin >> pick;
            if (pick != 11 && (pick > 0 && pick < 11))
                function_for_customers(cities_and_their_locations, outlets_and_their_data, pick, choose, customer_data, countforcustomers, flavor_of_icecreams);
        }
    }
}

void CustomerRanking_By_Outlets(Customer *customer_data, ICEOutlet outlets_and_their_data[], Address cities_and_their_locations[], int countforcustomer)
{

    sorting(customer_data, outlets_and_their_data, cities_and_their_locations);
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "   City Name   :"
             << '\t' << *(cities_and_their_locations[i].City) << '\n';

        for (int j = 0; j < 10; j++)
        {
            cout << "   Outlet Name : ";
            cout << cities_and_their_locations[i].Location[j] << endl;
            for (int k = 0; k < outlets_and_their_data[count].customercount; k++)
            {
                if (outlets_and_their_data[cities_and_their_locations[i].OutletID[j]].TopCus[k].having_discount == true)
                {
                    cout << "Customer id#\t\tCustomer name : \tCustomer purchase " << endl;
                    cout
                        << outlets_and_their_data[cities_and_their_locations[i].OutletID[j]].TopCus[k].custID
                        << "\t\t\t"
                        << outlets_and_their_data[cities_and_their_locations[i].OutletID[j]].TopCus[k].name
                        << "\t\t\t"
                        << outlets_and_their_data[cities_and_their_locations[i].OutletID[j]].TopCus[k].purchase
                        << endl;
                }
            }
            count++;
        }
        cout << endl;
    }
}
void revenue_of_all_the_outlets(ICEOutlet outlets_and_their_data[], Address cities_and_their_locations[], int countforcustomer)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\n Outlet City : " << *(cities_and_their_locations[i].City) << endl;
        for (int j = 0; j < 10; j++)
        {
            cout << "Branch " << cities_and_their_locations[i].Location[j] << " revenue is " << outlets_and_their_data[cities_and_their_locations[i].OutletID[j]].purchase << endl;
        }
    }
}
void customer_weekly_purchase(Customer *customer_data, int countforcustomer)
{
    int input_id;
    cout << "Enter the id of the customer to continue : ";
    cin >> input_id;
        for (int i = 0; i < countforcustomer; i++)
        {
            if (input_id == customer_data[i].custID)
            {
                cout << "The purchase of " << customer_data[i].name << " for week" << customer_data[i].week_number << "  is : " << customer_data[i].purchase << endl;
                if (customer_data[i].weekly_purchase > 2000)
                    cout << " This customer is a regular customer and discount has been already applied on this customer \n";
            }
        }
}
void age_group_getting_the_discount(Customer *customer_data, int countforcustomer)
{
    int age_storing = 0, count = 0;
    for (int i = 0; i < countforcustomer; i++)
    {
        if (customer_data[i].having_discount)
        {
            age_storing = age_storing + customer_data[i].age;
            count++;
        }
        else
            continue;
    }
    if (count == 0)
        cout << "\nNo Customer has the discount yet !\n";
    else
        cout << "The average age of the customers that are getting the discount is " << (age_storing / count) << endl;
}
int main()
{

    // Initialzing the values (names and prices of different ice creams)
    Flavor flavor_of_icecreams[4];
    flavor_of_icecreams[0].flavorname = "Mango";
    flavor_of_icecreams[1].flavorname = "Strawberry";
    flavor_of_icecreams[2].flavorname = "Chocolate";
    flavor_of_icecreams[3].flavorname = "Vanilla";
    flavor_of_icecreams[0].Price[0] = 30;
    flavor_of_icecreams[0].Price[1] = 120;
    flavor_of_icecreams[1].Price[0] = 40;
    flavor_of_icecreams[1].Price[1] = 4000;
    flavor_of_icecreams[2].Price[0] = 40;
    flavor_of_icecreams[2].Price[1] = 130;
    flavor_of_icecreams[3].Price[0] = 25;
    flavor_of_icecreams[3].Price[1] = 110;

    Address cities_and_their_locations[5];
    ICEOutlet outlets_and_their_data[50];
    int countforcustomers = 1;
    Customer *customer_data = new Customer[countforcustomers];
    string cities[5] = {"Islamabad", "Rawalpindi", "Lahore", "Karachi", "Faisalabad"};
    string islamabad_loactions[10] = {"G-10/4", "G-10 Markaz", "G-11/2", "F-11", "F-7", "F-9", "DHA", "Bahria", "Ghauri Town", "Blue Area"};
    string lahore_loactions[10] = {"Gulberg", "Model Town", "Mall road", "Askari XI", "Punjab Housing Society", "Canal Society", "DHA", "Bahria", "Cantt", "Park View City"};
    string Rawalpindi_loactions[10] = {"Satelite Town", "Fazal Town", "Airport Society", "Peshawar road", "Adyala Road", "Capital City", "Cantt", "Commerical Market", "Airport Road", "Freedom Society"};
    string Karachi_loactions[10] = {"K-Place 1", "K-Place 2", "K-Place 3", "K-Place 4", "K-Place 5", "K-Place 6", "K-Place 9", "K-Place 8", "K-Place 9", "K-Place 10"};
    string faisalabad_loactions[10] = {"F-Place 1", "F-Place 2", "F-Place 3", "F-Place 4", "F-Place 5", "F-Place 6", "F-Place 7", "F-Place 8", "F-Place 9", "F-Place 10"};
    for (int i = 0; i < 50; i++)
    {
        if (i < 10)
            cities_and_their_locations[0].OutletID[i] = i;
        else if (i >= 10 && i < 20)
            cities_and_their_locations[1].OutletID[i - 10] = i;
        else if (i >= 20 && i < 30)
            cities_and_their_locations[2].OutletID[i - 20] = i;
        else if (i >= 30 && i < 40)
            cities_and_their_locations[3].OutletID[i - 30] = i;
        else if (i >= 40 && i < 50)
            cities_and_their_locations[4].OutletID[i - 40] = i;
    }

    cities_and_their_Outlets(cities_and_their_locations, cities, islamabad_loactions, lahore_loactions, Rawalpindi_loactions, Karachi_loactions, faisalabad_loactions);
    int choose = 0, pick = 0;
    while (pick != 6)
    {
        cout << "Choose from the menu : \n\t1.Dealing with Outlets and Customers \n\t2.Customer Ranking\n\t3.Weekly Purchase By a Customer\n\t4.Revenue Generated by each Outlet \n\t5.Age Group getting most of the discount\n\t6.Exit\n";
        cin >> pick;
        if (pick != 6)
        {
            switch (pick)
            {
            case 1:
                cout << "Choose the city : " << endl;
                while (choose != 6)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        cout << i + 1 << ". " << cities[i] << "\t\n";
                    }
                    cout << "6. Exit\n";
                    cin >> choose;
                    if (choose != 6 && choose >= 1 && choose <= 5)
                        function_for_outlets(cities_and_their_locations, outlets_and_their_data, choose, countforcustomers, customer_data, flavor_of_icecreams);
                }
                choose = 0;
                break;
            case 2:
                CustomerRanking_By_Outlets(customer_data, outlets_and_their_data, cities_and_their_locations, countforcustomers);
                break;
            case 4:
                revenue_of_all_the_outlets(outlets_and_their_data, cities_and_their_locations, countforcustomers);
                break;
            case 3:
                customer_weekly_purchase(customer_data, countforcustomers);
                break;
            case 5:
                age_group_getting_the_discount(customer_data, countforcustomers);
                break;
            }
        }
    }
    delete[] customer_data;
    for (int i = 0; i < 50; i++)
    {
        delete outlets_and_their_data[i].storing_the_subscriptvalue_of_customers;
    }

    return 0;
}