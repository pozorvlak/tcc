OBJ=../obj
OBJS="$OBJ/lexer.o $OBJ/main.o $OBJ/die.o $OBJ/parser.o"
redo-ifchange $OBJS
gcc -o $3 $OBJS
