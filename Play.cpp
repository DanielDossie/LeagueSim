//#include "Player.h"
//#include "Team.h"
#include "League.h"
#include "Parser.h"
#include <iostream>
#include <string>
using namespace std;

string command;
string line;  
int int_param;  
//Team team;
//Player player;
Team freeAgents;
League league;

void do_Player(string firstname, string lastname, int number, string teamName) {
   Player player(firstname, lastname, number, teamName);
   //player.addCareer();
   //cout << "new player added" << endl;
   league.jerseyCheck(teamName, player);
   if (!league.addPlayer(player, player.getTeam())) {
	       cout << "Team " << player.getTeam() << " does not exist" << std::endl;
          cout << "Adding player " << player.getFirst() << " to free agents." << endl;
   }
}
void do_league() {
   //cout << "here" << endl;
   league.showTeams();
}
void do_Team(string location, string nickname) {
   Team team(location, nickname);
   if (!league.teamExists(team.getNickname())) {
         league.addTeam(team);
   }
   else {
	   cout << "Duplicate team nickname " << team.getNickname() << " not added" << std::endl;;
      }
}
void do_Roster(string nickname) {
   //cout << "Team: ";
	//std::getline(std::cin, nickname);
   league.showPlayers(nickname);
}

void do_FreeAgent(string firstname, string lastname, int number, string teamName) { //use teamname for career part. Wont be used now
   Player player(firstname, lastname, number, "Agents");
   ///cout << "hi new free agent" << endl;
   if (!league.addPlayer(player, "Agents")) {
	       cout << "Could not add the player to team " << player.getTeam() << std::endl;
   }
}
void show_FreeAgents() {
   league.showPlayers("Agents");
}
void do_release(string lastName, string nickname) {
   if (league.teamExists(nickname)) {
      if (league.playerExists(lastName, nickname)) {
         Player freeAgent = league.releasePlayer(lastName, nickname);
         league.addPlayer(freeAgent, "Agents");
      }
      else {
         cout << "Player " << lastName << " is not currently on team" << nickname << endl;
      }
   }
}

void do_career(string lastname) {
   Player careerPlayer = league.returnPlayer(lastname);
   if (league.playerExists(careerPlayer.getLastName(), careerPlayer.getNickName())) {
      careerPlayer.showCareer();
   }
   else {
      cout << "Could not find player with last name of " << careerPlayer.getLastName() << endl;
   }
}

void do_sign(string lastname, string nickname) {
   //cout << "check 1" << endl;
   if (league.playerExists(lastname, "Agents")) {
      Player teamPlayer = league.releasePlayer(lastname, "Agents");
      //cout << "check 2" << endl;
      league.jerseyCheck(nickname, teamPlayer);
      league.addPlayer(teamPlayer, nickname);
      //teamPlayer.addCareer();
      //cout << "check 3" << endl;
   }
   else {
      cout << "Error! cannot Sign player team doesnt exist." << endl;
   }
}

