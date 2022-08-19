CPP=/usr/bin/clang++
ESOURCES=ParticleEmitterEngine.cpp
SOURCES=Main.cpp

CPPFLAGS=-Wall -Wextra -Werror -fstack-protector-all -O3
ECPPFLAGS=-fPIC -shared
LFLAGS=-L. -lparticle_engine -lSDL2 -lGL -lGLEW

EOUTFILE=libparticle_engine.so
OUTFILE=particle_emitter

make: $(SOURCES) $(ESOURCES)
	@$(CPP) -o $(EOUTFILE) $(ESOURCES) $(CPPFLAGS) $(ECPPFLAGS)
	@echo "Finished engine compilation."

	@$(CPP) -o $(OUTFILE) $(SOURCES) $(CPPFLAGS) $(LFLAGS)
	@echo "Finished executable."
	@echo "Done."

run: $(OUTFILE) $(EOUTFILE)

	@LD_LIBRARY_PATH+=./ ./$(OUTFILE)

clean: $(EOUTFILE) $(OUTFILE)
	@rm ./$(OUTFILE)
	@rm ./$(EOUTFILE)
	@echo "Done."

