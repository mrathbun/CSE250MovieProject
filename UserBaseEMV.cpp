#include "UserBaseEMV.h"

UserBase::UserBase()
 : users(new vector<User>(1000))
{ }

void UserBase::add(int id, int rating, set<string>* genres) {
  if(users->at(id).getID()==-1) {
    users->at(id).setID(id);
    users->at(id).update(rating, genres);
  }
  else {
    users->at(id).update(rating, genres);
  }
}

/**REQ: Takes argument of a vector containing all of the already computed genre averages*/
void UserBase::createPreferenceRatings(vector<double>* aves) {
  for(int i=1; i<1000; i++) {
    if(users->at(i).getID()!=-1) {
      users->at(i).calculatePreference(aves);
    }
  }
}

User UserBase::at(int i) {
  return users->at(i);
}

int UserBase::size(){
  return users->size();
}

