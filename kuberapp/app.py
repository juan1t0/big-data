from flask import Flask, request #import main Flask class and request object
from flask import render_template as render

import os
import sys
from io import StringIO

app = Flask(__name__) #create the Flask app

def runcode(code):
	codeOut = StringIO()
	codeErr = StringIO()
	sys.stdout = codeOut
	sys.stderr = codeErr
	exec(code)
	sys.stdout = sys.__stdout__
	sys.stderr = sys.__stderr__
	error = codeErr.getvalue()
	out = codeOut.getvalue()
	codeOut.close()
	codeErr.close()
	return str(out), str(error)

@app.route('/', methods=['GET', 'POST']) #allow both GET and POST requests
def form_example():
	if request.method == 'POST':
		code = request.form.get('code')
		out,error = runcode(code)
		return '''<h2>The code is:</h2><br>
			{}<br>
			<h2>Output:<br></h2>
			<h1>>> {}</h1>
			<h1Error: {}</h1>'''.format(code, out, error)

	return render('running.html')

if __name__ == '__main__':
	# app.run(debug=True, port=5000) #run app in debug mode on port 5000
	app.run(debug=True,host='0.0.0.0',port=int(os.environ.get('PORT', 8080)))