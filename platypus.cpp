#include "platypus.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

platypus::platypus () // Dead platypus need default constructor
{
    alive = false;
    mutant = false;
}
platypus::platypus(char name, char gender, short age, float weight) // this is explicit value constructor
{
    this->name = name;
    this->gender = gender;
    this->age= age;
    this->weight = weight;
    this->alive = true;
    this->mutant = false;
}
void platypus::age_me(){    // Age function
    if(alive==1){
    cout<< "\tEnter month number: ";
    A:
    int month, mutationRisk = 0;
    while(!(cin>>month)){
        cin.clear();
        cin.ignore(50,'\n');
        cout<< "\t Enter Valid Input.\n";
        goto A;
    }
    cout<<"\n\nAter "<<month<<" Months: \n\n";

    for(int i=0; i<month; i++){
        age++;
        mutationRisk = 2*(1+0.01*2*age);   // platypus mutation risk can be increased 2% in month
        }

    cout<<"\t"<<mutationRisk<< "% Mutation chances"<<endl;
    if(mutationRisk < 100){
        setplatmutant(0);}
    else{ setplatmutant(1);}
    }
    short deathRisk = (short)weight*10;   // platypus death risk 10 times
    if(deathRisk > 100){
        cout<< "\tplatypus cannot it anymore because it is dead"<<endl;    //platypus cannot it if it is dead
    }
    else{
        cout<<"\t"<<deathRisk<< "% dying chances"<<endl;}
}

void platypus::eat(){                                       // feeding platypus function
    float increase = getplatweight()*(rand()%50+1)/1000.0;
    if(alive==true){
    setplatweight(getplatweight()+increase);
        if(getplatweight()>=10){
            cout<< "\n\tooo..\n"<<endl;
            cout<< "\tplatypus cannot it anymore because it is dead"<<endl;
            cout<< "\tIt if it is dead cannot fight anymore"<<endl;
            setplatalive(0);
        }
        else{cout<< "\tThe Platypus Is Fattened\n\n";}
    }
}

void platypus::print(ostream & out)
{
    out << "\tNAME:       " << name << endl;
    out << "\tGENDER:     " << gender << endl;
    out << "\tAGE:        " << age <<" Months"<< endl;
    out << "\tWEIGHT:     " << weight <<" Pounds"<< endl;

    if(alive){
        cout << "\tALIVE:      Yes"<<endl;}
    else {
        cout << "\tALIVE:      No"<<endl;}
    if(mutant) {
        cout << "\tMUTANT:     Yes"<<endl;}
    else {
        cout << "\tMUTANT:     No"<<endl;}
    cout << endl;
}

ostream & operator<<(ostream & out, platypus & p)
{
  p.print(out);
  return out;
}

void platypus::fight(platypus & other)
{
    float weightRatio = (this->weight/other.getplatweight())*50;
    short rendomizing = rand()%100;

    if(!(this->alive && other.alive))
    {
        cout<< "platypus is dead and cannot fight one of them or both."<<endl;
    }
    else{
        if(rendomizing<weightRatio){
            cout<<"\n\t"<<this->name<<"survived\n"<<endl;
            other.setplatalive(0);
        }
        else{
            cout<<"\n\t"<<other.getplatname()<< " survived\n"<<endl;
            this->alive = false;
        }
    }
}
void platypus::hatch(){
    bool newbornplat_alive = true;                   // platypus alive
    bool newbornplat_mutant = false;                 //platypus mutant
    short newbornplatplat_age = 0;                       // platypus age
    float newbornplat_weight = (rand()%10+1)/10.0;   //platypus weight
    int genderRand = rand()%2;                   // platypus gender
    if(genderRand == 1)
        {gender = 'M';}
    else{gender = 'F';}

    char newborn_name=('a' + rand()%26);
    if(genderRand == 1){
        cout<< "\tThe newborn platypus is female, do you want to give her name? " << endl;
        char userName_f;
        B:
        while(!(cin>>userName_f))
        {
            cout<< "\t Choose A Random Letter From Alphabet";
            cin.clear();
            cin.ignore(50,'\n');
            goto B;
        }
        newborn_name = userName_f;
        }
    else{
        cout<< "\tThe newborn platypus is male, do you want to give him name? "<< endl;
        char userName_m;
        C:
        while(!(cin>>userName_m))
        {
            cout<< "\tPlease, Choose A Random Letter  From Alphabet...";
            cin.clear();
            cin.ignore(50,'\n');
            goto C;
        }
        newborn_name = userName_m;
        }
    cout<< "\n\tNewborn Platypus \n";
    setplatalive(newbornplat_alive);
    setplatmutant(newbornplat_mutant);
    setplatage(newbornplatplat_age);
    setplatweight(newbornplat_weight);
    setplatname(newborn_name);
}
    // definition of accessors
    char platypus::getplatname() const
    {return name;}
    short platypus::getplatage() const
    {return age;}
    float platypus::getplatweight() const
    {return weight;}
    char platypus::getplatgender() const
    {return gender;}
    bool platypus::getplatalive()const
    {return alive;}
    bool platypus::getplatmutant() const
    {return mutant;}

    void platypus::setplatname(char nameP){this->name = nameP;}
    void platypus::setplatage(char ageP){this->age = ageP;}
    void platypus::setplatweight(float weightP){this->weight = weightP;}
    void platypus::setplatgender(char genderP){this->gender = genderP;}
    void platypus::setplatalive(bool aliveP){this->alive = aliveP;}
    void platypus::setplatmutant(bool mutantP){this->mutant = mutantP;}

platypus::~platypus(){}
