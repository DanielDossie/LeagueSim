#include "Career.h"
//#include "Player.h"
using namespace std;

Career::Career() {
    team = "";
    JNum = -1;
    int capacity = 1;
    int num_teams = 0;
    //career = new Career[1];
}

//Career::Career(Player &p) {
    //team = p.getTeam();
    //JNum = p.getJNum();
    //career = new Career[1];
//}

//void Career::showCareer(Player &p) {
    //for (int i = 0; i < num_teams; i++) {
        //cout << career[i].team << endl;
        //cout << career[i].JNum << endl;
    //}
//}

bool Career::setTeam(std::string nickname) {
    team = nickname;
}

bool Career::setJNum(int num) {
    JNum = num;
}
bool Career::setNum_teams(int num) {
    num_teams = num;
}

bool Career::setCapacity(int num) {
    capacity = num;
}
