#include "defenitions.h"

//Collision
bool collisionAny(int xMin1, int xMax1, int xMin2, int xMax2, int yMin1, int yMax1, int yMin2, int yMax2){
  if (xMin1 < xMax2 && yMin1 < yMax2 && xMin2 < xMax1 && yMin2 < yMax1){
    return true;
  }
  return false;
}
bool collisionBottom(int yMin1, int yMax1, int yMin2, int yMax2){
  if(yMin1 < yMax2 && yMax1 > yMax2){
    return true;
  }
  return false;
}
bool collisionTop(int yMin1, int yMax1, int yMin2, int yMax2){
  if(yMin2 < yMax1 && yMin1 < yMin2){
    return true;
  }
  return false;
}
bool collisionRight(int xMin1, int xMax1, int xMin2, int xMax2){
  if(xMin2 < xMax1 && xMin1 < xMin2){
    return true;
  }
  return false;
}
bool collisionLeft(int xMin1, int xMax1, int xMin2, int xMax2){
  if(xMin1 < xMax2 && xMax1 > xMax2){
    return true;
  }
  return false;
}

BITMAP* tileSprites[400][4];
BITMAP* projectileSprites[10][3];

FONT* pixelart;
FONT* pixelart_2;

//Checks if file exists
bool fexists(const char *filename){
  ifstream ifile(filename);
  return ifile;
}

//Random number generator. Use int random(lowest,highest);
int random(int newLowest, int newHighest){
  int lowest = newLowest, highest = newHighest; 
  int range = (highest - lowest) + 1;    
  int randomNumber = lowest+int(range*rand()/(RAND_MAX + 1.0));
  return randomNumber; 
}

//Convert int to string 
string convertInt(int number){
  stringstream ss;
  ss << number;
  return ss.str();
} 

//Convert bool to string
string convertBool(bool boolean){
  stringstream ss;
  ss << boolean;
  return ss.str();
}
