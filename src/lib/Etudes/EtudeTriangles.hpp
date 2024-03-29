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

#ifndef _ETUDES_ETUDETRIANGLES
#define _ETUDES_ETUDETRIANGLES

#include "Etude.hpp"

namespace etudes {
    class EtudeTriangles : public Etude {
    public:
        EtudeTriangles() {};
        virtual ~EtudeTriangles() {};
        
        std::string name() override;
        void draw() override;

    private:
    };
}

#endif // _ETUDES_ETUDETRIANGLES
