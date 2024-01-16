//#ifndef _LEAGUE_H
#define _LEAGUE_H
#include <iostream>
#include <vector>
#include "Team.h"

class League {
   private:
       //std::vector<Team> team;
       Team *team;
       int capacity = 0;
       int num_teams = 1;

   public:
       League();
       ~League();
       League(const League &other);
       //League& operator=(const Team & source);
       Team getFreeAgent();
       bool addTeam(const Team &new_team);
       bool teamExists(const std::string &nickname) const;
       bool addPlayer(const Player &new_player, const std::string &teamMascot);
       void showTeams() const;
       bool playerExists(const std::string &lastname, const std::string &nickname);
       bool showPlayers(const std::string &nickname) const;
       Team getTeamObject(std::string nickname);
       Player releasePlayer(std::string lastName, std::string nickname);
       bool jerseyCheck(std::string nickname, Player &p);
       Player returnPlayer(std::string lastName);
       void showCareer(Player &p);
       //Player addFreePlayer(std::string lastName, std::string nickname);
};

//#endif // _LEAGUE_H
