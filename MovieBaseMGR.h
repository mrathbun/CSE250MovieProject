/*Mitchell Rathbun and Ethan Vane*/
#ifndef MovieBase__H
#define MovieBase__H

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<fstream>

#include "MovieMGR.h"

using namespace std;

class MovieBase{
   vector<Movie>* base;

   public:

/**Constructor for a zero parameter movie base object*/
   MovieBase() : base(new vector<Movie>()) {}

/**Reads in a file and adds movies to the existing MovieBase class. Assigns an index, title, and a set of genres to each movie.*/
   void makeBase(string fileName);

/**Returns the movie at index i in the existing MovieBase class*/
   Movie at(int i);
             
/**Returns the amount of movies in the existing MovieBase class*/
   int size();

/**Sets the average rating for each movie in a vector of movies. Can be used on a movie base*/
   void createRatings(vector<Movie>* mBase);
  
/**Returns the vector of movies in the existing MovieBase class*/
   vector<Movie>* getBase() const;

/**Sets the average rating of each of a movie in the MovieBase class*/
   void setAverage(int i);

/**Determines and returns the average of all action movies within the existing MovieBase class*/
   double actionAverage(vector<Movie>* mBase);

/**Determines and returns the average of all noir movies within the existing MovieBase class*/
   double noirAverage(vector<Movie>* mBase);

/**Determines and returns the average of all light movies within the existing MovieBase class*/
   double lightAverage(vector<Movie>* mBase);

/**Determines and returns the average of all serious movies within the existing MovieBase class*/
   double seriousAverage(vector<Movie>* mBase);

/**Determines and returns the average of all fantasy movies within the existing MovieBase class*/
   double fantasyAverage(vector<Movie>* mBase);

/**Determines and returns the average of all history movies within the existing MovieBase class*/
   double historyAverage(vector<Movie>* mBase);

/**Creates a vector of doubles consisting of the overall average star rating for each genre. Passed on to user to create preference rating.*/ 
   vector<double>* averageGroup(vector<Movie>* mBase);

/**Set adjusted rating for a movie*/
   void setAdjustedAgain(int i, double j);
};

#endif
