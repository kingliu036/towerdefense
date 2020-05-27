#ifndef ENEMY_H
#define ENEMY_H


class enemy
{
public:
    enemy();
    int direction[8];
    int turnx[8];
    int turny[8];
    void move(bool start);
private:
    void loadimages();
    void initenemy();
};

#endif // ENEMY_H
