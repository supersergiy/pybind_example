

%.so: %.cpp
	c++ -O3 -fPIC -shared -std=c++11 -I pybind11/include `python-config --cflags --ldflags` $^ -o $@ 
all: numpy_example.so class_example.so func_example.so
