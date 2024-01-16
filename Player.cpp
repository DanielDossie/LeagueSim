#include "Player.h"
//#include "Career.h"
#include <iostream>
#include <sstream>

using namespace std;

Player::Player() {
   firstName = "";
   lastName = "";
   jerseyNumber = -1;
   prevNumber = -1;
   prefNumber = -1;
   is_active = false;
   team_nickname = "";
   capacity = 1;
   num_teams = 0;
   career = new Career[1];
}

Player::Player(const std::string &first, const std::string &last,
		unsigned int jersey, const std::string &nickname) {
   firstName = first;
   lastName = last;
   jerseyNumber = jersey;
   //is_active = active;
   prevNumber = jersey;
   prefNumber = jersey;
   team_nickname = nickname;
   capacity = 1;
   num_teams = 0;
   career = new Career[1];
}
Player::~Player() {
   //cout << "Destructor Player" << endl;
   delete [] career;
}

Player& Player::operator=(const Player & source) {
   if (this == &source) {
      return *this;
   }
   //cout << "Player Operator= called" << endl;
   firstName = source.firstName;
   lastName = source.lastName;
   jerseyNumber = source.jerseyNumber;
   team_nickname = source.team_nickname;
   prevNumber = source.prevNumber;
   prefNumber = source.prefNumber;
   capacity = source.capacity;
   num_teams = source.num_teams;
   career = new Career[capacity];
   for (int i = 0; i < num_teams; i++) {
      career[i] = source.career[i];
   }
   return *this;
}

Player::Player(const Player &other) {
   //cout << "Player copy constructor called" << endl;
   firstName = other.firstName;
   lastName = other.lastName;
   jerseyNumber = other.jerseyNumber;
   team_nickname = other.team_nickname;
   prevNumber = other.prevNumber;
   prefNumber = other.prefNumber;
   capacity = other.capacity;
   num_teams = other.num_teams;
   career = new Career[capacity];
   //cout << "Cc check 2" << endl;
   for (int i = 0; i < num_teams; i++) {
      career[i] = other.career[i];
   }
   //cout << "cc check 3" << endl;
}

bool Player::read() {
   std::string line;
   std::cout << "       First Name: "; 
   std::getline(cin, firstName);
   std::cout << "        Last Name: "; 
   std::getline(cin, lastName);
   std::cout << "           Number: "; 
   std::getline(cin, line);

   std::stringstream is;	       
   is.str(line);
   is >> jerseyNumber;

   std::cout << "     Active (y/n): "; 
   std::getline(cin, line);
   is_active = false;
   if (!line.empty() && line[0] == 'y')
       is_active = true;
   std::cout << "             Team: "; 
   std::getline(cin, team_nickname);

   return true; 
}

void Player::show() const {
   std::cout << lastName << ", " << firstName << " (#" << jerseyNumber << ")"
	     << std::endl;
}

string Player::getLastName() const{
   return lastName;
}

string Player::getNickName() const {
   return team_nickname;
}

void Player::setJNum(int num) {
   prevNumber = jerseyNumber;
   jerseyNumber = num;
}

void Player::setTeamName(string nickname) {
   team_nickname = nickname;
}

bool Player::addCareer() { //add every new player to a new array that is dynamically allocated. Just add one more to capacity. Must free old one.
   if (capacity == 0) {
      //cout << "do we make this to start?" << endl;
      career = new Career[1];
      capacity++;
      //num_teams++;
   }
   else if (num_teams == capacity) {
      //cout << "Career check 7" << endl;
      Career *temp = new Career[capacity*2];
      //cout << "Career Check 8" << endl;
      capacity = capacity*2;
      //cout << "Career Check 9" << endl;
      //cout << num_teams << "WHATS IS THIS " << endl;
      for (int i = 0; i < num_teams; i++) {
         //cout << "Career Check 10" << endl;
         temp[i] = career[i];
         //cout << "Career Check 11" << endl;
      }
      delete [] career;
      career = temp;
      //cout << career[num_teams].getTeam() << "why wont what is before this print";
      //delete [] temp;
   }
   else {
   }
   
   //cout << "Career Check 12" << endl;
   //Player player1 = p;
   //Career ob = Career();
   career[num_teams];
   career[num_teams].setTeam(team_nickname);
   career[num_teams].setJNum(jerseyNumber);
   //cout << "Career Check 13 " << career[num_teams].getTeam() << " why wont what is before this print" << endl;
   //cout << "Num teams is" << num_teams << endl;
   num_teams++;
   //cout << "Num teams is changed to" << num_teams << endl;
   //cout << "Career Check 14" << endl;
   return true;
}
void Player::showCareer() {
   int iterator = num_teams+1;
   //cout << num_teams << " This should be Agents?" << endl;
   for (int i = 0; i < num_teams; i++) {
      //cout << num_teams;
      if (career[i].getTeam() == "Agents") {
         continue;
      }
      cout << career[i].getTeam() << " " << career[i].getJNum() << endl;
   }
}