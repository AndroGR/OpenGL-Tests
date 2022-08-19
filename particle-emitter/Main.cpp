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

#include "Includes.hpp"
#include <SDL2/SDL_video.h>
#include <assert.h>

#include "ParticleEmitterEngine.hpp"

#define __particle_emitter__

/* Initializes OpenGL and loads the functions for it. */
static int
initGL()
{
        GLenum errorcode = glewInit();
        if (errorcode != GLEW_OK) {
                const unsigned char* error = glewGetErrorString(errorcode);
                std::cout << "Error: " << error << std::endl;
                return -1;
        } else {
                return 0;
        }
}

int
main(void)
{
        /* Whether the game is running or not. */
        bool running = true;
        std::vector<Particle*> vec;

        SDL_Window* window =
          SDL_CreateWindow("Particle Emitter",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           1280,
                           720,
                           SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
        assert(window != NULL);

        SDL_GLContext context = SDL_GL_CreateContext(window);
        if (!context) {
                std::cerr << "Error: " << SDL_GetError() << std::endl;
                return -1;
        }
        if (SDL_GL_MakeCurrent(window, context) != 0) {
                std::cout << "Error: " << SDL_GetError() << std::endl;
                return -1;
        }
        assert(initGL() == 0);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        while (running) {
                glClear(GL_COLOR_BUFFER_BIT);
                SDL_GL_SwapWindow(window);

                SDL_Event ev;
                SDL_PollEvent(&ev);

                switch (ev.type) {
                        case SDL_QUIT:
                                running = false;
                                goto cleanup;
                                break;
                }
        }
cleanup:
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
}