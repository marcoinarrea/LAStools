# makefile for liblas_wasm.a
#
#COPTS    = -g -Wall -DUNORDERED -DHAVE_UNORDERED_MAP -std=c++11
COPTS     = -O3 -Wall -Wno-deprecated -Wno-strict-aliasing -Wno-write-strings -Wno-unused-result -DNDEBUG -DUNORDERED -DHAVE_UNORDERED_MAP -std=c++11
COMPILER  = emcc
AR  = emar rc
#BITS     = -64

INCLUDE		= -I../../../LASzip/src -I../../inc -I../

OBJ_LAS		= lasreader.o lasignore.o laswriter.o lasreader_las.o lasreader_bin.o lasreader_shp.o lasreader_asc.o lasreader_bil.o lasreader_dtm.o lasreader_ply.o lasreader_qfit.o lasreader_txt.o lasreadermerged.o lasreaderbuffered.o lasreaderstored.o lasreaderpipeon.o laswriter_las.o laswriter_bin.o laswriter_qfit.o laswriter_wrl.o laswriter_txt.o laswritercompatible.o laswaveform13reader.o laswaveform13writer.o lasutility.o lasfilter.o lastransform.o laskdtree.o fopen_compressed.o

OBJ_LAZ		= ../../../LASzip/src/wasm/laszip.o ../../../LASzip/src/wasm/lasreadpoint.o ../../../LASzip/src/wasm/lasreaditemcompressed_v1.o ../../../LASzip/src/wasm/lasreaditemcompressed_v2.o ../../../LASzip/src/wasm/lasreaditemcompressed_v3.o ../../../LASzip/src/wasm/lasreaditemcompressed_v4.o ../../../LASzip/src/wasm/laswritepoint.o  ../../../LASzip/src/wasm/laswriteitemcompressed_v1.o ../../../LASzip/src/wasm/laswriteitemcompressed_v2.o ../../../LASzip/src/wasm/laswriteitemcompressed_v3.o ../../../LASzip/src/wasm/laswriteitemcompressed_v4.o ../../../LASzip/src/wasm/integercompressor.o ../../../LASzip/src/wasm/arithmeticdecoder.o ../../../LASzip/src/wasm/arithmeticencoder.o ../../../LASzip/src/wasm/arithmeticmodel.o ../../../LASzip/src/wasm/lasindex.o ../../../LASzip/src/wasm/lasquadtree.o ../../../LASzip/src/wasm/lasinterval.o ../../../LASzip/src/wasm/mydefs.o 

all: liblas_wasm.a

liblas_wasm.a: ${OBJ_LAZ} ${OBJ_LAS} 
	$(AR) $@ ${OBJ_LAZ} ${OBJ_LAS}
	cp -p $@ ../lib

clean:
	rm -rf ${OBJ_LAZ} ${OBJ_LAS} 

clobber:
	rm -rf liblas_wasm.a
	rm -rf ${OBJ_LAZ} ${OBJ_LAS}
	rm -rf *~
