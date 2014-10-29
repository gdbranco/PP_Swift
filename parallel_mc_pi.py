import random
import sys
import queue
import threading

def local_monte(lancamentos, results):
	x = float()
	y = float()
	distancia = float()
	dentro = int(0)
	while lancamentos > 0:
		x = random.random()
		y = random.random()
		distancia = x**2 + y**2
		if distancia <= 1:
			dentro+=1
		lancamentos -= 1
	results.put(dentro)
	

def main():
	n_threads	= int(sys.argv[1])
	n_iter		= int(sys.argv[2])
	
	local_iter = n_iter/n_threads
	
	results = queue.Queue()
	thr_list = []
	
	for i in range(0, n_threads) :
		thr_list.append(threading.Thread( target = local_monte, args = (local_iter, results) ))
		thr_list[i].start()
	
	for i in range(0, n_threads) :
		thr_list[i].join()
	
	total = 0
	
	while(not results.empty()):
		total += results.get()
	

	pi = float(4*total/n_iter)
	print (pi)
	
if __name__ == "__main__":
	main()
