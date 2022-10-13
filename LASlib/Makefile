all:
	cd src/wasm && make
	cd src && make
	cd example && make

clean:
	cd src/wasm && make clean
	cd src && make clean
	cd example && make clean
	rm -f lib/*
	rm -f libD/*

clobber:
	cd src/wasm && make clobber
	cd src && make clobber
	cd example && make clobber
	rm -f lib/*
	rm -f libD/*
