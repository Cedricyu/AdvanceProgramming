#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h> 
#define INT_MAX 2147483647

using namespace std;




class Monster
{
private:
    /* data */
    int id_; // Unique identifier
    int type_; // 0=monster, 1=your hero, 2=opponent hero
    int x_; // Position of this entity
    int y_;
    int shield_life_; // Ignore for this league; Count down until shield spell fades
    int is_controlled_; // Ignore for this league; Equals 1 when this entity is under a control spell
    int health_; // Remaining health of this monster
    int vx; // Trajectory of this monster
    int vy;
    int near_base_; // 0=monster with no target yet, 1=monster targeting a base
    int threat_for_; // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
    int target_ =0;  

public:
    Monster(const int id,// Unique identifier
            const int type, // 0=monster, 1=your hero, 2=opponent hero
            const int x, // Position of this entity
            const int y,
            const int shield_life, // Ignore for this league; Count down until shield spell fades
            const int is_controlled, // Ignore for this league; Equals 1 when this entity is under a control spell
            const int health, // Remaining health of this monster
            const int vx, // Trajectory of this monster
            const int vy,
            const int near_base, // 0=monster with no target yet, 1=monster targeting a base
            const int threat_for){
        id_ = id;
        type_ = type;
        shield_life_ = shield_life;
        x_ =x;
        y_ =y;
        near_base_ = near_base;
        threat_for_ = threat_for;
    }
    ~Monster(){};
    int getid() const {return id_;}
    int getx() const{return x_ ;}
    int gety() const{return y_ ;}
    int gethealth() const{return health_ ;}
    int isTarget()const{return target_;}
    void Targedted(){target_ = 1;}
    int getType()const{return type_;}
    int getShield() const{return shield_life_;}
    bool iscontrolled() const{return is_controlled_;}
    int nearBase() const{return near_base_;}
    int getThreat() const{return threat_for_;}
    bool canControl(const int x,const int y)const{
        return sqrt(pow(x_ - x,2)+pow(y_ - y,2)) < 2200;
    }
    bool canWind(const int x,const int y)const{
        return sqrt(pow(x_ - x,2)+pow(y_ - y,2)) < 1280;
    }
    


};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
bool randomBool()
{
    return 0 + (rand() % 4 ) == 1;
}

class Player{
    private:
        int health_;
        int mana_;
    public:
    Player(int health,int mana){
        health_ = health;
        mana_ = mana;
    }
    int getMana()const{return mana_;}
};


