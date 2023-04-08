CXX = g++
target = json.out
src = $(wildcard *.cc)
obj = $(patsubst %.cc, %.o, $(SRC))
CXXFlages = -c -Wall -std=c++2a

$(target):$(obj)
	#(CXX) -o $@ $^

%.o:%.cc
	$(CXX) $(CXXFlages) $<

.PHONY:clean
clean:
	rm -f json.out *.o