OBJ=../obj
OBJS="$OBJ/lexer.o $OBJ/tcc.o $OBJ/die.o"
redo-ifchange $OBJS
gcc -o $3 $OBJS
