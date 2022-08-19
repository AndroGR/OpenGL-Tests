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

#include "ParticleEmitterEngine.hpp"

/* Our vertex shader.
 * It is used to calculate the position of
 * the particle on the GPU.
 */
const static char* VERTEX_SHADER =
    "#version 330 core\n"
    "\n"
    "layout(location = 0) in vec3 position;\n"
    "void main() {\n"
    "    gl_Position = vec4(position, 1.0);\n"
    "}\n";

/* Our fragment shader.
 * Used to decide the color of each pixel on the screen.
 */
const static char* FRAGMENT_SHADER =
    "#version 330 core\n"
    "\n"
    "out vec4 color;\n"
    "void main() {\n"
    /* TODO: Change the color to different things based on the particle. */
    "       color = vec4(1.0, 1.0, 1.0, 1.0);\n"
    "}\n";

ParticleEmitter::ParticleEmitter() {
        /* TODO. */
}

const Particle* ParticleEmitter::NewParticle(short x,
                                             short y,
                                             ParticleClass pc) const {
        /* Our vertex positions. Since we want something simple, we just go with
         * bytes. */
        int8_t vertices[] = {1, 0, 1, -1, 1, 1 - 1, -1, 1};
        /* Generating a GPU vertex buffer. */
        unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);

        /* Attaching the data to the vertex buffer. */
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
                     GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_BYTE, GL_FALSE, 3, nullptr);

        /* Creating the particle and its GPU program */
        Particle* p = new Particle();
        p->program = glCreateProgram();

        /*
         * Compiling our shaders.
         * For more complex projects, a compute
         * shader can be used too to improve performance.
         * However we are just going with the basics here.
         */
        unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);

        /* Setting the shader source code. */
        glShaderSource(vertex, 1, &VERTEX_SHADER, nullptr);
        glShaderSource(fragment, 1, &FRAGMENT_SHADER, nullptr);

        /* Compiling the particle shaders. */
        glCompileShader(vertex);
        glCompileShader(fragment);

        /* Assigning the particle fields. */
        p->x = x;
        p->y = y;
        p->pc = pc;
        p->matrix = glm::mat4(1.0f);

        /* Attaching the compiled shaders to the particle. */
        glAttachShader(p->program, vertex);
        glAttachShader(p->program, fragment);
        glLinkProgram(p->program);

        return p;
}

uint32_t ParticleEmitter::EmitSelf(Particle* p) {
        glDrawArrays(GL_POINTS, 0, 3);
        glUseProgram(p->program);
}