/*Mitchell Rathbun and Ethan Vane*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<set>

#include "MovieBaseMGR.h"

void MovieBase::makeBase(string movieFile){
   string entry;
   string inFileName=movieFile;
   ifstream* InFile=new ifstream(inFileName.c_str(), ios_base::in);
   Movie dummy;
   base->push_back(dummy);
   int spotNumber=1;
   while(getline(*InFile, entry)){
      int count=0;
      int genreCount=0;
      string valueString="";
      dummy=Movie();
      base->push_back(dummy);
      for(string::iterator it=entry.begin(); it!=entry.end(); ++it){
         switch(count){
            case 0:
               if((*it)=='|'){  
                  base->at(spotNumber).setIndex(spotNumber);  
                  count++;    
               }
               break;
            case 1:
               if((*it)=='|'){
                  count++;
                  base->at(spotNumber).setTitle(valueString);
                  valueString="";
               }
               else{valueString += (*it);}
               break;

            case 2:
               if((*it)=='|'){
                  count++;
                  ++it;
               }
               break;
 
            case 3:
               if((*it)=='|'){
                  count++;
                  ++it;
               }
               break;       

            case 4:
               if((*it)=='|'){
                  genreCount++;
               }
               else if((*it)=='1'){
                  base->at(spotNumber).setGenres(genreCount);
               }
               break;
         }
      }
      spotNumber++;
   }      
}

Movie MovieBase::at(int i){
   return base->at(i);
}
 
void MovieBase::setAverage(int i){
   base->at(i).setRating(base->at(i).getRatings());
}

void MovieBase::setAdjustedAgain(int i, double j){
   base->at(i).setAdjusted(j);
}

int MovieBase::size(){
   return base->size();
}


void MovieBase::createRatings(vector<Movie>* mBase){
   for(int i=1; i<mBase->size(); i++){
      setAverage(i);
   }
}  


vector<Movie>* MovieBase::getBase() const {
   return base;
}

double MovieBase::actionAverage(vector<Movie>* mBase){
   int size=0;
   double total=0.0;
   for(int i=1; i<mBase->size(); i++){
      if(mBase->at(i).getGenres()->find("action")!=mBase->at(i).getGenres()->end()){
         total+=mBase->at(i).getAverage();
         size++;
      }
   }
   return total/size; 
}

double MovieBase::noirAverage(vector<Movie>* mBase){
   int size=0;
   double total=0.0;
   for(int i=1; i<mBase->size(); i++){
      if(mBase->at(i).getGenres()->find("noir")!=mBase->at(i).getGenres()->end()){
         total+=mBase->at(i).getAverage();
         size++;
      }
   }
   return total/size;
}

double MovieBase::lightAverage(vector<Movie>* mBase){
   int size=0;
   double total=0.0;
   for(int i=1; i<mBase->size(); i++){
      if(mBase->at(i).getGenres()->find("light")!=mBase->at(i).getGenres()->end()){
         total+=mBase->at(i).getAverage();
         size++;
      }
   }
   return total/size;
}

double MovieBase::seriousAverage(vector<Movie>* mBase){
   int size=0;
   double total=0.0;
   for(int i=1; i<mBase->size(); i++){
      if(mBase->at(i).getGenres()->find("serious")!=mBase->at(i).getGenres()->end()){
         total+=mBase->at(i).getAverage();
         size++;
      }
   }
   return total/size;
}

double MovieBase::fantasyAverage(vector<Movie>* mBase){
   int size=0;
   double total=0.0;
   for(int i=1; i<mBase->size(); i++){
      if(mBase->at(i).getGenres()->find("fantasy")!=mBase->at(i).getGenres()->end()){
         total+=mBase->at(i).getAverage();
         size++;
      }
   }
   return total/size;
}

double MovieBase::historyAverage(vector<Movie>* mBase){
   int size=0;
   double total=0.0;
   for(int i=1; i<mBase->size(); i++){
      if(mBase->at(i).getGenres()->find("history")!=mBase->at(i).getGenres()->end()){
         total+=mBase->at(i).getAverage();
         size++;
      }
   }
   return total/size;
}

vector<double>* MovieBase::averageGroup(vector<Movie>* mBase){
   vector<double>* averages=new vector<double>();
   averages->push_back(actionAverage(mBase));
   averages->push_back(noirAverage(mBase));
   averages->push_back(lightAverage(mBase));
   averages->push_back(seriousAverage(mBase));
   averages->push_back(fantasyAverage(mBase));
   averages->push_back(historyAverage(mBase));
   return averages;
}

