/*Mitchell Rathbun and Ethan Vane*/
#include<iostream>
#include<vector>
#include<string>

#include "MovieMGR.h"

void Movie::setIndex(int i){
   index=i;
}

void Movie::setTitle(string movieTitle){
   title=movieTitle;
}

void Movie::setYear(int i){
   this->year=i;
}

void Movie::setGenres(int i){
   if(i==1||i==2||i==16||i==18){
      genres->insert("action");
   }
   if(i==6||i==10||i==11||i==13){
      genres->insert("noir");
   }   
   if(i==3||i==4||i==5||i==12){
      genres->insert("light");
   }
   if(i==8||i==14){
      genres->insert("serious");
   }
   if(i==9||i==15){
      genres->insert("fantasy");
   }
   if(i==7||i==17){
      genres->insert("history");
   }
}

void Movie::addRatings(int i){
   ratings->push_back(i);
}

void Movie::setRating(vector<int>* movieRatings){
   double totalRating=0;
   for(int i=0; i<movieRatings->size(); i++){
      totalRating+=movieRatings->at(i);
   }
   avgRating = (totalRating)/(movieRatings->size()); 
}

set<string>* Movie::getGenres() const{
   return genres;
}

vector<int>* Movie::getRatings() const{
   return ratings;
}

double Movie::getAverage(){
   return avgRating;

}

int Movie::getIndex() const{
   return index;
}

string Movie::getTitle() const{
   return title;
}

void Movie::printGenre(set<string> genreSet){
   for(set<string>::iterator it=genreSet.begin(); it!=genreSet.end(); ++it){
      cout << *it << " ";
   }
}

void Movie::setAdjusted(double i){
   adjustedRating=avgRating*i;
}

bool Movie::operator<(const Movie& other){
   return adjustedRating < other.adjustedRating;
}

double Movie::getAdjusted(){
   return adjustedRating;
}




