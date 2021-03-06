#ifndef RUBIK_HH
#define RUBIK_HH

#include <list>

/*
 * Rubik's cube class
 */
class Rubik {
    private:
        /*
         * Leftmost 5 bits are for identification. Rightmost for orientation
         * Orientations is given by X,Y,Z tuple represented with 3 bits 
         */
        unsigned char left[8];   //0 to 7 cubie
        unsigned char right[8];  //8 to 15 cubie
        unsigned char middle[4]; //16 to 19 cubie

    public:
        void clean();
        void print();
        void transformToGoal();
        void random();
        Rubik clone();
        void setCubie(int,unsigned char);
        unsigned char getCubie(int);
        void turn(int,int);
        void turnLeft();
        void turnRight();
        void turnTop();
        void turnBottom();
        void turnFront();
        void turnBack();
        bool isSolved();
        std::list<Rubik> getSucc();
        bool isMaxOriented(int);
        void setMaxOrientation(int);
        void setMinOrientation(int);
        unsigned int getPosition(int);
        unsigned int getOrientation(int);
    private:
        void changePositionTo(int,int);
        unsigned char swapXY(unsigned char);
        unsigned char swapXZ(unsigned char);
        unsigned char swapYZ(unsigned char);
};

#endif
