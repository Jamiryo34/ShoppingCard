#include <iostream>
#include <string>
#include "shoppingCart.h"
using namespace std;

int main()
{
    shoppingCart s1("ahmed");
    s1.addItem("milk",3);
    s1.addItem("meat",50);
    s1.addItem("water",2);
    cout << s1;
    cout << "price of the product is " << s1["meat"] << endl;
    s1["meat"] = 57;
    cout << "price of the product is " << s1["meat"] << endl;
    s1.removeItem("water");
    cout << s1;
    //s1.removeItem("choclate");
    shoppingCart s2("james");
    s2.addItem("yougurt",3);
    s2.addItem("chicken",25);
    s2.addItem("mineral water",2.5);
    cout << s2;
    cout << "number of All items :" << shoppingCart::getItemCount() << endl;
    return 0;
}
