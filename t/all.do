for i in *; do
	if [ -d $i ]; then
		redo-ifchange $i/all
	else
		redo-ifchange $i
	fi
done
