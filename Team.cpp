#include "Team.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>

using namespace std;

Team::Team() {
   location = "";
   nickname = "";
   num_players = 0;
   capacity = 1;
   //Player* dataObject;
   player = new Player[1];
}

Team::Team(const std::string &loc, const std::string &name) {
   location = loc; 
   nickname = name; 
   num_players = 0;
   capacity = 1;
   //Player* dataObject;
   player = new Player[1];
}

Team::~Team() {
   //cout << "Destructor Team" << endl;
   delete [] player;
}
Team& Team::operator=(const Team & source) {
   if (this == &source) {
      return *this;
   }
   //cout << "do we get here?" << endl;
   location = source.location;
   nickname = source.nickname;
   capacity = source.capacity;
   num_players = source.num_players;
   player = new Player[capacity];
   for (int i = 0; i < num_players; i++) {
      player[i] = source.player[i];
      //cout << "here???????" << endl;
   }
   return *this;
}

Team::Team(const Team &other) {
   //cout << "are we here? Copy constructor";
   location = other.location;
   nickname = other.nickname;
   capacity = other.capacity;
   num_players = other.num_players;
   player = new Player[capacity];
   for (int i = 0; i < num_players; i++) {
      player[i] = other.player[i];
   }
   //return;
}

bool Team::addPlayer(const Player &p) { //add every new player to a new array that is dynamically allocated. Just add one more to capacity. Must free old one.
   //if (num_players == MAX_PLAYERS)
      //return false;
   //capacity++;
   if (capacity == 0) {
      player = new Player[1];
      capacity++;
   }
   else if (num_players == capacity) {
      //cout << "Check 7" << endl;
      Player *temp = new Player[capacity*2];
      //cout << "Check 8" << endl;
      capacity = capacity*2;
      //cout << "Check 9" << endl;
      for (int i = 0; i < num_players; i++) {
         //cout << "Check 10" << endl;
         temp[i] = player[i];
         //cout << "Check 11" << endl;
         //delete [] player;
         //player = temp;
      }
      delete [] player;
      player = temp;
      //delete [] temp;
   }
   else {
   }
   //for (int i = 0; i < capacity -1; i++) {
      //temp[i] = player[i];
   //capacity++;
   //cout << "Check 12" << endl;
   Player player1 = p;
   player1.setTeamName(nickname);
   player1.addCareer();
   player[num_players] = player1;
   //player[num_players].setTeamName(nickname);
   //cout << "Check 13" << endl;
   num_players++;
   //cout << "Check 14" << endl;
   //delete [] player;
   //player = temp;
   //delete[] temp;
   //player[num_players++] = p;
   return true;
}

Player Team::releasePlayer(string lastName) { //add every new player to a new array that is dynamically allocated. Just add one more to capacity. Must free old one.
   //if (num_players == MAX_PLAYERS)
      //return false;
   //capacity++;
   //Player *temp = new Player[capacity-1];
   //capacity = capacity-1;
   Player rval;
   for (int i = 0; i < num_players; i++) {
      if (player[i].getLastName() == lastName) {
         rval = player[i];
         Player replace = player[num_players-1];
         player[i] = replace;
         Player *temp = new Player[num_players-1];
         num_players--;
         capacity = num_players;
         for (int i = 0; i < num_players; i++) {
            temp[i] = player[i];   
         }
         delete [] player;
         player = temp;
      }
   }
   return rval;
   //if (p.getLastName() == nickname) {
      //Player *temp = new Player[capacity*2];
      //capacity = capacity*2;
      //for (int i = 0; i < num_players; i++) {
         //temp[i] = player[i];
         //delete [] player;
         //player = temp;
      //}
      //delete [] player;
      //player = temp;
      //delete [] temp;
   //}
   //else {
   //}
   //for (int i = 0; i < capacity -1; i++) {
      //temp[i] = player[i];
   //capacity++;
   //player[num_players] = p;
   //num_players--;
   //delete [] player;
   //player = temp;
   //delete[] temp;
   //player[num_players++] = p;
   //return true;
   //return;
}

void Team::showTeam() const {
   if (nickname == "Agents") {
      std::cout << location << " " << nickname << ": " << endl;
   }
   else {
      std::cout << location << " " << nickname << " (" << num_players << " players)" << endl;
   }	 
}

Player Team::returnPlayer(string lastName) { //add every new player to a new array that is dynamically allocated. Just add one more to capacity. Must free old one.
   Player rval;
   for (int i = 0; i < num_players; i++) {
      if (player[i].getLastName() == lastName) {
         rval = player[i];
      }
   }
   return rval;
}

bool Team::playerExists(const std::string &lastname) {
   for (int i = 0; i < num_players; i++) {
      if (player[i].getLastName() == lastname) {
         return true;
      }
   }
   return false;
}

//bool Team::signPlayer(Team FreeAgents, string lastname, string nickname) {
   //return true;
//}

void Team::showPlayers() const {
   if (nickname == "Agents") {
      for (unsigned int i = 0; i < num_players; i++) {
      player[i].show();
      }
   }
   else {
      std::cout << "Players:" << std::endl;
      for (unsigned int i = 0; i < num_players; i++) {
      player[i].show();
      }
   }
}

bool Team::read() {
   string line;

   std::cout << "     Location: "; 
   std::getline(std::cin, location);
   std::cout << "     Nickname: "; 
   std::getline(std::cin, nickname);
   return true; 
}

std::ostream &operator<<(std::ostream &out, const Team &tm) {
   tm.showTeam();
   return out;
}
//Team Team::getFreeAgent(string lastname, Team freeAgents) {
   //for (int i = 0; i < freeAgents.num_players; i++) {
      //if (freeAgents[i].lastname == lastname) {
         
      //}
   //}
//}
bool Team::prevCheck(Player &p) {
bool check = true;
   for (int z = 0; z < num_players; z++) {
      if (player[z].getJNum() == p.getprevJNum()) {
         jerseyCheck(p);
         check = false;
         break;
      }
      else{
         p.setJNum(p.getprevJNum());
      }
   }
   return check;
} 

bool Team::prefCheck(Player &p) {
   for (int z = 0; z < num_players; z++) {
      if (player[z].getJNum() == p.getJNum()) {
         if (prevCheck(p) == false) {
            jerseyCheck(p);
            break;
         }
      }
      else{
         p.setJNum(p.getprefJNum());
      }
   }
   return true;
}
bool Team::jerseyCheck(Player &p) {
   //bool check = false;
   //for (int z = 0; z < num_players; z++) {
      //if (player[z].getJNum() == p.getJNum()) {
         //check = false;
         int set = 1;
         for (int i = 1; i <= 99; i++) {
            bool check = false;
            for (int j = 0; j < num_players; j++) {
               if (i == player[j].getJNum()) {
                  //continue;
                  //cout << set << endl;
                  set=i+1;
                  check = true;
                  break;
                  //i++;
               }
               //p.setJNum(min);
            }
            if (check == true) {
               continue;
               //p.setJNum(set-2);
            }
            else{
               p.setJNum(set);
               return true;
            }
            //p.setJNum(set);
            //return true;
         }
      //}
   //}
}