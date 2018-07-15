#ifndef __b02901035_h__
#define __b02901035_h__

//!! TODO 1: modify the ifndef/define protection as your ID like "__b02901xxx_h__"

#include "../PolicyMaker.h"

//!! TODO 2: rename your agent class name as "Agent_b02901xxx" with your own student ID
class Agent_b02901035:public PolicyMaker{
public:
//!! TODO 3: put your student ID for the constructor of PolicyMaker (the base class)
// you can have argument(s), but all these argument(s) must have their default value
    Agent_b02901035():PolicyMaker("b02901035"){}

    //{ ===== you can add any member functions and datas here =====
        //but don't use any static data!!!
    Action randMove(){
        int r = rand()%6;
        //2/6%: just go ahead
        //4/6%: 1/6% for each dir
        switch(r){
        case 0:
        case 1:
            return Action(pTank->getFacing());
        case 2:
            return U_Act;
        case 3:
            return D_Act;
        case 4:
            return L_Act;
        case 5:
            return R_Act;
        default:
            return noAct;
        }
    }
    //} ===========================================================

//!! TODO 4: implement your own actionToDo function here
    virtual Action actionToDo(int arg){
        getView(2);
        // view:
        // 00 01 02 03 04
        // 05 06 07 08 09
        // 10 11 me 13 14
        // 15 16 17 18 19
        // 20 21 22 23 24

        // find tank in certain direction, turn to face it and fire
        Direction tankInLine = noDir;

        if     (view.isTank( 7) || view.isTank( 2)){
                tankInLine = U_Dir;
                if (pTank->getFacing()!=tankInLine) return U_Act;
        }
        else if(view.isTank(17) || view.isTank(22)){
                tankInLine = D_Dir;
                if (pTank->getFacing()!=tankInLine) return D_Act;
        }
        else if(view.isTank(11) || view.isTank(10)){
                tankInLine = L_Dir;
                if (pTank->getFacing()!=tankInLine) return L_Act;
        }
        else if(view.isTank(13) || view.isTank(14)){
                tankInLine = R_Dir;
                if (pTank->getFacing()!=tankInLine) return R_Act;
        };

        if((tankInLine!=noDir) && (tankInLine==pTank->getFacing())) return fire;

        // change direction when faced wall or edge
        int obsDir[4];
        for (int i = 0; i < 4; i++) obsDir[i] = 0;

        getView(2);

        if(view.isWall( 7)) obsDir[0] = 1;
        if(view.isWall(17)) obsDir[1] = 1;
        if(view.isWall(11)) obsDir[2] = 1;
        if(view.isWall(13)) obsDir[3] = 1;

        int turnDir = obsDir[0] + obsDir[1] + obsDir[2] + obsDir[3];

        getView(2);

        if (turnDir == 4);
        else if (turnDir == 3){
            if     (obsDir[0]==0) return U_Act;
            else if(obsDir[1]==0) return D_Act;
            else if(obsDir[2]==0) return L_Act;
            else if(obsDir[3]==0) return R_Act;
        }

        else if (turnDir == 2){
            int r = rand()%2;

            if (obsDir[0] * obsDir[1] == 1) // turn to L or R
            {
                if      (pTank->getFacing()==L_Dir) return L_Act;
                else if (pTank->getFacing()==R_Dir) return R_Act;
                else if (r == 1) return L_Act;
                else return R_Act;
            }

            else if (obsDir[0] * obsDir[2] == 1) // turn to D or R
            {
                if      (pTank->getFacing()==D_Dir) return D_Act;
                else if (pTank->getFacing()==R_Dir) return R_Act;
                else if (r == 1) return D_Act;
                else return R_Act;
            }

            else if (obsDir[0] * obsDir[3] == 1) // turn to D or L
            {
                if      (pTank->getFacing()==D_Dir) return D_Act;
                else if (pTank->getFacing()==L_Dir) return L_Act;
                else if (r == 1) return D_Act;
                else return L_Act;
            }

            else if (obsDir[1] * obsDir[2] == 1) // turn to U or R
            {
                if      (pTank->getFacing()==U_Dir) return U_Act;
                else if (pTank->getFacing()==R_Dir) return R_Act;
                else if (r == 1) return U_Act;
                else return R_Act;
            }

            else if (obsDir[1] * obsDir[3] == 1) // turn to U or L
            {
                if      (pTank->getFacing()==U_Dir) return U_Act;
                else if (pTank->getFacing()==L_Dir) return L_Act;
                else if (r == 1) return U_Act;
                else return L_Act;
            }

            else if (obsDir[2] * obsDir[3] == 1) // turn to U or D
            {
                if      (pTank->getFacing()==U_Dir) return U_Act;
                else if (pTank->getFacing()==D_Dir) return D_Act;
                else if (r == 1) return U_Act;
                else return D_Act;
            }
        }

        else // turnDir == 1
        {
            int r = rand()%3;

            if (obsDir[0] == 1)
            {
                if      (pTank->getFacing()==D_Dir) return D_Act;
                else if (pTank->getFacing()==L_Dir) return L_Act;
                else if (pTank->getFacing()==R_Dir) return R_Act;
                else if (r == 0) return D_Act;
                else if (r == 1) return L_Act;
                else return R_Act;
            }

            else if (obsDir[1] == 1)
            {
                if      (pTank->getFacing()==U_Dir) return U_Act;
                else if (pTank->getFacing()==L_Dir) return L_Act;
                else if (pTank->getFacing()==R_Dir) return R_Act;
                else if (r == 0) return U_Act;
                else if (r == 1) return L_Act;
                else return R_Act;
            }

            else if (obsDir[2] == 1)
            {
                if      (pTank->getFacing()==U_Dir) return U_Act;
                else if (pTank->getFacing()==D_Dir) return D_Act;
                else if (pTank->getFacing()==R_Dir) return R_Act;
                else if (r == 0) return U_Act;
                else if (r == 1) return D_Act;
                else return R_Act;
            }

            else if (obsDir[3] == 1)
            {
                if      (pTank->getFacing()==U_Dir) return U_Act;
                else if (pTank->getFacing()==D_Dir) return D_Act;
                else if (pTank->getFacing()==L_Dir) return L_Act;
                else if (r == 0) return U_Act;
                else if (r == 1) return D_Act;
                else return L_Act;
            }
        }

        DebuggingMessage = "Hello~";
        return randMove();
    }
};

#endif //__b02901xxx_h__
