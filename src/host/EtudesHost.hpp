/*

Études Audiovisuel - graphical elements for audiovisual composition
Copyright (C) 2015 Patric Schmitz, Claudio Cabral

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef _ETUDES_ETUDESHOST
#define _ETUDES_ETUDESHOST

#include <vector>

class GLFWwindow;
class Etude;

namespace etudes {
  class EtudesHost {
    public:
      friend void key_callback(GLFWwindow* window,
                               int key, int scancode, int action, int mods);
      
      EtudesHost();
      ~EtudesHost();
      
      bool initialise();

      /**
       * @return Wether the application will continue to run, i.e. the
       *         user can do while(host.loopIteration()) {}.  
       */
      bool loopIteration();
      
    private:
      bool initGLFW();
      bool initOSC();
      bool initEtudes();

      void processInput();
      void keyCallback(int, int, int, int);
      
      void nextEtude();
      void prevEtude();
      void printEtude();

      void render();

      GLFWwindow *window;
      bool quitLoop;

      std::vector<Etude*> etudes;
      std::vector<Etude*>::const_iterator curEtude;
  };
}

#endif // _ETUDES_ETUDESHOST
