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

#ifndef _SHADERREGISTRY
#define _SHADERREGISTRY

#include <vector>
#include <map>
#include <string>

#include <glbinding/gl/gl.h>

class ShaderRegistry {
    std::map<std::string, gl::GLuint> m_mapShader;
    std::map<std::string, gl::GLuint> m_mapProgram;
    std::map<std::string, std::map<std::string, GLuint> > m_mapUniform;

public:
    GLuint RegisterShader(std::string name,
                          gl::GLenum type,
                          std::vector<std::string> paths);

    GLuint RegisterProgram(std::string name,
                           std::vector<std::string> shader_names);

    GLuint RegisterUniform(std::string program_name,
                           std::string uniform_name);

    GLuint GetProgram(std::string name);
    GLuint GetUniform(std::string program_name,
                      std::string uniform_name);

};

#endif // _SHADERREGISTRY
