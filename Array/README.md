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
* You may see `localhost` or another slightly different IP address -- that's normal. To run the program on the Web, simply copy the listed URL into the browser and include the path to the Array Visualizer application: `http://127.0.0.1:5000/array`

## Using Array Visualizer in the Browser

When you go to `http://127.0.0.1:5000/array` in the browser, you'll see a button to generate a list of random integers -- use this to create a random array of positive and negative integers that can be copied into any of the Array Values fields. Or, if you'd prefer, simply input your own comma-separated list of integers.<br>

Each array function is independent (not related to any of the other array functions). You can test the same array of values on different array functions, or different array values on the same array function. It's a good idea to test a variety of input to make sure your function produces the correct solution no matter the input.<br>

Note: Since these functions may be included in C++ code, `extern "C"` ensures that the functions are treated as external C functions, while the `EMSCRIPTEN_KEEPALIVE` declaration adds your functions to the list of exported functions and allows your code to run when compiled to JavaScript. The body of each function does not change.

### Exercise 1: Find Largest

Write the function `int EMSCRIPTEN_KEEPALIVE find_largest(int* arr, int length)` to iterate through the `arr` array and find the largest element in the array. The `length` parameter stores the number of array elements. Return the largest value in the array.

### Exercise 2: Calculate the Sum

Write the function `int EMSCRIPTEN_KEEPALIVE calc_sum(int* arr, int length)` that iterates through the array and calculates the sum. Return the sum of the elements in the array.

### Exercise 3: Double the Values

Write the function `int* EMSCRIPTEN_KEEPALIVE double_vals(int* arr, int length)` that doubles all of the values in the array. Emscripten does not support non-const reference parameters, but we can update the values in the array and then return an integer pointer to achieve the same result. 

### Exercise 4: Rotate Left

Write the function `int* EMSCRIPTEN_KEEPALIVE rotate_left(int* arr, int length)` that shifts all of the values in the array left by 1 and moves the first value to the last index of the array. As mentioned in Exercise #4, Emscripten does not support non-const reference parameters, but we can update the values in the array and then return an integer pointer to achieve the same result. 

### Exercise 5: Is Sorted

Write the function `bool EMSCRIPTEN_KEEPALIVE is_sorted(int* arr, int length)` that checks if the array is sorted in increasing order. If so, return true. If any values are not sorted in increasing order, return false.
