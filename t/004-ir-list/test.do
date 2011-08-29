OBJS="test.o ../../obj/ir.o ../../obj/ir-list.o"
redo-ifchange $OBJS
gcc -ltap -o $3 $OBJS
