# BoxAndArrow Array Visualizer

The BoxAndArrow Array Visualizer provides the framework for creating and testing your own C-style array functions. If you haven't already, follow the steps in the main [BoxAndArrow README](https://github.com/shelleywong/BoxAndArrow) to Set Up Your Environment and Get the Source, then come back here for instructions specific to the Array Visualizer.<br>

## Array Visualizer Set Up

Every time you open a new terminal, follow these steps.

1. Reactivate the PATH and other environment variables for Emscripten: 
```
$ cd emsdk
$ source ./emsdk_env.sh
```

2. Change to the BoxAndArrow directory and activate the virtual environment. The `(venv)` before the Linux command prompt lets you know that you are currently working within your Python3 virtual environment:
```
$ cd ../BoxAndArrow
$ . venv/bin/activate
(venv) $
```

3. Move to the BoxAndArrow/Array subdirectory that contains the Array Visualizer Flask application. Before the `flask` script can be used, you need to set the `FLASK_APP` environment variable to tell it where to find the application. Make sure you are in the directory where arr.py is located:
```
$ cd Array
$ export FLASK_APP=arr.py
``` 

## Compile and Run the Array Visualizer

Now you can compile the starter code! The Array Visualizer provides a model solution and compares it with your results. To ensure that everything compiles from the get-go, a default return value has been set for all of the provided function prototypes. If you compile everything without changing the starter code, you can see what happens when a function implementation doesn't match the solution. Run the following commands each time you update your code.

1. Run the `make` command -- this uses the Emscripten Compiler Frontend (emcc) to build the code and compile your program so that it can be run on the Web.
```
(venv) $ make
```
* When `make` is successfully executed, it generates three files in the BoxAndArrow/Array directory:
    * `array.wasm`: binary code in the WebAssembly format
    * `array.js`: JavaScript glue code (necessary for .wasm code to work on the Web)
    * `array.html`: an HTML file that loads, compiles, and instantiates the WebAssembly code

2. Run the `runscript.sh` command.
```
(venv) $ ./runscript.sh
```
* Flask expects all JavaScript and CSS files to be in a `static` folder and all HTML files to be in a `templates` folder. The `runscript.sh` script moves the generated files to the appropriate locations for this application.

3. Start the server
```
(venv) $ flask run
```
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
* You can ignore the warning -- for most individuals using this project, running a development server in a production environment is fine for this project.
* If you want to, you can silence the warning by setting the FLASK_ENV variable:
```
(venv) $ export FLASK_ENV=development
```
* The name of your server is likely to be different -- that's normal. To run the program on the Web, simply copy the listed URL into the browser and include the path to the Array Visualizer application: `http://127.0.0.1:5000/array`
