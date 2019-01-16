mydaemon:mydaemon.cc
	g++ -o $@ $^
.PHONY:clean
clean:
	rm -f mydaemon
