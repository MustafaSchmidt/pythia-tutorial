tutorial%: tutorial%.cc
	g++ -I/home/mustafa/software/pythia/pythia8306/include $@.cc -o $@ -lpythia8 -L/home/mustafa/software/pythia/pythia8306/lib
