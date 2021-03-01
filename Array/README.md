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

Note: Since these functions may be included in C++ code, `extern "C"` ensures that the functions are treated as external C functions, while the `EMSCRIPTEN_KEEPALIVE` declaration adds your functions to the list of exported functions and allows your code to run when compiled to JavaScript. The body of each function does not change.<br>

## Array Exercises

After you complete each exercise, go through the steps to compile and run your code and check that everything is working as expected in the Array Visualizer. In order to see changes in your code, you'll likely need to open the Web Console and disable the cache. For more details, read the section on [Developing for Web](#developing-for-web).

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

## Hints

* If you see a message that "Something doesn't look right," it means that your results do not match the model solution. Walk through the array visualization and think about what has to happen before you enter the array, while iterating through the array, and after you've exited the array.
* One way to manually debug code is by using print statements. Below the visualization in the browser, you'll see a canvas where text can be displayed. All standard output (cout) statements get printed here. Printing information for debugging can help you confirm what your program is doing as you step through the code.
* Remember to test with all positive numbers, all negative numbers, and a combination of numbers, and check that your code is producing the results you expect in each case.
* Make sure you declare and initialize any local variables.
* Be careful that you don't step outside of the valid range of indices for your array (remember that C++ indexing begins at 0).
* If you've completed everything successfully, try using both the C++ [] operator and pointer arithmetic to traverse the array.

## Developing for Web

All browsers have a cache that is used to store local Web page resources. This is good for performance; however, if you are currently developing the Web page and making updates to the code, the changes may not show up immediately -- even if you refresh the page, the outdated page may be used instead because it's in the cache. Instructions are included for Firefox and Chrome; other browsers should have similar options.<br> 

* Solution #1: Disable Cache
    * Open the Web Console
    * Move to the Network tab
    * Make sure that there's a checkmark for Disable Cache
    * Then reload the page
* Solution #2: Clear the Cache Data
    * On Firefox, go to the menu and select > Preferences
        * Click on Privacy and Security
        * Under the Cookies and Site Data heading, click on Clear Data, make sure that there's a checkmark next to "Cached Web Content", and click Clear
        * Then reload the page
    * On Chrome, go to the menu and select > More Tools > Clear Browsing Data...
        * You can change the time range if you'd like, but make sure that there's a checkmark next to "Cookies and other site data" and "Cached images and files", and click Clear Data
        * Then reload the page<br>

After you've reloaded the page, check for your updates. If the changes still aren't showing up, try one of the other options.

### The Web Console

The Web console is an important and useful tool for Web developers. If you'd like more information, this is a good [introduction to the Web Console](https://developer.mozilla.org/en-US/docs/Tools/Web_Console).

* Firefox:
    * Use the shortcut(Windows/Linux): CTRL + Shift + K
    * Use the shortcut(macOS): Option + Command + K
    * Go to the menu (upper right hand corner of the browser window) and select > Web Developer > Web Console<br>

* Chrome:
    * Use the shortcut (Windows/Linux): CTRL + Shift + J
    * Use the shortcut (macOS): Option + Command + J
    * Go to the menu (upper right hand corner of the browser window) and select > More Tools > Developer Tools<br>
