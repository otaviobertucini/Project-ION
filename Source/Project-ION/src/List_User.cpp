#include "List_User.h"

List_user::List_user()
{

}

void List_user::Import_List()
{
    string line;
    ifstream file("Register/Rank/Rank.txt");

    int i,level;
    float score;

    if(file.is_open())
    {

        while(getline(file,line))
        {
            i=0;
            while(line[i] != ',')
                i++;

            string name(line,0,i);
            i++;
            level = line[i] - 48;
            i+=2;

            string score_copy(line,i,line.size()-1);
            score = (float) atof(score_copy.c_str());

            User *user_aux = new User;
            user_aux->setAll(name,score,level);
            users.push_back(user_aux);
        }

    }
    else
        cout << "n abriu" << endl;
}

void List_user::Export_List()
{
    typename std::vector<User*>::iterator itr = users.begin();
    int i = 0;
    ofstream file("Register/Rank/Rank.txt");
    if(file.is_open())
    {
        for(;itr< users.end(); itr++)
        {
            file << users[i]->getName() << "," << users[i]->getLevel() << "," << users[i]->getScore() << "\n";
            i++;
        }
    }
}

void List_user::Add_User(User* user)
{
    typename std::vector<User*>::iterator itr = users.begin();
    bool confirm = false;
    int i,save_i;
    i=0;
    for(; itr != users.end(); itr++)
    {
        if(user->getName().compare(users[i]->getName()) == 0)
        {
            confirm = true;
            save_i = i;
        }
        i++;
    }

    if(confirm)
    {
        users[save_i]->setLevel(user->getLevel());
        users[save_i]->setScore(user->getScore() + users[save_i]->getScore());
    }
    else
        users.push_back(user);
}

void List_user::Insertion_Sort_Level()
{
    int i,j;
    typename std::vector<User*>::iterator itr = users.begin();

    i=0;
    for(;itr != users.end();itr++)
    {
        j=i;
        while(j-1 >= 0 && (users[j-1]->getLevel() < users[j]->getLevel() || (users[j-1]->getLevel() == users[j]->getLevel() && users[j-1]->getScore() > users[j]->getScore())))
        {
            swap(users[j],users[j-1]);
            j--;
        }
        i++;
    }

}

void List_user::setCurrentUser(User* user)
{
    current_user = user;
}

int List_user::getSize()
{
    cout << users.size() << endl;
    return users.size();
}

User* List_user::getUser(int i)
{
    return users[i];
}

List_user::~List_user()
{
    typename std::vector<User*>::iterator itr = users.begin();
    for(; itr != users.end(); itr++)
        delete *itr;
    users.clear();
}
