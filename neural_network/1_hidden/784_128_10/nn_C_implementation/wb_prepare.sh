#!/bin/bash

cp ../model/*.txt .

for f in w*.txt; do
	sed -i 's/ /, /g' $f
	sed -i 's/$/},/g' $f
	sed -i 's/^/{/g' $f

	sed -i '1s/^/float '$f'[][] = {/' $f
	echo "};" >> $f
done

for f in b*.txt; do
	sed -i 's/$/, /g' $f
	sed -i '1s/^/float '$f'[] = {/' $f
	echo "};" >> $f
done

rename -f "s/txt/h/" w*.txt
rename -f "s/txt/h/" b*.txt
