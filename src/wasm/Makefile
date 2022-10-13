# makefile for LGPL-licensed LAStools for WebAssembly
# 
COMPILER  = emcc
LINKER  = emcc
COPTS = -D name=COMPILE_WITH_GUI -O3  -Wall -Wno-deprecated -Wno-strict-aliasing -Wno-write-strings -Wno-unused-result -DNDEBUG -sEXIT_RUNTIME
COPTS_DEBUG = -sLLD_REPORT_UNDEFINED -DDEBUG -sASSERTIONS
COPTS_WASM = --no-entry -lembind -std=c++2b -sSINGLE_FILE=1 -sMODULARIZE=1 -sEXPORT_ES6=1 -sENVIRONMENT=web,worker -sEXPORT_NAME='createInstance' -sALLOW_MEMORY_GROWTH=1 -sEXPORTED_RUNTIME_METHODS="['FS']" -sFORCE_FILESYSTEM=1

# LIBS     = -L ./lib
INCLUDE  = -I ../

LASLIBS     = -L../../LASlib/lib
LASINCLUDE  = -I../../LASzip/src -I../../LASlib/inc

all: clobber laszip.js lasinfo.js lasprecision.js las2txt.js txt2las.js las2las.js lasdiff.js lasmerge.js lasindex.js

laszip.js: geoprojectionconverter.o 
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} geoprojectionconverter.o laszip_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasinfo.js: geoprojectionconverter.o
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} geoprojectionconverter.o lasinfo_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasprecision.js: geoprojectionconverter.o
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} geoprojectionconverter.o lasprecision_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

las2txt.js:
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} las2txt_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

txt2las.js: geoprojectionconverter.o
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} geoprojectionconverter.o txt2las_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

las2las.js: geoprojectionconverter.o
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} geoprojectionconverter.o las2las_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasdiff.js:
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} lasdiff_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasmerge.js: geoprojectionconverter.o 
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} geoprojectionconverter.o lasmerge_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

lasindex.js:
	${LINKER} ${COPTS} ${COPTS_DEBUG} ${COPTS_WASM} lasindex_wrapper.cpp ../../LASlib/lib/liblas_wasm.a -o $@ ${LIBS} ${LASLIBS} $(INCLUDE) $(LASINCLUDE)
	mkdir -p ../../wasm/
	mv $@ ../../wasm/$@

geoprojectionconverter.o: 
	${COMPILER} -c ${COPTS} ${COPTS_DEBUG} ${INCLUDE} $(LASINCLUDE) ../geoprojectionconverter.cpp -o $@

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
