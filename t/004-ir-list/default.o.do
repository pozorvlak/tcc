gcc -I../../inc -MD -MF $1.d -c -o $3 $1.c
read DEPS <$1.d
redo-ifchange ${DEPS#*:}
