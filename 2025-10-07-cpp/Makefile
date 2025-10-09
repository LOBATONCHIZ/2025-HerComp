all: fig

%.x: %.cpp
	g++ -std=c++23 $< -o $@

data.txt: ode.x
	./ode.x > $@

fig: plot.py data.txt
	python plot.py

clean:
	rm -f *~ *.txt a.out *.x
