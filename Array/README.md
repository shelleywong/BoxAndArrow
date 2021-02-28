# BoxAndArrow Array Visualizer

The BoxAndArrow Array Visualizer provides the framework for creating and testing your own C-style array functions. If you haven't already, follow the steps in the main [BoxAndArrow README](https://github.com/shelleywong/BoxAndArrow) to Set Up Your Environment and Get the Source, then come back here for instructions specific to the Array Visualizer.<br>

## Initial Steps

1. Every time you open a new terminal, you will need to reactivate the PATH and other environment variables for Emscripten: 
```
$ cd emsdk
$ source ./emsdk_env.sh
```

2. Change to the BoxAndArrow directory, then create a Python 3 virtual environment by executing the `venv` command. In this case, we create a virtual environment named venv in the BoxAndArrow directory. Then activate the virtual environment in this directory. The `(venv)` before the Linux command prompt lets you know that you are currently working within your Python3 virtual environment:
```
$ cd ../BoxAndArrow
$ python3 -m venv venv
$ . venv/bin/activate
(venv) $
```

If you want to leave the virtual environment, simply run:
```
(venv) $ deactivate
$
```

3. Next you will need to install all of the packages used in this Flask application. From the directory with the requirements.txt file, you can install them using `pip`:
```
$ pip install -r requirements.txt
```

4. Move to the BoxAndArrow/Array subdirectory -- this contains the Array Visualizer Flask application. Before the `flask` script can be used, you need to use the `FLASK_APP` environment variable to tell it where to find the application (make sure you are in the directory where arr.py is located):
```
$ cd Array
$ export FLASK_APP=arr.py
``` 

5. Now you can compile the starter code! The Array Visualizer provides a model solution and compares it with your results. To ensure that everything compiles from the get-go, a default return value has been set for all of the provided function prototypes. If you compile everything without changing the starter code, you can see what happens when a function implementation doesn't match the solution. Run the following commands each time you update your code:
```
$ make
$ ./runscript.sh
$ flask run
```

* `make` uses the Emscripten Compiler Frontend (emcc) to build the code and compile your program so that it can be run on the Web. 
* When `make` successfully runs, it generates three files in the BoxAndArrow/Array directory:
    * `array.wasm`: binary code in the WebAssembly format
    * `array.js`: JavaScript glue code (necessary for .wasm code to work on the Web)
    * `array.html`: an HTML file that loads, compiles, and instantiates the WebAssembly code
* Flask expects all JavaScript and CSS files to be in a `static` folder and all HTML files to be in a `templates` folder. The `runscript.sh` script moves the generated files to the appropriate locations for this application.
* `flask run` is a command line script that can be used to run a development server. If you run into any errors with `flask run`, make sure you have set the `FLASK_APP` environment variable to point to the `arr.py` application and you are in the same directory as `arr.py`.
* You should see something similar to the following printed in the terminal:
```
 * Serving Flask app "arr.py"
 * Environment: production
   WARNING: This is a development server. Do not use it in a production deployment.
   Use a production WSGI server instead.
 * Debug mode: off
 * Running on http://127.0.0.1:5000/ (Press CTRL+C to quit)
```
* For the average individual, a development server is all that you need to use this project. The name of your server is likely to be different -- simply copy the listed URL into the browser and include the path to the Array Visualizer application: `http://127.0.0.1:5000/array`
