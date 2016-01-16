/*Ethan Vane and Mitchell Rathbun*/
#ifndef USERBASEEMV_H_
#define USERBASEEMV_H_

#include "UserEMV.h"

#include <vector>
#include <set>

using std::vector;
using std::set;

class UserBase {
  /*vector of User which represents the User Base*/
   vector<User>* users;

 public:
   /*default constructor instantiates a vector of User to hold all the users (users->at(196) will be the user with\
 user ID 196)*/
   UserBase();

   /*adds new User to the users vector which represents the userbase and it calls an update function to update the\
ir ratings for a set of genres which is aquired from the Movie objects)*/
   void add(int id, int rating, set<string>* genres);

   /*returns the user at index i*/
   User at(int i);

   /*Goes through the users vector and calculates each users preference rating for each genre (only called after a\
ll of the data file has been read in*/
   void createPreferenceRatings(vector<double>* aves);
   
   /*Returns the size of the UserBase class*/
   int size();
};

#endif
