CC = g++
CFLAGS = -O3
LDFLAGS = -lgsl -lm -lgslcblas


LSOURCE = main.cpp corpus.cpp slda.cpp utils.cpp opt.cpp coordinate.cpp
LHEADER = corpus.h slda.h utils.h opt.h settings.h coordinate.h

slda: $(LSOURCE) $(HEADER)
	  $(CC) $(CFLAGS) $(LSOURCE) -o $@ $(LDFLAGS)

clean:
	-rm -f *.o slda
