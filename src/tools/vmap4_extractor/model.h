/*
 * Copyright (C) 2013 LasCore <http://lascore.makeforum.eu/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MODEL_H
#define MODEL_H

#include "vec3d.h"
#include "modelheaders.h"
#include <vector>

class MPQFile;

Vec3D fixCoordSystem(Vec3D v);

class Model
{
private:
    void _unload()
    {
        delete[] vertices;
        delete[] indices;
        vertices = NULL;
        indices = NULL;
    }
    std::string filename;
public:
    ModelHeader header;
    Vec3D* vertices;
    uint16* indices;

    bool open();
    bool ConvertToVMAPModel(char const* outfilename);

    Model(std::string& filename);
    ~Model() { _unload(); }
};

class ModelInstance
{
public:
    Model* model;

    uint32 id;
    Vec3D pos, rot;
    unsigned int d1, scale;
    float w, sc;

    ModelInstance() : model(NULL), id(0), d1(0), scale(0), w(0.0f), sc(0.0f) {}
    ModelInstance(MPQFile& f, char const* ModelInstName, uint32 mapID, uint32 tileX, uint32 tileY, FILE* pDirfile);

};

#endif
