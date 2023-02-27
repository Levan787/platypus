#include "platypus.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


int main(){

    srand(time(0));
    cout<<"\n\t Welcome To Fedora Man's Computer Simulations \n";
    cout<<"\t\t Here You Will Encounter Small Platypuses\n\n";
    cout<<"\t\t Click << I >> To see platypuses \n";
    cout<<"\t\t Click << O >> To exit ";
    char answer;
    start:
    cin>>answer;
    if(tolower(answer) == 'i'){
    cout<< "\n\n\n";
    }
    else if(tolower(answer) == 'o'){
        cout<< "\n\n\t\t\t\t<< we will meet soon! >> \n\n\n\n";
        return 0;
    }
    else{
        cout<< "\n\t Your Input Is Invalid,  Try Again later\n";
        goto start;
    }

    cout<< "\t See Your Platypus: \n\n";
    platypus p('B', 'M', rand()%12+1, 6.0);
    p.print(cout);

    platypus p1;
    platypus p2;

	cout<<"\n\t if you want to increase platypus age click << I >> << O >>";  //  age_me function
    platypusAfterTimeOption:
    cin>>answer;
    if(tolower(answer) == 'i'){
        cout<< "\n\n\t age increase is in process... \n\n";
        p.age_me();
        p.print(cout);
    }
    else if(tolower(answer) == 'o'){
        cout<< "\n\n";
    }
    else{
        cout<< "\n\t Your Input Is Invalid,  Try Again later\n";
        goto platypusAfterTimeOption;
    }

	cout<<"\n\tDo you want give food platypus? << I >>  << O >>";        //  eat
    feedPlatypusOption:
    cin>>answer;
    if(tolower(answer) == 'i'){
    {
        cout<< "\n\tFeeding is In Process...\n\n";
        feedPlatypusAmount:
        p.eat();
        p.print(cout);
        if(p.getplatweight()>= 10)
                {
                  cout<< "\n";
                  cout<< "\n\t If your platypus is too fat you can create new one\n"<<endl;
                  goto newBornPlatypusOption;
                }
        cout<<"\tDo you want continue feeding? << I >>  << O >>";        //  continue feeding
        feedPlatypusMore:
        cin>>answer;
        if(tolower(answer) == 'i'){
                goto feedPlatypusAmount;}
        else if(tolower(answer) == 'o'){
            cout <<"\n\n";}
        else{
            cout<< "\n\t  Enter Valid Input...";
            goto feedPlatypusMore;}
    }
    }
    else if(tolower(answer) == 'o')
    {cout <<"\n";}
    else{
        cout<< "\n\t  Enter Valid Input...";
        goto feedPlatypusOption;
    }

	cout <<"\tiF You Want To See A Brawl Of Decade, or Century ? click << I >> << O >> \n\n\n";   //  fight
    cin>>answer;
        if(tolower(answer) == 'i'){
            cout<< "\tYou Can Create The Opponent platypus\n\n";
            char foeplatname;
            int foeplatage;
            char foeplatgen;
            float foeplatweight;
            chooseName:
            cout<< "\tEnter your opponent name: ";
            while(!(cin>>foeplatname))
            {
                cout<< "\t  Choose random letter from alphabet\n";
                cin.clear();
                cin.ignore(50,'\n');
                goto chooseName;
            }
            chooseAge:
            cout<< "\tChoose The opponents age: \n";
            while(!(cin>>foeplatage))
            {
                cout<< "\t   Enter A Number\n";
                cin.clear();
                cin.ignore(50,'\n');
                goto chooseAge;
            }
            chooseGender:
            cout<< "\tchoose your opponent platypus gender: \n";
            cin>>foeplatgen;
            if(!((foeplatgen == 'm') || (foeplatgen == 'M') || (foeplatgen == 'f') || (foeplatgen == 'F'))) //  gender input
            {
               cout<< "\t  if you want male platypus Choose < M > , or < F > if you want  Female Platypus\n";
               goto chooseGender;
            }
            chooseWeight:
            cout<< "\tyou can choose opponent platypus weight: \n";
            while(!(cin>>foeplatweight))
            {
                cout<< "\t   Enter A Number...\n";
                cin.clear();
                cin.ignore(50,'\n');
                goto chooseWeight;
            }
            cout<<"\n";
            p2.setplatname(foeplatname);
            p2.setplatage(foeplatage);
            p2.setplatgender(foeplatgen);
            p2.setplatweight(foeplatweight);
            p2.setplatalive(true);
            p2.setplatmutant(false);
            p2.print(cout);
            cout<< "Victory\n";
            p.fight(p2);
            p.print(cout);
            p2.print(cout);
        }
        if(tolower(answer) == 'i'){
            cout <<"\n";
            }

newBornPlatypusOption:
cout<< "\tDo you want to hatch new platypus? << I >>  << O >>\n\n\n";   //  hatch function
    cin>>answer;
        if(tolower(answer) == 'i'){
            p1.hatch();
            p1.print(cout);
        }
        else if(tolower(answer) == 'o'){
            cout <<"\n";
        }
        else{
            cout<< "\n\t Enter Valid Input...\n";
            goto newBornPlatypusOption;
        }

    cout<<"\t\t\t  << We will meet later! >>";
    cout<< "\n\n\t\t\t      << Good bye >> \n\n\n\n";



    return 0;
}

