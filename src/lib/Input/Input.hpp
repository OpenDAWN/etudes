#ifndef _ETUDES_SOURCE
#define _ETUDES_SOURCE

#include <map>
#include <string>
using std::map;
using std::string;

namespace etudes {

    /**
     * Input is the base class for all input data sources we want to
     * map to the inputs of the different Renderers. Examples could be
     * OSC, MIDI, Network, sensor, webfeed, random input, there shall
     * be no restrictions.
     *
     * @todo Think about a common representation which allows to treat
     * the value ranges of all inputs uniformly. For scalar values, we
     * settled on [0, 1]. Can we / do we need to think of other
     * representations for non-scalar, structured, vector
     * inputs?... Think...
     * claudio: Let's prepare a basic scalar OSC input, make a first 
     * working example and iterate. For the time being that will be enough...
     */
    class Input {
    public:
        typedef map<string, float> value_map;
        
        Input();
        virtual ~Input();

        bool start();
        void stop();
        
        virtual void update() = 0;
        
        const value_map & getInputs();
        float getInput(string);

    protected:
        virtual bool doStart() = 0;
        virtual void doStop()  = 0;
        
    private:
        bool m_bStarted;
        value_map m_mapInputs;
    };
}

#endif // _ETUDES_SOURCE