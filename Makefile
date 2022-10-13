all: deps
	cd LASlib && make
	cd LASzip && make
	cd src && make
#	cd src_full && make

deps:
	git submodule update --init --recursive
	git pull
	cd emsdk && ./emsdk install latest
	cd emsdk && ./emsdk activate latest
	echo 'source "/emsdk/emsdk_env.sh"' >> .zshenv
	echo 'source "/emsdk/emsdk_env.sh"' >> .bashrc

clean:
	cd LASlib && make clean
	cd LASzip && make clean
	cd src && make clean
#	cd src_full && make clean

clobber:
	cd LASlib && make clobber
	cd LASzip && make clobber
	cd src && make clobber
#	cd src_full && make clobber
	cd bin && rm -rf lasinfo laszip lasprecision las2txt txt2las las2las lasdiff lasmerge lasthin las2shp shp2las las2iso las2tin lasboundary lasview las2dem
