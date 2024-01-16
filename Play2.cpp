#include "Player.h"
#include "Team.h"
#include "League.h"
#include "Parser.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
string command;
string line;  
//int int_param;  
Team team;
Player player;
League league;
    while (1) {
      std::string teamName;
      cout << endl << "Enter a command: " << endl;
      cout << "Choose from [\"Team\" \"Player\" \"League\" \"Roster\" \"Quit\"]" << endl; 
      cout << ": "; 

      std::getline(std::cin, command);

      if (command == "Team") {
         if (team.read()) {
            if (!league.teamExists(team.getNickname()))
               league.addTeam(team);
            else 
	       cout << "Duplicate team nickname " << team.getNickname() << 
		        " not added" << std::endl;;
         }
	 else
            cout << "Team didn't read properly" << std::endl;
      }
      else if (command == "Player") {
         if (player.read())
            if (!league.addPlayer(player, player.getTeam()))
	       cout << "Could not add the player to team " << 
		       player.getTeam() << std::endl;;
      }
      else if (command == "League")
            league.showTeams();
      else if (command == "Roster") {
            cout << "Team: ";
	    std::getline(std::cin, teamName);
            league.showPlayers(teamName);
      }
      else if (command == "Quit") {
         break;
      }
      else {
         cout << "Command " << command << " not recognized. Please try again." << endl; 
      }
   }
}