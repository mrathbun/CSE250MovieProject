#include "UserEMV.h"

User::User()
  : id(-1),
    sumAction(0),
    sumNoir(0),
    sumLight(0),
    sumSerious(0),
    sumFantasy(0),
    sumHistory(0),
    numAction(0),
    numNoir(0),
    numLight(0),
    numSerious(0),
    numFantasy(0),
    numHistory(0),
    actionP(0),
    noirP(0),
    lightP(0),
    seriousP(0),
    fantasyP(0),
    historyP(0)
{ }



void User::setID(int i) { id=i; }

int User::getID() const { return id; }

double User::getPreference (set<string>* genres) const {
  set<string>::iterator it= genres->begin();
  double sum=0;
  while(it!=genres->end()) {
    if(*it=="action") { sum+= actionP; }
    if(*it=="noir") { sum+= noirP; }
    if(*it=="light") { sum+= lightP; }
    if(*it=="serious") { sum+= seriousP; }
    if(*it=="fantasy") { sum+= fantasyP; }
    if(*it=="history") { sum+= historyP; }
    ++it;
  }
  return sum/(genres->size());
}

void User::update(int rating, set<string>* genres) {
  set<string>::iterator it= genres->begin();
  while(it!=genres->end()) {
    if(*it=="action") {
      sumAction+=rating;
      numAction++;
    }
    if(*it=="noir") {
      sumNoir+=rating;
      numNoir++;
    }
    if(*it=="light") {
      sumLight+=rating;
      numLight++;
    }
    if(*it=="serious") {
      sumSerious+=rating;
      numSerious++;
    }
    if(*it=="fantasy") {
      sumFantasy+=rating;
      numFantasy++;
    }
    if(*it=="history") {
      sumHistory+=rating;
      numHistory++;
    }
    it++;
  }
}

double User::average(string genre) {
  if(genre=="action") {
    if(numAction==0) { return (double)(-1); }
    else { return sumAction/(double)numAction; }
  }
  if(genre=="noir") {
    if(numNoir==0) { return (double)(-1); }
    else { return sumNoir/(double)numNoir; }
  }
  if(genre=="light") {
    if(numLight==0) { return (double)(-1); }
    else { return sumLight/(double)numLight; }
  }
  if(genre=="serious") {
    if(numSerious==0) { return (double)(-1); }
    else { return sumSerious/(double)numSerious; }
  }
  if(genre=="fantasy") {
    if(numFantasy==0) { return (double)(-1); }
    else { return sumFantasy/(double)numFantasy; }
  }
  if(genre=="history") {
    if(numHistory==0) { return (double)(-1); }
    else { return sumHistory/(double)numHistory; }
  }
}

/**Req: Takes previously calculated vector of movie genre averages*/
void User::calculatePreference(vector<double>* averages) {
  vector<double>::iterator it= averages->begin();
  double temp;
  if(numAction==0) { temp= (double)(-1); }
  else { temp= sumAction/(double)numAction; }
  if(temp==-1) { actionP=1; }
  else { actionP= temp/(*it); }
  it++;
  if(numNoir==0) { temp= (double)(-1); }
  else { temp= sumNoir/(double)numNoir; }
  if(temp==-1) { noirP=1; }
  else { noirP= temp/(*it); }
  it++;
  if(numLight==0) { temp= (double)(-1); }
  else { temp= sumLight/(double)numLight; }
  if(temp==-1) { lightP=1; }
  else { lightP= temp/(*it); }
  it++;
  if(numSerious==0) { temp= (double)(-1); }
  else { temp= sumSerious/(double)numSerious; }
  if(temp==-1) { seriousP=1; }
  else { seriousP= temp/(*it); }
  it++;
  if(numFantasy==0) { temp= (double)(-1); }
  else { temp= sumFantasy/(double)numFantasy; }
  if(temp==-1) { fantasyP=1; }
  else { fantasyP= temp/(*it); }
  it++;
  if(numHistory==0) { temp= (double)(-1); }
  else { temp= sumHistory/(double)numHistory; }
  if(temp==-1) { historyP=1; }
  else { historyP= temp/(*it); }
}

/**REQ: Must take an already sorted vector in order of increasing size as an argument.*/
void User::createTopMovies(vector<Movie>* sortedHeap, int k){
   cerr << endl << "User: " << id << endl;
   for(int i=sortedHeap->size()-1; i>sortedHeap->size()-(k+1); i--){
    //  topMovies->push_back(sortedHeap->at(i).getTitle());
      cerr << sortedHeap->at(i).getTitle() << endl;
   }
}


