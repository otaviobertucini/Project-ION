#ifndef PERSONAGEM_H
#define PERSONAGEM_H


class Personagem
{
    public:
        Personagem();
        virtual ~Personagem();

        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        int Gety_speed() { return y_speed; }
        void Sety_speed(int val) { y_speed = val; }
        int Getx_speed() { return x_speed; }
        void Setx_speed(int val) { x_speed = val; }

    protected:

    private:
        int x;
        int y;
        string name;
        int y_speed;
        int x_speed;
};

#endif // PERSONAGEM_H
