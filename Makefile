CURRENT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
SHELL = /bin/sh

export PATH := $(PATH):$(CURRENT_DIR)/emsdk:$(CURRENT_DIR)/emsdk/node/14.18.2_64bit/bin:$(CURRENT_DIR)/emsdk/upstream/emscripten

all: deps
	cd LASlib && make
	cd LASzip && make
	cd src && make
#	cd src_full && make

deps:
	git submodule update --init --recursive
	cd emsdk && ./emsdk install latest
	cd emsdk && ./emsdk activate latest

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
