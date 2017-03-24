tracer: *.cpp *.h
	g++ -std=gnu++14 -O3 -Wall tracer.cpp -o tracer
test: tracer
	./tracer | convert - -scale 100% traced.png
dump: tracer
	./tracer
clean:
	rm tracer
