# BoxAndArrow Linked List Visualizer

The BoxAndArrow Linked List Visualizer provides the framework for creating and testing your own Linked List class. If you haven't already, follow the steps in the main [BoxAndArrow README](https://github.com/shelleywong/BoxAndArrow) to Set Up Your Environment and Get the Source, then come back here for instructions specific to the Linked List Visualizer.

## Linked List Visualizer Set Up

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

3. Move to the BoxAndArrow/List subdirectory that contains the Linked List Visualizer Flask application. Before the `flask` script can be used, you need to set the `FLASK_APP` environment variable to tell it where to find the application. Make sure you are in the directory where list.py is located:
```
$ cd List
$ export FLASK_APP=list.py
``` 

## Compile and Run the Linked List Visualizer

Now you can compile the starter code! The Linked List Visualizer can help you visualize basic linked list operations like insertion, lookup, removal, and traversal. Pay attention as you click through the slideshow and make sure everything looks like you expect it to at each step. To ensure that everything compiles from the get-go, a default return value has been set for all of the provided function prototypes. If you compile everything without changing the starter code, you can see what happens when a function implementation doesn't match the solution. Run the following commands each time you update your code.

1. Run the `make` command -- this uses the Emscripten Compiler Frontend (emcc) to build the code and compile your program so that it can be run on the Web.
```
(venv) $ make
```
* When `make` is successfully executed, it generates three files in the BoxAndArrow/List directory:
    * `list.wasm`: binary code in the WebAssembly format
    * `list.js`: JavaScript glue code (necessary for .wasm code to work on the Web)
    * `list.html`: an HTML file that loads, compiles, and instantiates the WebAssembly code

2. Run the `runscript.sh` command.
```
(venv) $ ./runscript.sh
```
* Flask expects all JavaScript and CSS files to be in a `static` folder and all HTML files to be in a `templates` folder. The `runscript.sh` script moves the generated files to the appropriate locations for this application.

3. Start the server
```
(venv) $ flask run
```
* `flask run` is a command line script that can be used to run a development server. If you run into any errors with `flask run`, make sure you have set the `FLASK_APP` environment variable to point to the `list.py` application and you are in the same directory as `list.py`.
* You should see something similar to the following printed in the terminal:
```
 * Serving Flask app "list.py"
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
* You may see `localhost` or another slightly different IP address -- that's normal. To run the program on the Web, simply copy the listed URL into the browser and include the path to the Linked List Visualizer application: `http://127.0.0.1:5000/list`

## Using Linked List Visualizer in the Browser

When you go to `http://127.0.0.1:5000/list` in the browser, you'll see a button that generates a list of random integers. If you find it difficult to think of different sets of input to test, the random generator is a useful option for creating a random array of positive and negative integers that can be copied into any of the Array Values fields. You can also change any of the values or simply input your own comma-separated list of integers.<br>

Each linked list method is a member function of the Linked List class. Every time you start or restart the Linked List Visualizer, you'll instantiate a new linked list and all functions will impact the same linked list object. You can insert a set of values to start, or you can test how your program handles an empty list. The functions can be run in any order. It's a good idea to test the functions with a variety of input to make sure your Linked List program produces the correct solution no matter the input.<br>

A common way to show how linked lists work is with box and arrow diagrams drawn on a whiteboard. The Linked List Visualizer helps you step through this type of diagram without needing to continually draw and erase boxes and arrows. It also helps minimize the possibility of making incorrect assumptions while creating the diagram. In the visualization, you'll notice:

* Boxes -- these are the Nodes of the linked list. Each box/node contains a value and a `next` pointer.
* Arrows -- these are the pointers between nodes.
* After you insert the first node, you'll see an arrow floating above it -- this is the `head` Node pointer. It will always point to the beginning of the list.
* The last node in the list doesn't have an arrow pointing out of it; instead, this portion of the node has a slash through it to indicate you've reached NULL (the end of the list).
* The nodes are highlighted and unhighlighted as you traverse the list -- this represents a Node stepping through the list.<br>

Note: This program uses Emscripten Embind to bind C++ functions and classes, exposing them to JavaScript. The `EMSCRIPTEN_BINDINGS()` block at the end of list.cpp creates bindings for the public member functions of the Linked List class. You don't need to change anything in this block; just know that it allows your code to work with JavaScript and modify the visualization in the browser.

## Linked List Exercises

After you complete each exercise, go through the steps to compile and run your code and check that everything is working as expected in the Linked List Visualizer. In order to see changes in your code, you'll likely need to open the Web Console and disable the cache. For more details, read the section on [Developing for Web](#developing-for-web).<br>

