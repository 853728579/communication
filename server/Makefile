ROOT=.
BIN=$(ROOT)/bin
OBJ=$(ROOT)/obj

OBJS = $(OBJ)/main.o $(OBJ)/SockZy.o $(OBJ)/Manage.o $(OBJ)/Admin.o
C11=-std=c++11

$(BIN)/service.exe:$(OBJS)
	g++ -o $@ $^


$(OBJ)/main.o:main.cpp
	g++ -c $< -o $@ $(C11)
$(OBJ)/SockZy.o:SockZy.cpp
	g++ -c $< -o $@ $(C11)
$(OBJ)/Manage.o:Manage.cpp
	g++ -c $< -o $@ $(C11)
$(OBJ)/Admin.o:Admin.cpp
	g++ -c $< -o $@ $(C11)
	
clean:
	rm -f $(OBJ)/*.o $(BIN)/*.exe

rebuild:clean $(BIN)/service.exe