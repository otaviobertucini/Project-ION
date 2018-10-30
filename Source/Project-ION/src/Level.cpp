#include "Level.h"

Level::Level()
{
    //ctor
}

Level::Level(BITMAP* buffer, Images *images){
    map = NULL;
    this->buffer = buffer;
    this->images = images;
    characters = new List_Characters;
}

int Level::isCollide(Entity* a, Entity* b){
    int x_sum = (a->getw()/2)+(b->getw()/2);
    int y_sum = (a->geth()/2)+(b->geth()/2);
    if((abs(a->getx() - b->getx()) < x_sum) && (abs(a->gety() - b->gety()) <= y_sum ))
        return 1;
    return 0;
}

void Level::isStructureCollide(Character* a)
{
    int i;
    float x_center,y_center,x_center_body,y_center_body;

    x_center = a->getx()+(a->getw()/2);
    y_center = a->gety()+(a->geth()/2);

    List_Structures* aux;
    aux = map->getList();

    a->setLeft(true);
    a->setRight(true);
    a->setUp(true);
    a->setDown(true);

    for(i=0; i<aux->size(); i++)
    {

        x_center_body = (*aux)[i]->getx() + 15;
        y_center_body = (*aux)[i]->gety() + 15;

        //if( isCollide(a, static_cast<Entity*>((*aux)[i])) )
        //{
            if(a->gety() + a->geth() >= (*aux)[i]->gety() && a->gety() + a->geth() <= (*aux)[i]->gety() + 3
                    && abs(x_center - x_center_body) < 33)
            {
                a->setDown(false);
                a->sety((*aux)[i]->gety() - a->geth());
            }

            else if(a->gety() <= (*aux)[i]->gety() + 30 && a->gety() >= (*aux)[i]->gety() + 27
                    && abs(x_center - x_center_body) < 33)
            {
                a->setUp(false);
            }

            else if(a->getx() + a->getw() == (*aux)[i]->getx() && abs(y_center - y_center_body) < a->getw()+3)
                a->setRight(false);

            else if(a->getx() == (*aux)[i]->getx() + 30 && abs(y_center - y_center_body) < a->getw()+3)
                a->setLeft(false);
        //}
    }
}

Map* Level::getMap(){
    return map;
}

/*This function print the background of the level.*/
void Level::printMap(){
    map->printMap(buffer);
}

//Update all the positions of the characters placed in the level.
void Level::updatePosition(){
    for(int i = 0; i < characters->size(); i++){
        (*characters)[i]->print(buffer);
    }
}

void Level::loopCharacters(){
    for(int i = 0; i < characters->size(); i++){
        (*characters)[i]->loop();
    }
}

void Level::collisionCharacters(){
    for(int i = 0; i < characters->size(); i++){
        isStructureCollide((*characters)[i]);
    }
}

int Level::getValueMap(int i, int j){
    return map->getValueMap(i, j);
}

Level::~Level()
{
    characters->deleteAll();
    delete jack;
    jack = NULL;
}
