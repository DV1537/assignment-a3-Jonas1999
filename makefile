TestRule: main.cpp
	g++ main.cpp Shape.h Shape.cpp Point.h Point.cpp Triangle.h Triangle.cpp Polygon.h Polygon.cpp Line.h Line.cpp -o main.exe -static-libgcc -static-libstdc++