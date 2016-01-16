/*Mitchell Rathbun and Ethan Vane*/
#ifndef Movie__H
#define Movie__H

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Movie{ 
   int index;
   string title;
   int year;
   set<string>* genres;
   vector<int>* ratings;
   double avgRating;
   double adjustedRating;
public:
/** Constructor for a zero parameter movie*/
   Movie() : index(0), title(""), genres(new set<string>()), ratings(new vector<int>()), avgRating(0), adjustedRating(0) {}

/**Sets the index of the movie object.*/
   void setIndex(int i);

/**Sets the title of the movie object.*/
   void setTitle(string movieTitle);

/**Sets the year of the movie object.*/
   void setYear(int i);

/**Adds to the set of genres of the movie object.*/
   void setGenres(int i);

/**Adds a star rating to the movie object's total set of ratings*/
   void addRatings(int i);

/**Uses a vector of star ratings to calculate the movie object's average rating. The average rating for the movie object is then set.*/
   void setRating(vector<int>* movieRatings);

/**Returns the movie object's set of genres that it belongs to.*/
   set<string>* getGenres() const;

/**Returns the movie object's vector of star ratings.*/
   vector<int>* getRatings() const;

/**Returns the average rating of the movie object.*/
   double getAverage();

/**Returns the index of the movie object.*/
   int getIndex() const;

/**Returns the title of the movie object*/
   string getTitle() const;

/**Prints out all of the genres that the movie object is a part of*/
   void printGenre(set<string> genreSet);

/**Sets adjusted rating for a movie*/
   void setAdjusted(double i);

/**Compares Movie objects. Used for sorting in the client*/
   bool operator<(const Movie& other);

/**Returns the adjusted rating*/
   double getAdjusted();
};

#endif

