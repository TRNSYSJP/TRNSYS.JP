"""type169(Python) sample"""
import TRNSYSpy as trn
import traceback
import os

def myFunc():
	# retrieve values from the Inputs
	inp1 = trn.getInputValue(1)
	inp2 = trn.getInputValue(2)
	inp3 = trn.getInputValue(3)
	# processing
	out1 = inp1+inp2
	out2 = inp3**inp2
	# return the new values to the Outputs
	trn.setOutputValue(1, out1)
	trn.setOutputValue(2, out2)
	return

def PythonFunction():
	"""This function is called from TRNSYS/Type169"""
	# delete the previous log file if it exists.
	logfile = "_error.log"
	if os.path.exists(logfile):
		os.remove(logfile)

	try:
		myFunc()

	except:
		# save messages to the log file when something goes wrong.
		print('error')
		with open(logfile, 'w') as f:
			f.write(traceback.format_exc())
