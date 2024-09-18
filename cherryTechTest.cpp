#include <iostream>
#include "cherryTech.h"

using namespace std;

int main() {
    // Create an instance of cherryTech
    cherryTech tech;

    // Output initial growth speed
    cout << "Initial Growth Speed: " << tech.getSpeed() << endl;

    // Set the baseModifier and cropModifier (assuming these are meant to be public or have setter methods)
    // Since your class doesn't provide a setter, I'll add a setter for baseModifier in Technology
    tech.setBaseModifier(2);  // Setting the baseModifier to 2 (for example)
    tech.setCropModifier(1.5);  // Setting cropModifier to 1.5

    // Call setModifier to modify growth speed
    tech.setModifier();

    // Output updated growth speed
    cout << "Updated Growth Speed: " << tech.getSpeed() << endl;

    return 0;
}