int main() {
   do_Team("Free", "Agents");
   while (1) {
      cout << endl << "Enter a command: " << endl;
      cout << "Choose from " << std::endl;
	   cout << "   Team <location> <team-nickname>" << std::endl;
      cout << "   Player <firstname> <lastname> <number> [<team-nickname>]" << std::endl;
      cout << "   League" << std::endl;
      cout << "   Roster [<team-nickname>]" << std::endl;
      cout << "   Release <lastname> <team-nickname>" << std::endl;
      cout << "   Sign <lastname> <team-nickname>" << std::endl;
      cout << "   Career <lastname>" << std::endl;
      cout << "   Trade" << std::endl;
      cout << "   Quit" << std::endl;
      cout << ": ";

      getline(cin, line);
      Parser command(line);
      if (command.getOperation().empty()) {
         if (std::cin.fail())
	    break;
         continue;
      }

      if (command.getOperation() == "Quit") {
         if (command.numArgs() > 0) 
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
         break;
      }
      else if (command.getOperation() == "Player") {
         if (command.numArgs() == 3) {
            int_param = stoi(command.getArg3());
            do_FreeAgent(command.getArg1(), command.getArg2(), int_param, command.getArg4());
         }
         else if (command.numArgs() < 3) {
            cout << "Can't operate with missing arguments";
         }
         else if (command.numArgs() > 4) {
            int_param = stoi(command.getArg3());
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
            do_Player(command.getArg1(), command.getArg2(), int_param, command.getArg4());
         }
         else if (command.numArgs() == 4) {
            int_param = stoi(command.getArg3());
            do_Player(command.getArg1(), command.getArg2(), int_param, command.getArg4());
         }
         else if (command.numArgs() < 3) {
            cout << "Can't operate with missing arguments";
         }
      }
      else if (command.getOperation() == "Team") {
         if (command.numArgs() == 2) {
            do_Team(command.getArg1(), command.getArg2());
         }
         else if (command.numArgs() > 2) {
            do_Team(command.getArg1(), command.getArg2());
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
         }
         else if (command.numArgs() < 2) {
            cout << "Can't operate with missing arguments";
         }
         //do_FreeAgent(command.getArg1(), command.getArg2(), int_param, command.getArg4());
      }
      else if (command.getOperation() == "Roster") {
         if (command.numArgs() == 1) {
            do_Roster(command.getArg1());
         }
         else if (command.numArgs() == 0) {
            show_FreeAgents();
         }
         else if (command.numArgs() > 1) {
            cout << std::endl << MISSING_ARGS << endl;
            do_Roster(command.getArg1());
         }
      }
      else if (command.getOperation() == "League") {
         if (command.numArgs() == 0) {
            do_league();
         }
         else if (command.numArgs() > 0) {
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
            do_league();
         }
      }
      else if (command.getOperation() == "Release") {
         if (command.numArgs() == 2) {
            do_release(command.getArg1(), command.getArg2());
         }
         else if (command.numArgs() > 2) {
            do_release(command.getArg1(), command.getArg2());
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
         }
         else if (command.numArgs() < 2) {
            cout << "Can't operate with missing arguments";
         }
      }
      else if (command.getOperation() == "Sign") {
         if (command.numArgs() == 2) {
            do_sign(command.getArg1(), command.getArg2());
         }
         else if (command.numArgs() < 2) {
             cout << "Can't operate with missing arguments";
         }
         else if (command.numArgs() > 2) {
            do_sign(command.getArg1(), command.getArg2());
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
         }
      }
      else if (command.getOperation() == "Career") {
         if (command.numArgs() == 1) {
            do_career(command.getArg1());
         }
         else if (command.numArgs() > 1) {
            cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
            do_career(command.getArg1());
         }
         else if (command.numArgs() < 1) {
            cout << std::endl << MISSING_ARGS << endl;
         }
      }
   }
}

   
   //while (1) {
      //std::string teamName;
      //cout << endl << "Enter a command: " << endl;
      //cout << "Choose from [\"Team\" \"Player\" \"League\" \"Roster\" \"Quit\"]" << endl; 
      //cout << ": "; 

      //std::getline(std::cin, command);

      //if (command == "Team") {
         //if (team.read()) {
            //if (!league.teamExists(team.getNickname()))
               //league.addTeam(team);
            //else 
	       //cout << "Duplicate team nickname " << team.getNickname() << 
		       //" not added" << std::endl;;
         //}
	 //else
            //cout << "Team didn't read properly" << std::endl;
      //}
      //else if (command == "Player") {
         //if (player.read())
            //if (!league.addPlayer(player, player.getTeam()))
	       //cout << "Could not add the player to team " << 
		       //player.getTeam() << std::endl;;
      //}
      //else if (command == "League")
            //league.showTeams();
      //else if (command == "Roster") {
            //cout << "Team: ";
	    //std::getline(std::cin, teamName);
            //league.showPlayers(teamName);
      //}
      //else if (command == "Quit") {
         //break;
      //}
      //else {
         //cout << "Command " << command << " not recognized. Please try again." << endl; 
      //}
   //}