You'll notice that several linked list functions are implemented for you. If you don't have a lot of experience programming linked lists, this starter code provides a bunch of useful tips for how to work with linked list code. Check out the [Hints](#hints) section for more help with interpreting the provided code.<br>

Note: Make sure you start by implementing `length()` -- it is used by the visualization to show how other linked list methods work as well, so it's important that it works as expected. 

### Exercise 1: Length

Write the function `int List::length()` that traverses the linked list, determines the number of nodes in the list, and returns this value.

### Exercise 2: Lookup

Write the function `int List::lookup(int value)` that traverses the linked list and checks to see if `value` is in the list. For this implementation, return the "index" of the value in the list -- the location of the node in relation to head of the list, using zero-based indexing. Thus, if `value` is at the head, `lookup()` should return 0. If `value` is not found in the list, return -1.

### Exercise 3: Remove Head

Write the function `bool List::remove_head()` that removes the node at the head of the list, returning true if a node is removed successfully and false if the list is empty and there are no nodes to remove. Remember to use the delete operator on the Node that is removed, as this is important for proper memory management. You can see how `delete` is used in the provided `~List` destructor.

### Exercise 4: Insert At End

Write the function `bool List::insert_at_end(int value)` that inserts the given value at the end of the list. To add an extra challenge to this implementation, `insert_at_end` only inserts if the value does not already exist in the list. If `value` is in the list already, return false. If `value` is inserted successfully, return true.

### Exercise 5: Remove Value

Write the function `int List::remove(int value)` that removes the target value from the list. For this implementation, return the "index" of the value removed from the list -- the location of the node in relation to head of the list, using zero-based indexing. Thus, if `value` is at the head, `remove()` should return 0. If `value` is not found in the list, return -1. Otherwise, return the "index" where the value was found and removed. Remember to use the delete operator on the Node that is removed, as this is important for proper memory management. You can see how `delete` is used in the provided `~List` destructor.

## Hints

* Remember to consider all special cases! These might include an empty list, checking for an element at beginning or end of list, and determining if a value doesn't exist in the list.
* The `List()` constructor is simple but important -- it initializes the head of the list to NULL. When the head is NULL, you know that you have an empty list. If head is not initialized, it can result in undefined behavior or segmentation faults.
* The `~List()` destructor shows how to delete all of the Nodes in the list. When you remove any node from the list, you generally need to set a temporary node pointer to the node that's being removed, move the current node pointer to the next node in the list, and then delete the node pointed to by the temporary node pointer.
* `void List::insert(int value)` shows how to initialize a new node. Make sure the node holds the given value and has a pointer to the appropriate next node. In this case, the new node inserted at the head has a next pointer to the old head of the list.
* `string List::print()` provides an example of how to traverse a linked list -- start a local node pointer at the beginning of the list, step through the list one node at a time, and exit the list when the local node pointer reaches NULL. For this program, we also return a variable that holds the list in a space-separated string. This string is used by the visualization to compare your results with the results expected by the visualization -- if differences are found between the results, the visualization will let you know.
* One way to manually debug code is by using print statements. Below the visualization in the browser, you'll see a canvas where text can be displayed. All standard output (cout) statements get printed here. Printing information for debugging can help confirm what your program is doing as you step through the code.

### A note about memory

Anytime you run a program that you have written, you are given access to specific portions of memory. In C++, some memory is allocated during runtime when you use the `new` operator. When you try to access memory that is outside of the memory that's been allocated to you, you usually receive a segmentation fault.<br>

Memory in WebAssembly and JavaScript works differently than memory in C++ -- you do not get the same segfaults because all WebAssembly memory addresses are technically accessible. This includes the 0x0 address, which is just a normal location in WebAssembly memory. However, in the Linked List Visualizer, your code WILL have undefined or unexpected behavior if you try to access memory outside of the memory that's been set aside for your program.<br>

Pay attention to the messages provided in the visualization. If you are told that something went wrong or your program produced an unexpected result, there is a good chance that your code would have produced a segfault in a normal C++ environment.<br>

You should also test your code with a variety of inputs and, at each step, make sure the visualization matches your expectations of how the linked list should appear. Buggy code will not always produce segfaults, but it will produce incorrect results in some situations.

## Developing for Web

All browsers have a cache that is used to store local Web page resources. This is good for performance; however, if you are trying to load a Web page that you are currently developing and updating, the changes may not show up immediately. Even if you refresh the page, the browser may load the outdated page instead because it's in the cache. Below, you will find a couple solutions to this issue. Instructions are included for Firefox and Chrome; other browsers should have similar options.<br>

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

After you've reloaded the page, check for your updates. If the changes still aren't showing up, test one of the other options. If none of the options work, you may want to add some additional debugging print statements to trace the flow of your program.

### The Web Console

The Web console is an important and useful tool for Web developers. If you'd like more information, this is a good [introduction to the Web Console](https://developer.mozilla.org/en-US/docs/Tools/Web_Console).

* To open the console on Firefox:
    * Use the shortcut(Windows/Linux): CTRL + Shift + I
    * Use the shortcut(macOS): Option + Command + I
    * Go to the menu (upper right hand corner of the browser window) and select > Web Developer > Web Developer Tools<br>

* To open the console on Chrome:
    * Use the shortcut (Windows/Linux): CTRL + Shift + J
    * Use the shortcut (macOS): Option + Command + J
    * Go to the menu (upper right hand corner of the browser window) and select > More Tools > Developer Tools<br>
