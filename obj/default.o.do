redo-ifchange ../src/$1.c
gcc -I../inc -MD -MF $1.d -c -o $3 ../src/$1.c
read DEPS <$1.d
redo-ifchange ${DEPS#*:}
