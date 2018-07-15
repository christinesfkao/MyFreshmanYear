#ifndef __b02901000_h__
#define __b02901000_h__

// the same as default b02901xxx

#include "../PolicyMaker.h"

class Agent_b02901000:public PolicyMaker{
public:
    Agent_b02901000():PolicyMaker("b02901000"){}
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
    virtual Action actionToDo(int arg){
        getView(2);
        Direction tankInLine = noDir;
        if     (view.isTank( 7)) tankInLine = U_Dir;
        else if(view.isTank(17)) tankInLine = D_Dir;
        else if(view.isTank(11)) tankInLine = L_Dir;
        else if(view.isTank(13)) tankInLine = R_Dir;
        if(tankInLine!=noDir){
            if(tankInLine==pTank->getFacing()) return fire;
        }
        return randMove();
    }
};

#endif //__b02901000_h__
