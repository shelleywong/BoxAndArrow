# BoxAndArrow Tree Visualizer

The BoxAndArrow Binary Tree Visualizer provides the framework for creating and testing your own Binary Tree class. If you haven't already, follow the steps in the main [BoxAndArrow README](https://github.com/shelleywong/BoxAndArrow) to Set Up Your Environment and Get the Source, then come back here for instructions specific to the Binary Tree Visualizer.

## Binary Tree Visualizer Set Up

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

3. Move to the BoxAndArrow/Tree subdirectory that contains the Binary Tree Visualizer Flask application. Before the `flask` script can be used, you need to set the `FLASK_APP` environment variable to tell it where to find the application. Make sure you are in the directory where tree.py is located:
```
$ cd Tree
$ export FLASK_APP=tree.py
```

## Compile and Run the Binary Tree Visualizer

Now you can compile the starter code! The Binary Tree Visualizer can help you visualize basic binary tree operations for inserting an element in the tree, finding an element in the tree, determining the number of nodes in the tree, determining if the tree is balanced, and printing in-order, pre-order, and post-order. Pay attention as you click through the slideshow and make sure everything looks like you expect it to at each step. To ensure that everything compiles from the get-go, a default return value has been set for all of the provided function prototypes. If you compile everything without changing the starter code, you can see what happens when a function implementation doesn't match the solution. Run the following commands each time you update your code.

1. Run the `make` command -- this uses the Emscripten Compiler Frontend (emcc) to build the code and compile your program so that it can be run on the Web.
```
(venv) $ make
```
* When `make` is successfully executed, it generates three files in the BoxAndArrow/Tree directory:
    * `tree.wasm`: binary code in the WebAssembly format
    * `tree.js`: JavaScript glue code (necessary for .wasm code to work on the Web)
    * `tree.html`: an HTML file that loads, compiles, and instantiates the WebAssembly code

2. Run the `runscript.sh` command.
```
(venv) $ ./runscript.sh
```
* Flask expects all JavaScript and CSS files to be in a `static` folder and all HTML files to be in a `templates` folder. The `runscript.sh` script moves the generated files to the appropriate locations for this application.

3. Start the server
```
(venv) $ flask run
```
* `flask run` is a command line script that can be used to run a development server. If you run into any errors with `flask run`, make sure you have set the `FLASK_APP` environment variable to point to the `tree.py` application and you are in the same directory as `tree.py`.
* You should see something similar to the following printed in the terminal:
```
 * Serving Flask app "tree.py"
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
* You may see `localhost` or another slightly different IP address -- that's normal. To run the program on the Web, simply copy the listed URL into the browser and include the path to the Binary Tree Visualizer application: `http://127.0.0.1:5000/tree`

## Using Binary Tree Visualizer in the Browser

When you go to `http://127.0.0.1:5000/tree` in the browser, you'll see a button that generates a list of random integers. If you find it difficult to think of different sets of input to test, the random generator is a useful option for creating a random array of positive and negative integers that can be copied into any of the Array Values fields. You can also change any of the values or simply input your own comma-separated list of integers.<br>

Each binary tree method is a member function of the Tree class. Every time you start or restart the Binary Tree Visualizer, you'll instantiate a new binary tree and all functions will impact the same Tree object. You can insert a set of values to start, or you can test how your program handles an empty tree. The functions can be run in any order. It's a good idea to test the functions with a variety of input to make sure your Binary Tree program produces the correct solution no matter the input.<br>

Note: This program uses Emscripten Embind to bind C++ functions and classes, exposing them to JavaScript. The `EMSCRIPTEN_BINDINGS()` block at the end of tree.cpp creates bindings for the public member functions of the Linked List class. Notice that the private Tree member functions are not included, since they will not be called outside of the class. You don't need to change anything in this block; just know that it allows your code to work with JavaScript and modify the visualization in the browser.

## Binary Search Tree Properties

All binary search trees have the following properties:

* All of the nodes in the left subtree have values less than the value of the current root node.
* All of the nodes in the right subtree have values greater than the value of the current root node.
* Each subtree in the binary tree is itself a binary tree.<br>

## Binary Tree Exercises

After you complete each exercise, go through the steps to compile and run your code and check that everything is working as expected in the Binary Tree Visualizer. In order to see changes in your code, you'll likely need to open the Web Console and disable the cache. For more details, read the section on [Developing for Web](#developing-for-web).<br>

You'll notice that the binary tree has a set of public member functions and a corresponding set of recursive private member functions. All private helper functions end in *_r (for recursive), so that Emscripten can differentiate the which functions to bind and which to ignore.<br>

Make sure you've completed the linked list exercises before you start trying to implement the Tree class. The binary tree data structure is made up of nodes, similar to nodes in a linked list, the main difference being that binary trees have a `left` and `right` node rather than one `next` node. The beginning of the tree is represented by the `m_root` Node pointer. In the Tree constructor, `m_root` is initialized to NULL, meaning the tree is empty.<br>

