/*Ethan Vane and Mitchell Rathbun*/
#ifndef USEREMV_H_
#define USEREMV_H_

#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;
using std::cout;
using std::endl;

class User {
  /*keeps running sum of ratings for each genre as ratings are added*/
  int sumAction;
  int sumNoir;
  int sumLight;
  int sumSerious;
  int sumFantasy;
  int sumHistory;

  /*keeps running sum of number of ratings for each genre as ratings are added*/
  int numAction;
  int numNoir;
  int numLight;
  int numSerious;
  int numFantasy;
  int numHistory;

  /*Preference ratings for each genre so they can be accessed to be used in later calculations*/
  double actionP;
  double noirP;
  double lightP;
  double seriousP;
  double fantasyP;
  double historyP;

  /*id of User*/
  int id;
  /*vector that represents the top 50 movie recommendations for each user*/
  //vector<string>* top50;
 public:

  /*default constructor for User that instantiates all of its fields*/
   User();

   /*sets id to i*/
   void setID(int i);

   /*gets id*/
   int getID() const;

   /*gets Preference number for whatever genre is sent in ( getPreference("action") gets the action preference)*/
   double getPreference(set<string>* genres) const;

   /*update is called whenever a new user review is read in and updates the sumAction etc and numAction etc fields\
*/
   void update(int rating, set<string>* genres);

   /*calculates average for whatever genre is desired by dividing for example for "action" sumAction/numAction*/
   double average(string genre);

   /*calculates Preferences for all genres for the user and needs to be sent in a set of all the average ratings f\
or each genre*/
   void calculatePreference(vector<double>* averages);

   /**Prints out top k movies for a specific user*/
   void createTopMovies(vector<Movie>* sortedHeap, int k);
   
};

#endif
