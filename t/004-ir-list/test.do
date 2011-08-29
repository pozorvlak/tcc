gcc -ltap -I../../inc -MD -MF $1.d -o $3 $1.c
read DEPS <$1.d
redo-ifchange ${DEPS#*:}
