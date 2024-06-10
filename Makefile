all: main.cc src/PitchTracker.cc include/PitchTracker.h src/PitchRepresentation.cc include/PitchRepresentation.h \
	src/HomePlateRepresentation.cc include/HomePlateRepresentation.h include/HomePlateTracker.h src/HomePlateTracker.cc \
	src/BatterRepresentation.cc include/BatterRepresentation.h include/BatterTracker.h src/BatterTracker.cc \
	src/Feed.cc include/Feed.h include/BallStrikeClassifier.h src/BallStrikeClassifier.cc \
	include/StrikeZoneDeterminer.h src/StrikeZoneDeterminer.cc include/StrikeZoneRepresentation.h \
	src/Output.cc include/Output.h include/matplotlibcpp.h
	g++ -g -std=c++20 -Ofast -o main main.cc src/PitchTracker.cc src/PitchRepresentation.cc src/HomePlateTracker.cc src/HomePlateRepresentation.cc src/BatterTracker.cc src/BatterRepresentation.cc src/Feed.cc src/BallStrikeClassifier.cc src/StrikeZoneDeterminer.cc src/Output.cc -I /usr/include/python3.10 -lpython3.10

.PHONY: clean

clean:
	rm -f main