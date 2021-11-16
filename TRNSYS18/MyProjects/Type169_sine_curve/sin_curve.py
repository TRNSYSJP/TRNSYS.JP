"""type169(Python) sample"""
import TRNSYSpy as trn
import math

def PythonFunction():
	# retrieve values from the Inputs
    inp1 = trn.getInputValue(1)
    
	# processing
    degree = inp1%360
    out1 = math.sin(math.radians(degree))

	# return the new values to the Outputs
    trn.setOutputValue(1, out1)    
    return
