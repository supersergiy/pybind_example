
ZNN_INCLUDES = -I/home/ubuntu/znnphi_interface/code/include -I/home/ubuntu/znnphi_interface/code/include/znn -I/home/ubuntu/znnphi_interface/ 

%.so: %.cpp
	c++ -O3 -fPIC -shared -std=c++11 -I pybind11/include `python-config --cflags --ldflags` $^ -o $@ 
all: numpy_example.so class_example.so func_example.so
.PHONY: znet
znet:
	icpc -pthread -std=c++14 `python-config --cflags --ldflags` -Ipybind11/include $(ZNN_INCLUDES) -fmax-errors=5 -DZNN_NO_HBW -DZNN_NO_CUDA -DNDEBUG -O3 -ffast-math -fno-omit-frame-pointer -DZNN_AVX -fPIC -lznnphiconv -c znet.cpp znet_python.cpp 
	icpc znet.o znet_python.o -lznnphiconv -shared -o znet.so 
	python znet.py
