#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H


class playerstatus                      //玩家状态类，主要控制玩家的金钱以及波数；
{
public:
    playerstatus();
    int money;
    int wave;
    void initstatus();
};

#endif // PLAYERSTATUS_H
