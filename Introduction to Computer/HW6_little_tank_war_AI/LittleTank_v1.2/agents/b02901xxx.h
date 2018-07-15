#ifndef __b02901xxx_h__
#define __b02901xxx_h__

//!! TODO 1: modify the ifndef/define protection as your ID like "__b02901xxx_h__"

#include "../PolicyMaker.h"

//!! TODO 2: rename your agent class name as "Agent_b02901xxx" with your own student ID
class Agent_b02901xxx:public PolicyMaker{
public:
//!! TODO 3: put your student ID for the constructor of PolicyMaker (the base class)
// you can have argument(s), but all these argument(s) must have their default value
    Agent_b02901xxx():PolicyMaker("b02901xxx"){}

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
        Direction tankInLine = noDir;
        if     (view.isTank( 7)) tankInLine = U_Dir;
        else if(view.isTank(17)) tankInLine = D_Dir;
        else if(view.isTank(11)) tankInLine = L_Dir;
        else if(view.isTank(13)) tankInLine = R_Dir;
        if(tankInLine!=noDir){
            if(tankInLine==pTank->getFacing()) return fire;
        }
        DebuggingMessage = "Hello~";
        return randMove();
    }
};

#endif //__b02901xxx_h__
