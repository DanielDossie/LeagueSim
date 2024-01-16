#ifndef _TEAM_H
#define _TEAM_H

#include "Player.h"
#include <iostream>

const unsigned int MAX_PLAYERS = 12;

class Team {
   private:
      std::string location;
      std::string nickname;
      int capacity;
      //Player* dataObject;
      unsigned int num_players; 
      Player *player;


   public:
      Team();
      ~Team();
      Team(const std::string &loc, const std::string &name);
      std::string getNickname() const {return nickname;};
      Team& operator=(const Team & source);
      Team(const Team& other);
      bool addPlayer(const Player &p);
      Player releasePlayer(std::string lastName);
      Player returnPlayer(std::string lastName);
      bool playerExists(const std::string &lastname);
      //Team Team::getFreeAgent(string lastname,  Team freeAgent);
      //bool signPlayer(Team FreeAgents, string lastname, string nickname);
      void showTeam() const;
      void showPlayers() const;
      bool read();
      bool prefCheck(Player &p);
      bool prevCheck(Player &p);
      bool jerseyCheck(Player &p);
      friend std::ostream &operator<<(std::ostream &out, const Team &tm);
};

#endif // _TEAM_H
