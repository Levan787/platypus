#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#ifndef PLATYPUS_H
#define PLATYPUS_H

class platypus
{
    public:
        platypus(); // platypus is dead
        platypus(char name, char gender, short age, float weight);
        void age_me();                      // increase object's age
        void eat();                         //  increase object's weight
        void hatch();                       //  create a newborn platypus
        void print(ostream & out);          //  show output on screen
        void fight(platypus & another_p);   //  platypuses start fight

        char getplatname() const;
        short getplatage() const;
        float getplatweight() const;
        char getplatgender() const;
        bool getplatalive()const;
        bool getplatmutant() const;

        void setplatname(char nameP);
        void setplatage(char ageP);
        void setplatweight(float weightP);
        void setplatgender(char genderP);
        void setplatalive(bool aliveP);
        void setplatmutant(bool mutantP);

        virtual ~platypus();

    private:
        char name;
        char gender;
        short age;
        float weight;
        bool alive;
        bool mutant;
};

#endif
