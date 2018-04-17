phase.png pos.png vel.png: tray.txt NB_graph.py 
	python3 NB_graph.py 
tray.txt: NB_gravity.cpp
	c++ NB_gravity.cpp -o gravity
	./gravity > tray.txt
