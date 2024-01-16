#ifndef _PLAYER_H
#define _PLAYER_H

#include "Career.h"
#include <iostream>

class Player {
   private:
      std::string firstName;
      std::string lastName;
      unsigned int jerseyNumber;
      std::string team_nickname;
      unsigned int prevNumber;
      unsigned int prefNumber;
      bool is_active;
      int capacity;
      int num_teams;
      Career *career;

   public:
      Player();
      ~Player();
      Player(const std::string &first, const std::string &last,
             unsigned int jersey, const std::string &nickname);
      std::string getTeam() {return team_nickname;};
      int getJNum() const {return jerseyNumber;};
      std::string getFirst() const {return firstName;};
      int getprefJNum() {return prefNumber;};
      int getprevJNum() {return prevNumber;};
      Player& operator=(const Player & source);
      Player(const Player & other);
      bool read();
      bool addCareer();
      void showCareer();
      void show() const;
      void setJNum(int num);
      void setprevJNum(int num);
      void setTeamName(std::string nickname);
      std::string getLastName() const;
      std::string getNickName() const;
};

#endif // _PLAYER_H
