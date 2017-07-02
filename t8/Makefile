
CXX = g++

CXXFLAGS = -std=c++11 -Wall -I_include

LDFLAGS = -lfltk -lfltk_images

EXEC = FormGenerator

OBJ = main.o GUI.o Project.o Input.o InputText.o InputSelect.o InputRadio.o functions.o GUIFormGenerator.o

$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ) $(LDFLAGS) $(CXXFLAGS)
	rm -R -f *.o *~

%.o: _src/%.cpp $(DEPS)
	$(CXX) -c $< $(DEPS) $(LIBS) $(CXXFLAGS)

%.o: _src/%.cxx $(DEPS)
	$(CXX) -c $< $(DEPS) $(LIBS) $(CXXFLAGS)

run:
	./$(EXEC)

clean:
	rm -R -f $(EXEC) *.o *~
