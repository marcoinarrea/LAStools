# makefile for LGPL-licensed LAStools
# 
COPTS_COMMON = -O3 -std=c++2b
COPTS_WASM     = -lembind -sSINGLE_FILE=1 -sMODULARIZE=1 -sEXPORT_ES6=1 -sENVIRONMENT=web,worker -sALLOW_MEMORY_GROWTH=1 -sEXPORT_NAME='createInstance' -sEXPORTED_RUNTIME_METHODS="['FS']" -sFORCE_FILESYSTEM=1 -sEXIT_RUNTIME=1
COPTS_PARTIAL = -Wall -Wno-deprecated -Wno-strict-aliasing -Wno-write-strings -Wno-unused-result -DNDEBUG -DUNORDERED -DHAVE_UNORDERED_MAP
COMPILER  = emcc
LINKER  = emcc
DEBUG = -sASSERTIONS

LASLIBS     = -L../../LASlib/lib
LASINCLUDE  = -I../../LASzip/src -I../../LASlib/inc 

# LIBS = 
INCLUDE = -I../

all: clobber laszip.js lasinfo.js lasprecision.js las2txt.js txt2las.js las2las.js lasdiff.js lasmerge.js lasindex.js

laszip.js: geoprojectionconverter.o 
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} geoprojectionconverter.o laszip_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasinfo.js: geoprojectionconverter.o
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} geoprojectionconverter.o lasinfo_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasprecision.js: geoprojectionconverter.o
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} geoprojectionconverter.o lasprecision_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

las2txt.js:
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} las2txt_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

txt2las.js: geoprojectionconverter.o
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} geoprojectionconverter.o txt2las_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

las2las.js: geoprojectionconverter.o
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} geoprojectionconverter.o las2las_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasdiff.js:
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} lasdiff_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasmerge.js: geoprojectionconverter.o 
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} geoprojectionconverter.o lasmerge_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasindex.js:
	${LINKER} ${COPTS_COMMON} ${COPTS_WASM} ${DEBUG} lasindex_wrapper.cpp -llas_wasm -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

geoprojectionconverter.o: 
	${COMPILER} -c ${COPTS_COMMON} ${COPTS_PARTIAL} ${INCLUDE} $(LASINCLUDE) ../geoprojectionconverter.cpp -o $@

clean:
	rm -rf *.o
	rm -rf laszip lasinfo lasprecision las2txt txt2las las2las lasdiff lasmerge lasindex
	rm -rf *.js

clobber:
	rm -rf *.o
	rm -rf laszip lasinfo lasprecision las2txt txt2las las2las lasdiff lasmerge lasindex
	rm -rf *~
	rm -rf *.js
	rm -rf *~