int main()
{
    int base_x; // The corner of the map representing your base
    int base_y;
    cin >> base_x >> base_y; cin.ignore();
    int heroes_per_player; // Always 3
    cin >> heroes_per_player; cin.ignore();
    int turn =0;
    
    while (1) {
        turn++;
        Player *Players;
        Players = (Player *)malloc(sizeof(Player)*2);
        for (int i = 0; i < 2; i++) {
            int health; // Each player's base health
            int mana; // Ignore in the first league; Spend ten mana to cast a spell
            cin >> health >> mana; cin.ignore();
            Players[i] = Player(health,mana);
        }
        int entity_count; // Amount of heros and entitys you can see
        cin >> entity_count; cin.ignore();
        Monster *entitys;

        entitys = (Monster *)malloc(sizeof(Monster)*entity_count);
        for (int i = 0; i < entity_count; i++) {
            int id; // Unique identifier
            int type; // 0=monster, 1=your hero, 2=opponent hero
            int x; // Position of this entity
            int y;
            int shield_life; // Ignore for this league; Count down until shield spell fades
            int is_controlled; // Ignore for this league; Equals 1 when this entity is under a control spell
            int health; // Remaining health of this monster
            int vx; // Trajectory of this monster
            int vy;
            int near_base; // 0=monster with no target yet, 1=monster targeting a base
            int threat_for; // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
            cin >> id >> type >> x >> y >> shield_life >> is_controlled >> health >> vx >> vy >> near_base >> threat_for; cin.ignore();
            
            entitys[i] = Monster(
            id,
            type, 
            x,
            y,
            shield_life, 
            is_controlled, 
            health, 
            vx,
            vy,
            near_base,
            threat_for
            );
        }
        bool hero_go_far[heroes_per_player];

        for (int i = 0; i < heroes_per_player; i++) {

            // Write an action using cout. DON'T FORGET THE "<< endl"
            // To debug: cerr << "Debug messages..." << endl;
            int distance = INT_MAX;
            int entityNo = -1;
            int opponentNo = -1;
            int midSpidersNo = -1;
            int minhealth = INT_MAX;
            int controlno = -1;
            int enSpiderNo = -1;
            

            Monster hero = entitys[i];

            int hero_distance = (sqrt(pow( hero.getx()-base_x ,2 ) + pow(hero.gety()-base_y,2) ));
            bool far_enough = false;
            bool player_near_enmy_base = false;

            cerr << "hero distance " << hero_distance << endl;

           
            if( hero_distance > 17000 ){
                player_near_enmy_base = true;
                hero_go_far[i] = true;
            }
            else if( hero_distance > 5000 ){
                hero_go_far[i] = true;
            }
            else{
                hero_go_far[i] = false;
            }

            if( hero_distance > 12000 ){
               far_enough = true;
            }
            //cerr << base_x << " " << base_y << endl;
            for (int j = heroes_per_player ; j < entity_count; j++) {
                Monster enemy = entitys[j];
                //cerr << "enemy " << j << "pos " << enemy.getx() << " " << enemy.gety() << endl;
                unsigned long long int entity_dis = sqrt( pow(enemy.getx()-base_x,2) + pow(enemy.gety()-base_y,2) );
                //cerr << "distance = " << j << " " << entity_dis << endl;
               
                if( entity_dis <= distance && !enemy.isTarget() && enemy.getType()!=2 ){
                    distance = entity_dis ;
                    // if( !enemy.isTarget() && enemy.getType() == 0 ){
                    //     if(enemy.nearBase()==0 && enemy.getThreat()==2){
                    //         continue;
                    //     }
                    // enemy.gethealth();
                    entityNo = j;
                }
                //cerr << "type " << hero.getid() << "=" << hero.getType() << endl;
                cerr << enemy.getid()  << " is near base " << enemy.nearBase() << "and is threat for " << enemy.getThreat() << endl;

                if(enemy.getType()==2 && opponentNo==-1 && hero.canControl(enemy.getx(),enemy.gety())){
                    opponentNo = j;
                }
                if(enemy.getThreat()==0 && midSpidersNo ==-1 && hero.canControl(enemy.getx(),enemy.gety())){
                    midSpidersNo = j;
                }
                if(enemy.nearBase()==0 && enemy.getThreat()==2 && enSpiderNo==-1 && hero.canWind(enemy.getx(),enemy.gety())){
                    enSpiderNo = j;
                }
            }


            if(enSpiderNo!=-1)
                cerr << "find enmy spider\n";
            

            entitys[entityNo].Targedted();
            int towardx = (base_x==0)? 17630 : 0,towardy = (base_y==0)? 9000 : 0;

            // In the first league: MOVE <x> <y> | WAIT; In later leagues: | SPELL <spellParams>;
            if(Players[0].getMana() > 10 ){
                //cerr << distance << endl;
                if( distance < 5000 && hero.canWind(entitys[entityNo].getx(),entitys[entityNo].gety()) ){
                    cout << "SPELL " << "WIND " << 2*(hero.getx()-base_x)+base_x << " " << 2*(hero.gety()-base_y)+base_y << endl;
                    entitys[entityNo].Targedted();
                    continue;
                }
                if( !(midSpidersNo ==-1) && !entitys[midSpidersNo].isTarget() ){
                    
                    cout << "SPELL " << "CONTROL " << entitys[midSpidersNo].getid() << " " <<  towardx << " " << towardy << endl;
                    entitys[midSpidersNo].Targedted();
                    continue;
                }
                if( !(enSpiderNo ==-1) && far_enough ){
                    if( entitys[enSpiderNo].getShield()==0 ){
                        cout << "SPELL " << "SHIELD " << hero.getid() << endl;
                        continue;
                    }
                    cout << "SPELL " << "WIND " << towardx << " " << towardy << endl;
                    continue;
                }
                if( !(opponentNo==-1) && !entitys[opponentNo].isTarget() && turn > 90 ){
                    if(hero.getShield()==0){
                        cout << "SPELL " << "SHIELD " << hero.getid() << endl;
                        continue;
                    }
                    if( entitys[opponentNo].getShield()==0 ){
                        cout << "SPELL " << "CONTROL " << entitys[opponentNo].getid() << " " << 2*(entitys[opponentNo].getx()-base_x)+base_x  << " " << 2*(entitys[opponentNo].gety()-base_y)+base_y << endl;
                        entitys[opponentNo].Targedted();
                        continue;
                    }
                    // control oppenent's heros
                }
            }
            if(entityNo==-1){
                bool is_hero_too_far = false;
                for(int j=0 ; j < i ; j++)
                    if(hero_go_far[i])
                        is_hero_too_far = true;

                if( !is_hero_too_far )
                    cout << "MOVE " << 2*(hero.getx()-base_x)+base_x << " " << 2*(hero.gety()-base_y)+base_y << endl;
                else
                    cout << "WAIT" << endl;
                continue;
            }
            cout << "MOVE " << entitys[entityNo].getx() << " " << entitys[entityNo].gety() <<  endl;
        }
        //free(entitys);
    }
}