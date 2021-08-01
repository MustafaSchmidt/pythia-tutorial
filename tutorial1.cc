#include <iostream>

#include "Pythia8/Pythia.h"

int main()
{
    int nevents = 10;
    
    Pythia8::Pythia pythia;
    
    pythia.readString("Beams:idA = 2212");
    pythia.readString("Beams:idB = 2212");
    pythia.readString("Beams:eCM = 14.e3");
    pythia.readString("SoftQCD:all = on");
    pythia.readString("HardQCD:all = on");
    
    pythia.init();
    
    for (int i = 0; i < nevents; i++)
    {
        if (!pythia.next()) continue;
        
        std::cout << "Event: " << i << std::endl;
        std::cout << "Event size: " << pythia.event.size() << std::endl;
        
        for (int j = 0; j < pythia.event.size(); j++)
        {         
            int id = pythia.event[j].id();
            
            double m = pythia.event[j].m();
            
            double px = pythia.event[j].px();
            double py = pythia.event[j].py();
            double pz = pythia.event[j].pz();
            
            double pabs = sqrt(pow(px,2) + pow(py,2) + pow(pz,2));
            
            std::cout << id << " " << px << " " << py << " " << pz << " " << m << std::endl;
        }

    }
    
    return 0;
}