Each exercise includes some useful tips, so make sure to read the instructions carefully. Check out the [Hints](#hints) section for more help with implementing a binary tree and using the Binary Tree Visualizer.<br>

### Exercise 1: Node Constructor

Implement `Tree::Node::Node(int value)` -- this is a constructor that initializes a Node with the given integer `value`. The Node constructor should assign `value` to the Node private member variable `m_value`. Then it should initialize the `m_left` and `m_right` Node pointers to NULL, because each new node is inserted in the tree as a leaf node.

### Exercise 2: Tree and Node Destructors

Implement `Tree::~Tree()` and `Tree::Node::~Node()`, the Tree Destructor and the Node Destructor, respectively. You can delete all memory allocated for a binary tree using the C++ `delete` operator. When `delete` is used on an object, it calls the destructor of the object.<br>

In the Tree destructor, use the `delete` operator on the root of the tree, and in the Node destructor, use the `delete` operator on the left and right nodes of the tree. When `delete` is used on the root, it calls the destructor of the root Node object. When the Node object uses the `delete` operator on the left and right nodes, it calls the destructor of the left and right Node objects. This process continues recursively until NULL is reached, then the memory allocated for the Node objects is freed, starting with the leaf nodes and ending with the root node.<br>

You do not explicitly call the Tree or Node destructor, so you cannot see either of these at work in the visualization; however, it is important that you properly manage memory and implement the destructors. In WebAssembly, after an instance of a class is created, it must be deleted. This is already done for you in the provided JavaScript, but it doesn't know anything about how the destructors are implemented, so making sure they work as expected is up to you.

### Exercise 3: Insert a Node and Implement the Helper

#### Insert

Implement the public `bool Tree::insert(int value)` function and the private `bool Tree::insert_r(int value, Node *&cur_root)` function. Remember that all nodes are inserted as leaf nodes, and make sure that as you insert, you maintain the binary tree properties.<br>

The public `insert()` should call the private `insert_r()` with `m_root` passed in as the argument for the current root, and `insert_r()` should recursively traverse the tree to find the location to insert `value`.<br>

The private insert function can be expressed as a recursive algorithm:
```
recursive_insert(value, current_root):
    if current_root is null:
        create a new node with value and insert it at current_root
        successful insertion, return true
    if current_root.value equals value being inserted:
        value is already in the tree, return false
    if value is less than current_root.value:
        return recursive_insert(value, current_root.left)
    if value is greater than current_root.value:
        return recursive_insert(value, current_root.right)
```

#### Helper

Implement the public `string Tree::helper(int value)` function and the private `string Tree::helper_r(int value, Node *cur_root, string &result)` function. These helpers are special methods that assist the Binary Tree Visualizer, providing the information it needs to know the path that your `insert` and `remove` functions take before they reach their destination. The helpers make sure that the visualization reflects your C++ Tree implementation.<br>

In the public `helper()`, initialize an empty string called `result` and pass this argument to the private `helper_r()` function, along with `m_root` passed in as the argument for the current root. `helper_r()` should recursively traverse the tree until it reaches a base case:
```
recursive_helper(value, current_root, result):
    if current_root is null:
        base case reached, return the result string
    if current_root.value equals value being inserted:
        add "0" (0 as a string) to result, return the result string
    if value is less than current_root.value:
        add "1" (1 as a string) to result
        return recursive_helper(value, current_root.left, result)
    if value is greater than current_root.value:
        add "2" (2 as a string) to result
        return recursive_helper(value, current_root.right, result)
```

### Exercise 4: Find

Implement the public `bool Tree::find(int value)` function and the private `bool Tree::find_r(int value, Node *cur_root)` function. This type of tree implementation is sometimes called a binary search tree (BST), an ordered tree, or a sorted binary tree, as it follows the [Binary Search Tree Properties](#binary-search-tree-properties).<br>

The ordering of the nodes means that each comparison can, on average, skip half of the nodes in the tree. Even though the worst case runtime complexity is still linear O(n), the average runtime complexity for functions like find, insert, and remove can be cut in half to a relatively efficient runtime of O(log n).<br>

The find function has a very similar implementation to the insert function:
```
recursive_find(value, current_root):
    if current_root is null:
        value not found, return false
    if current_root.value equals value being targeted:
        value found, return true
    if value is less than current_root.value:
        return recursive_find(value, current_root.left)
    if value is greater than current_root.value:
        return recursive_find(value, current_root.right)
```

### Exercise 5: Print (in-order, pre-order, post-order)



### Exercise 6: Size



### Exercise 7: Balanced



## Hints

* Remember to consider all cases! Is the tree empty? Have you reached a leaf node? Is the value at the current node? Should you check the left or right node?
* This binary tree implementation uses recursion -- a process of defining a problem in terms of simpler instances of the same problem. In C++, you know that a function is using recursion if the function calls itself. You can think of the Tree as being made up of many smaller trees, where each node is a root with one left node and one right node, each of which is the root of its own smaller binary tree.
* Many recursive functions have an iterative counterpart, but trees naturally lend themselves to being defined recursively.
* The worst case time complexity for inserting a value into a binary tree or finding a value in a binary tree is O(n), but the average case time complexity is O(log n). If a binary tree is balanced or nearly balanced, you can halve the number of nodes you need to check at each step.
* With recursion, it is important to have at least one base case -- a case that causes the recursion to terminate. This is when your function returns without making a recursive call.
* One way to manually debug code is by using print statements. Below the visualization in the browser, you'll see a canvas where text can be displayed. All standard output (cout) statements get printed here. Printing information for debugging can help confirm what your program is doing as you step through the code.


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
    * Use the shortcut(Windows/Linux): CTRL + Shift + K
    * Use the shortcut(macOS): Option + Command + K
    * Go to the menu (upper right hand corner of the browser window) and select > Web Developer > Web Console<br>

* To open the console on Chrome:
    * Use the shortcut (Windows/Linux): CTRL + Shift + J
    * Use the shortcut (macOS): Option + Command + J
    * Go to the menu (upper right hand corner of the browser window) and select > More Tools > Developer Tools<br>
