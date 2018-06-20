import numpy as np
import matplotlib.pyplot as plt
import matplotlib.lines as mlines

import math

def bissection(a,b,tol,itermax,f):
	c = float(a+b)/2.0
	k = 0
	
	print("Bissecao")	
	print("k       a       b      xk       f(xk)       b-a")		
	
	while ( (b-a) >= tol or math.fabs(f(c)) >= tol ) and (k <= itermax):
		if f(a)*f(c) < 0:
			b = c
		else:
			a = c
		c = float(a+b)/2.0
		k = k + 1
		print("%d %f %f %f %f %f" % (k, a, b, c, f(c), b-a) )		

	print("Solucao encontrada = %f" % (c) )
	print("Num de iteracoes   = %d" % (k) )
	print("Intervalo da raiz  = (%f,%f)"% (a,b) )	
	print("Erro absoluto      = %f"   % math.fabs(f(c)))	


def falseposition(a,b,tol,itermax,f):
	 
	k = 0
	xant = a;
	xk = float(a*f(b)-b*f(a))/(f(b)-f(a))
	
	x = np.arange(a-0.5, b+0.5, 0.1);
	y = [f(z)  for z in x]
	ax = plt.gca()
	ax.axhline(y=0, color='k')
	ax.axvline(x=0, color='k')
	plt.plot(x, y)
	
	l = mlines.Line2D([a-0.1,b+0.1], [f(a-0.1),f(b+0.1)])
	ax.add_line(l)
	


	print("Posicao Falsa")
	print("k       a      b     xk      f(xk)        xk-xant")		


	while (xk - xant >= tol or math.fabs(f(xk)) >= tol) and k <= itermax:
		
		if f(a)*f(xk) < 0:
			b = xk
		else:
			a = xk
		
		l = mlines.Line2D([a-0.1,b+0.1], [f(a-0.1),f(b+0.1)])
		ax.add_line(l)


		xant = xk
		xk = float(a*f(b)-b*f(a))/(f(b)-f(a))
		
		print("%d %f %f %f %f %f" % (k, a, b, xk, f(xk), xk - xant) )		

		k = k + 1

	plt.show()
	
	print("Solucao encontrada = %f" % (xk) )
	print("Num de iteracoes   = %d" % (k) )
	print("Intervalo da raiz  = (%f,%f)"% (a,b) )	
	print("Erro absoluto      = %f"   % math.fabs(f(xk)))	


def NewthonRaphson(xant,tol, itermax, f, _f):

	k = 0
	xk = xant
	passo = 1000
	
	print("NewthonRaphson")
	print("k        xk         f(xk)       passo ")	
	while (math.fabs(passo) >= tol  or  math.fabs( f(xk) ) >= tol) and k <= itermax:
		passo = float(f(xk))/_f(xk)
		xk = xk - passo
		k = k + 1
		print ("%d  %f  %f %f" % (k, xk, f(xk), passo) )	    
  
	print("Solucao encontrada = %f" % (xk) )
	print("Num de iteracoes   = %d" % (k) )
	print("Erro absoluto      = %f"   % math.fabs(f(xk)))	

  

	
def f1(x):
	return pow(x,2) - 2

def _f1(x):
	return 2*x


def f2(x):
  return 2*pow(x,3) - 4*pow(x,2) + 3*x

def _f2(x):
  return 6*pow(x,2) - 8*x + 3


def f3(x):
	return pow(x,5) - 3*pow(x,4) - 3*pow(x,2) + 2


def main():
	
	print("----------------------")
	print("f(x) = x^2 - 2")
	print("tol  = %f" % pow(2,-10) )
	print("itermax %d" % 100)
	print("[%d,%d]" % (1, 2))  	
	bissection(1,2,pow(2,-10),100,f1)
	print("----------------------\n\n")
		
	print("----------------------")
	print("f(x) = x^2 - 2")
	print("tol  = %f" % pow(2,-10) )
	print("itermax %d" % 100)
	print("[%d,%d]" % (1, 2))  		
	falseposition(1,2,pow(2,-10),100,f1)
	print("----------------------\n\n")
	
	print("----------------------")
	print("f(x) = x^2 - 2")
	print("tol  = %f" % pow(2,-10) )
	print("itermax %d" % 100)
	print("[%d,%d]" % (1, 2))  		
	NewthonRaphson(1,pow(2,-10),100,f1, _f1)
	print("----------------------\n\n")
	
  
	print("----------------------")
	print("f(x) = 2x^3 - 4x^2 + 3x")
	print("tol  = %f" % pow(2,-10) )
	print("itermax %d" % 100)
	print("[%d,%d]" % (-1, 0.5))
	print("%f %f" % (f2(-1), f2(0.5)) )  	
	bissection(-1,0.5,pow(2,-10),100,f2)
	print("----------------------\n\n")
	

	print("----------------------")	
	print("f(x) = 2x^3 - 4x^2 + 3x")
	print("tol  = %f" % pow(2,-10) )
	print("itermax %d" % 100)
	print("[%d,%d]" % (-1, 0.5))
	print("%f %f" % (f2(-1), f2(0.5)) )  	
	falseposition(-1,0.5,pow(2,-10),100,f2)
	print("----------------------\n\n")
	
	print("----------------------")	
	print("f(x) = 2x^3 - 4x^2 + 3x")
	print("tol  = %f" % pow(2,-10) )
	print("itermax %d" % 100)
	print("[%d,%d]" % (-1, 0.5))
	print("%f %f" % (f2(-1), f2(0.5)) )  	
	NewthonRaphson(-1,pow(2,-10),100,f2,_f2)
	print("----------------------\n\n")
	
if __name__ == "__main__":
    main()
