#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        

    protected:
    float money;
    public:
        Player(){
            money = 1000.f;
        };
        void setMoney(float cost) {
            money = money-cost;
        }
        float getMoney() {
            return money;
        }
        ~Player(){};
};

#endif