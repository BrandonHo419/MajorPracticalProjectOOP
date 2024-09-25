#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        float money;
    public:
        Player();
        void setMoney(float cost);
        float getMoney();
};

#endif