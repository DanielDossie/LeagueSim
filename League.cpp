#include "League.h"
using namespace std;

League::League() {
   num_teams = 0;
   capacity = 1;
   //Player* dataObject;
   team = new Team[1];
   //freeAgents = new Team[1];
}

League::League(const League &other) {
   //cout << "are we here? Copy constructor";
   num_teams = other.num_teams;
   //num_teams = other.num_teams;
   capacity = other.capacity;
   team = new Team[capacity];
   if (team != nullptr) {
      //cout << "NULL TEST" << endl;
      delete [] team;
   for (int i = 0; i < num_teams; i++) {
      team[i] = other.team[i];
      }
   }
   //return;
}

League::~League() {
   delete [] team;
}

//League& League::operator=(const League & source) {
   //if (this == &source) {
      //return *this;
   //}
   //cout << "do we get here?" << endl;
   //num_teams = source.num_teams;
   // = source.nickname;
   //capacity = source.capacity;
   //num_players = source.num_players;
   //team = new Team[capacity];
   //for (int i = 0; i < num_teams; i++) {
      //team[i] = source.team[i];
  // }
   ////return *this;
//}

bool League::addTeam(const Team &new_team) {
   if (new_team.getNickname().empty())
      return false;
   if (teamExists(new_team.getNickname()))
      return false;
   if (num_teams == capacity) {
      Team *temp = new Team[capacity*2];
      capacity = capacity*2;
      for (int i = 0; i < num_teams; i++) {
         temp[i] = team[i];
         //delete [] player;
         //player = temp;
      }
      delete [] team;
      team = temp;
   }
   else {
   }
   team[num_teams] = new_team;
   num_teams++; //(new_team);
   return true;
} 

bool League::teamExists(const std::string &nickname) const {
   for (unsigned i = 0; i < num_teams; i++) //team.size() replaced
      if (team[i].getNickname() == nickname)
         return true;
   return false;
}

bool League::playerExists(const std::string &lastname, const std::string &nickname) {
   for (unsigned i = 0; i < num_teams; i++) //team.size() replaced
      if (team[i].getNickname() == nickname) {
         if (team[i].playerExists(lastname)) {
            return true;
         }
      }
   return false;
}

bool League::addPlayer(const Player &new_player, const std::string &nickname) {
   for (unsigned i = 0; i < num_teams; i++) {
      //cout << "check4" << endl;
      if (team[i].getNickname() == nickname) {
         //cout << "check 5" << endl;
         team[i].addPlayer(new_player);
         //cout << "check 6" << endl;
         return true;
      }
   }
   return false;
} 

void League::showTeams() const {
   cout << "Teams:" << num_teams -1<< std::endl;
   for (unsigned i = 1; i < num_teams; i++) 
      team[i].showTeam();
   return;
}

bool League::showPlayers(const std::string &nickname) const {
   for (unsigned i = 0; i < num_teams; i++) 
      if (team[i].getNickname() == nickname) {
         team[i].showTeam();
         team[i].showPlayers();
         return true;
      }
   return false;
}
Team League::getFreeAgent() {
   return team[0];
}
Team League::getTeamObject(std::string nickname) {
   for (int i = 0; i < num_teams; i++) {
      if (team[i].getNickname() == nickname) {
         return team[i];
      }
   }
}
Player League::releasePlayer(std::string lastname,std::string nickname) {
   for (int i = 0; i < num_teams; i++) {
      if (team[i].getNickname() == nickname) {
         Player free = team[i].releasePlayer(lastname);
         return free;
      }   
   }
}

Player League::returnPlayer(std::string lastname) {
   for (int i = 0; i < num_teams; i++) {
      if (team[i].playerExists(lastname)) {
         Player free = team[i].returnPlayer(lastname);
         return free;
      }   
   }
}

bool League::jerseyCheck(string nickname, Player &p) {
   for (int i = 0; i < num_teams; i++) {
      if (nickname == team[i].getNickname()) {
         team[i].prefCheck(p);
         return true;
      }
   }
}

void League::showCareer(Player &p) {

}

//Player addFreePlayer(std::string lastName, std::string nickname) {

//}
