#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream>
#include <string>
using namespace std;

class shoppingCart
{
    private:
        string costumer_name;
        double* list_of_prices;
        string* list_of_products;
        int number_of_products; //number of product in one shopping cart (will be the length of the lists)
        static int All_items; // for the getItemCount() methd counts all the products we`ve added in all shopping carts

    public:
        shoppingCart(string name = " ");
        shoppingCart(const shoppingCart& s);
        shoppingCart& operator=(const shoppingCart& s);
        ~shoppingCart();
        //getters and setters
        string getCostumer();
        void setCostumer(string name);
        //
        void addItem(string product, const double price);
        void removeItem(string name);
        int cartSize();
        double totalCost();
        static int getItemCount();
        double& operator[](const string product);
        friend ostream& operator<<(ostream& os, shoppingCart& s);
};

#endif // SHOPPINGCART_H
