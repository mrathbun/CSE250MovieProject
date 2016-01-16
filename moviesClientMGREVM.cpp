/*Mitchell Rathbun and Ethan Vane*/
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

#include "MovieMGR.h"
#include "MovieMGR.cpp"
#include "MovieBaseMGR.h"
#include "MovieBaseMGR.cpp"
#include "UserEMV.h"
#include "UserEMV.cpp"
#include "UserBaseEMV.h"
#include "UserBaseEMV.cpp"


void singleUserTopMovies(int i, MovieBase* mBase, UserBase* uBase){
   if(uBase->at(i).getID()!=-1){
      for(int j=1; j<mBase->size(); j++){
         mBase->setAdjustedAgain(j, uBase->at(i).getPreference(mBase->at(j).getGenres()));
      }
      vector<Movie>* heap=mBase->getBase();
      make_heap(heap->begin(), heap->end());
      sort_heap(heap->begin(), heap->end());
      uBase->at(i).createTopMovies(heap, 10);
   }
   else{ cout << "Not a valid User" << endl; }
}

void allUserTopMovies(MovieBase* mBase, UserBase* uBase){
   for(int i=1; i<uBase->size(); i++){
      if(uBase->at(i).getID()!=-1){ 
         for(int j=1; j<mBase->size(); j++){
           mBase->setAdjustedAgain(j, uBase->at(i).getPreference(mBase->at(j).getGenres()));
         }
         vector<Movie>* heap=mBase->getBase();
         make_heap(heap->begin(), heap->end());
         sort_heap(heap->begin(), heap->end());
         uBase->at(i).createTopMovies(heap, 10);
      }
   }
}

int main(){
   MovieBase* movieBase=new MovieBase();
   string movieFile="u.item";
   movieBase->makeBase("u.item");
//Read in u.data
   ifstream file;
   int userID;
   int movieID;
   int rating;
   int timeStamp;
   UserBase* userBase=new UserBase();
   file.open("u.data");
   while(file >> userID) {
      file >> movieID >> rating >> timeStamp;
      userBase->add(userID, rating, movieBase->at(movieID).getGenres());
      movieBase->at(movieID).addRatings(rating);
   }
  
   movieBase->createRatings(movieBase->getBase());

   userBase->createPreferenceRatings(movieBase->averageGroup(movieBase->getBase()));


   allUserTopMovies(movieBase, userBase);
//   singleUserTopMovies(14, movieBase, userBase);   
 
}

/* Report Section

a) 

1. In the MovieBase class, it was decided to make the container of movies a
vector of movies. A map could have been used, since it allows access by key, 
which makes sense when considering a movie. However, since the movies are read 
in order of index from the file u.item, we figured it made sense to implement
the base as a vector, which allows for indexed access to correspond with the 
index of the movie. All that was required for this to work is a "dummy" movie 
in vector position 0.

2. In order to create the preference ratings, both an average overall and
and average user rating is needed for every genre. We decided to implement
this all in one step. This allowed for cleaner code in the file, and less 
methods to define/keep track of in the UserBase. Of course, the alternative 
would have been to define 3 different methods and call them sequentially in the
client file. If this was done, the code need for the preference ratings would 
required greater work from the MovieBase. Not doing this allowed us to keep our
code more object oriented. 

3. As mentioned in 2, we decided to create all of the preferences within one 
method. In order to do this, the method createPreferences needed a vector of 
floats to be passed into it. Due to this, averageGroup was created to bring 
all of the separate ratings into one vector. This work could have been left to 
the client, but we ultimately decided that it would be easier and cleaner to 
implement in the movieBase class.    

4. In the UserBase class when a new user is instantiated its user ID field is 
initially set to -1.  This is to be able to identify when adding new users which spots still have dummy nodes at them.  If the user still has an id of -1 then
their id must be updated.  This is used in the add function in the userBase
class always checks this when adding a new user while going through the data to
make sure that each user has a the proper id associated with it.  -1 is also an easy way to identify whether there is a dummy user somewhere in other methods as well. 

b) For our simulation, we first create the movies from the file u.item. To do 
this we read through all of the characters in all movies M. This comes to be 
theta(cm), which reduces to theta(m). Then we create the user base and add 
ratings to the movies from u.data. This takes theta(3R) time since 3 constant 
time methods are carried out for each rating. This reduces to theta(R) time. 
The createRatings method loops through the movie base and sets each average 
rating. Thus it runs in theta(M) time. createPreference ratings must scroll 
through the user and movie bases to complete, but these are done sequentially. 
Therefore, it runs in theta(M)+theta(U). If singleUserTopMovies is used, the sort heap takes the longest run time, and thus it is O(MlogM). If allUserTopMovies
is used, then it is O(UMlogM). Therefore, the total runtime is theta(M)+theta(R)
+theta(M)+(theta(M)+theta(U))+either O(MlogM) or O(UMlogM). If a single user is printed out, this reduces to theta(R). If all users are printed out, this 
reduces to O(UMlogM).

Extra Comments:
If a movie has more than one genre, we decided to take the average of all of its preference ratings for those genre and average them for its final preference rating used in the average x preference formula.`

*/



