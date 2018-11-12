#include "Map.h"

Map::Map()
{
    //ctor
}

Map::Map(int** matrix, List_Images *img){
    this->matrix = matrix;
    this->img = img;
    srand(NULL);

    generateStructures();
}

void Map::generateStructures(){

    bool upStone;
    bool downStone;
    bool leftStone;
    bool rightStone;

    for(int i = 0; i<24; i++){
        for(int j = 0; j<36; j++){

            if(matrix[i][j] == 0)
            {
                upStone = false;
                downStone = false;
                leftStone = false;
                rightStone = false;

                if(i != 0 && matrix[i-1][j] != 0)
                    upStone = true;
                if(j != 35 && matrix[i][j+1] != 0)
                    rightStone = true;
                if(i != 23 && matrix[i+1][j] != 0)
                    downStone = true;
                if(j != 0 && matrix[i][j-1] != 0)
                    leftStone = true;

                if(upStone)
                {
                    if(downStone)
                    {
                        if(rightStone)
                            structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[13])));
                        else if(leftStone)
                            structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[15])));
                        else
                            structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[11])));
                    }
                    else if(rightStone)
                    {
                        if(leftStone)
                            structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[16])));
                        else
                            structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[7])));
                    }
                    else if(leftStone)
                        structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[10])));
                    else
                        structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[3])));
                }
                else if(rightStone)
                {
                    if(leftStone)
                    {
                        if(downStone)
                            structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[14])));
                        else
                            structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[12])));
                    }
                    else if(downStone)
                        structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[8])));
                    else
                        structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[4])));
                }
                else if(downStone)
                {
                    if(leftStone)
                        structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[9])));
                    else
                        structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[5])));
                }
                else if(leftStone)
                        structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[6])));
                else
                {
                    int aux;
                    aux = rand()%3;
                    structures.include(static_cast<Structure*>(new Stone(30*j, 30*i, (*img)[aux])));
                }
            }
            else if(matrix[i][j] == 2){
                Lava* aux;
                if(matrix[i-1][j] != 2 && matrix[i-1][j] != 3)
                    aux = new Lava(30*j, 30*i, (*img)[18]);
                else
                    aux = new Lava(30*j, 30*i, (*img)[17]);

                obstacles.include(static_cast<Obstacle*>(aux));
            }
            else if(matrix[i][j] == 3){
                Lava* aux = new Lava(30*j, 30*i, (*img)[18]);
                obstacles.include(static_cast<Obstacle*>(aux));
                lavas.include(aux);
            }
            else if(matrix[i][j] == 4){
                int side;
                if(matrix[i-1][j] == 0){
                    side = 21;
                }
                else if(matrix[i+1][j] == 0){
                    side = 19;
                }
                else if(matrix[i][j+1] == 0){
                    side = 22;
                }
                else if(matrix[i][j-1] == 0){
                    side = 20;
                }
                obstacles.include(static_cast<Obstacle*>(new Spine(30*j, 30*i, (*img)[side])));
            }
        }
    }
}

void Map::printMap(BITMAP* screen){
    for(int i = 0; i<structures.size(); i++){
        structures[i]->print(screen);
    }
    for(int i = 0; i<obstacles.size(); i++){
        obstacles[i]->print(screen);
    }
}

int** Map::getMatrix(){
    return matrix;
}

/*Returns the value of the matrix in the given (i, j) position
If at least one of the values is invalid, NULL is returned.*/
int Map::getValueMap(int i, int j){
    if(j > 35 || j < 0 || i > 23 || i < 0)
        return -1;
    return matrix[i][j];
}

List_Structures* Map::getList()
{
    return &structures;
}

List_Obstacles* Map::getListObstacles(){
    return &obstacles;
}

List_Lavas* Map::getListLavas(){
    return &lavas;
}

Map::~Map()
{
    for(int i = 0; i<24; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = NULL;
}
