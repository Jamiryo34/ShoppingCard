#include "shoppingCart.h"

int shoppingCart::All_items= 0; // initializing static variable
//default constructor with string parameter
shoppingCart::shoppingCart(string name)
{
    costumer_name = name;
    number_of_products = 0;
    list_of_prices = nullptr;
    list_of_products = nullptr;
}
//destructor to make sure that we destroyed the dynamic memory allocated lists
shoppingCart::~shoppingCart(){
    delete [] list_of_prices;
    delete [] list_of_products;
}
// copy constructor
shoppingCart::shoppingCart(const shoppingCart& s)
{
    costumer_name = s.costumer_name;
    number_of_products = s.number_of_products;
    string* list_of_products = new string[number_of_products];
    double* list_of_prices = new double[number_of_products];
    for (int i=0; i<number_of_products; i++){
        list_of_products[i] = s.list_of_products[i];
        list_of_prices[i] = s.list_of_prices[i];
    }
}
//assignment operator
shoppingCart& shoppingCart::operator=(const shoppingCart& s)
{
    if (this != &s) {
    costumer_name = s.costumer_name;
    number_of_products = s.number_of_products;
    string* list_of_products = new string[number_of_products];
    double* list_of_prices = new double[number_of_products];
    for (int i=0; i<number_of_products; i++){
        list_of_products[i] = s.list_of_products[i];
        list_of_prices[i] = s.list_of_prices[i];
    }
    }
    return *this;
}
//getters and setters
string shoppingCart::getCostumer(){
    return costumer_name;
}
void shoppingCart::setCostumer(string name){
    costumer_name = name;
}
//addItem function : we must delete the old lists and make new ones with the new items
//also we will increase the item counter and the aAll items counter
void shoppingCart::addItem(string product, const double price){
    string* temp_products = new string[number_of_products + 1];
    double* temp_prices = new double[number_of_products + 1];
    for (int i=0; i<number_of_products; i++){
        temp_products[i] = list_of_products[i];
        temp_prices[i] = list_of_prices[i];
    }
    temp_products[number_of_products] = product;
    temp_prices[number_of_products] = price;
    delete [] list_of_products;
    delete [] list_of_prices;
    list_of_products = temp_products;
    list_of_prices = temp_prices;
    number_of_products ++;
    All_items ++;
}
//
int shoppingCart::cartSize(){
    return number_of_products;
}
//
double shoppingCart::totalCost(){
    double sum = 0;
    for (int i=0; i<number_of_products; i++){
        sum += list_of_prices[i];
    }
    return sum;
}
// overloading index operator
double& shoppingCart::operator[](const string product){
    for (int i=0; i<number_of_products; i++){
        if(list_of_products[i] == product)
            return list_of_prices[i];
    }
    throw runtime_error("The product you asked for doesn't exist\n"); // throw an error when we dont find the product we search for
}
// overloading shift << operator
ostream& operator<<(ostream& os, shoppingCart& s){
    os << "Costumer Name: " << s.costumer_name << "\t Number of products in this cart = " << s.cartSize() << "\nThe list of items an prices";
    os << "\nProduct" << "\t Price\n";
    for (int i=0; i<s.number_of_products; i++){
        os << s.list_of_products[i] << "\t" << s.list_of_prices[i] << "\n";
    }
    os << "\t  Total cost of cart : " << s.totalCost() << endl;
    return os;
}
void shoppingCart::removeItem(string name){
    int key = 0,j=0; // to check if we have deleted an item or not (if we delete it will be 1 and if we dont it will stay 0)
    string* temp_products = new string[number_of_products ];
    double* temp_prices = new double[number_of_products ];
    for (int i=0; i<number_of_products; i++){
        if(list_of_products[i] == name){
            key = 1;
        }
        else {
            temp_products[j] = list_of_products[i];
            temp_prices[j] = list_of_prices[i];
            j++;
        }
    }
    delete [] list_of_products;
    delete [] list_of_prices;
    list_of_products = temp_products;
    list_of_prices = temp_prices;
    if (key == 1){  // if statment to check if we deleted item or not
        cout << "The item has been deleted" << endl;
        number_of_products -- ;
        All_items --;
    }
    else throw runtime_error("The product you asked for doesn't exist\n"); // throw an error when we dont find te item
}
// get the summary of items in all carts
int shoppingCart::getItemCount(){
    return All_items;
}
