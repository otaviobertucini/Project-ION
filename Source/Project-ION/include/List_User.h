#ifndef LIST_USER_H
#define LIST_USER_H
#include <Vector>
#include <fstream>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "User.h"

using std::cout;
using std::endl;

class List_user
{
public:
    List_user();
    void Import_List();
    void Export_List();
    void Add_User(User* user);
    void Insertion_Sort_Level();
    void setCurrentUser(User* user);
    ~List_user();
private:
    vector<User*> users;
    User* current_user;
};
#endif // LIST_USER_H
