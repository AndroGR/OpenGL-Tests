/*
 * This file is part of ParticleEmitterEngine. License text follows:
 *
 * This is free and unencumbered software released into the public domain.
 * Anyone is free to copy, modify, publish, use, compile, sell, or distribute
 * this software, either in source code form or as a compiled binary, for any
 * purpose, commercial or non-commercial, and by any means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors of this
 * software dedicate any and all copyright interest in the software to the
 * public domain. We make this dedication for the benefit of the public at large
 * and to the detriment of our heirs and successors. We intend this dedication
 * to be an overt act of relinquishment in perpetuity of all present and future
 * rights to this software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __particle_emitter_engine__
#define __particle_emitter_engine__

#include <GL/glew.h>
#include <cstdint>
#include <glm/glm.hpp>

/* The type of particle we are going to emit. */
typedef enum { Dust, Water, Sand, Lava } ParticleClass;

/* A struct used to identify a single particle. */
typedef struct {
        short x, y;
        ParticleClass pc;
        glm::mat4 matrix;
        unsigned int program;
} Particle;

/* The general class used to draw particles. */
class ParticleEmitter {
      public:
        ParticleEmitter();

        const Particle *
        NewParticle(short x, short y,
                    ParticleClass pc = ParticleClass::Sand) const;
        uint32_t EmitSelf(Particle *p);
};

#endif /* __particle_emitter_engine__ */
