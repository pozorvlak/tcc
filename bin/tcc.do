SRC=../src
SRCS=$SRC/tcc.c
redo-ifchange $SRCS
gcc -o $3 $SRCS
