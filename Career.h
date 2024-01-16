
#define _LEAGUE_H
#include <iostream>
#include <vector>
//#include "Player.h"

class Career {
    private:
        std::string team;
        int JNum;
        int capacity;
        int num_teams;
        //Career *career;
    
    public:
    Career();
    //Career(Player &p);
    //void showCareer(Player &p);
    bool setTeam(std::string nickname);
    bool setJNum(int num);
    std::string getTeam() const {return team;};
    int getJNum() const {return JNum;};
    bool setCapacity(int num);
    bool setNum_teams(int num);
    int getCapacity() const {return capacity;};
    int getNum_teams() const {return num_teams;};

};
