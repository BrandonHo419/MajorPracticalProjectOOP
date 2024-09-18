#include "Technology.h"
#ifndef CHERRYTECH_H
#define CHERRYTECH_H

class cherryTech : public Technology {
    private:

    protected:
        float growthSpeed;
    public:
    cherryTech();
    float getSpeed();
    void setModifier();
    ~cherryTech();
};

#endif
