# BoxAndArrow
A repository for my Computer Science Master's Project: *Exploring the Use of Software Visualization in Computer Science Education and Developing a System to Facilitate the Construction of Algorithm Visualizations with JSAV and WebAssembly*.<br>

Box and arrow diagrams are often used to help illustrate how data structures and algorithms work in memory. While nothing beats a good whiteboard drawing, this tool aims to provide a clear and precise Web interface for testing and reviewing how data structures function, allowing users to quickly and easily test different inputs and compare their own code with a visualization.<br>

My goal has been to create an application that enables students and instructors to efficiently map their C++ code to a data structure visualization that can be viewed in a Web browser. This project utilizes [JSAV](http://jsav.io/), an existing and widely used Algorithm Visualization library. Users are able to construct visualizations that work with C++ programs they have written themselves because of the use of [WebAssembly](https://webassembly.org/) and [Emscripten](https://emscripten.org/docs/compiling/WebAssembly.html).

## License

BoxAndArrow is released under the [BSD 3-Clause License](https://github.com/shelleywong/BoxAndArrow/blob/main/LICENSE).

## Set Up Your Environment

This project was completed on a [VMware](https://www.vmware.com/) virtual machine running Ubuntu 20.04.1 LTS.<br>

Before you start, confirm that you have the necessary packages installed. You can do this by checking the version of each package. I have included a comment indicating the versions I used for this project.
```
$ git --version       // git version 2.25.1
$ make --version      // GNU Make 4.2.1
$ emcc -v             // emcc (Emscripten) 2.0.11
$ nodejs --version    // v10.19.0
$ python3 --version   // Python 3.8.5
$ flask --version     // Flask 1.1.2 and Werkzeug 1.0.1
```

* [Git](https://git-scm.com/) allows you to build this project from the source code.
* [GNU Make](https://www.gnu.org/software/make/) builds executable targets from the source code.
* [Emscripten](https://emscripten.org/docs/introducing_emscripten/about_emscripten.html) is an open-source toolchain that compiles C and C++ code to WebAssembly, enabling the code to be run on the Web.
  * If you have not previously worked with Emscripten, you will need to [download and install the emsdk repo](https://emscripten.org/docs/getting_started/downloads.html).
  * In order to use Emscripten on a separate project (outside of the emsdk directory), you will need to activate the PATH & other environment variables in the current terminal. From the `emsdk` directory, run `source ./emsdk_env.sh`
* [Node.js](https://nodejs.org/en/) is used by both Emscripten and JSAV.
* [Python](https://www.python.org/) is used by Emscripten.
  * This project uses [Flask](https://flask.palletsprojects.com/en/1.1.x/), a lightweight Python web application framework. I recommend that you use Python 3 (Flask supports Python 3.5 and newer).
  * Since different Python projects have different requirements, it is also recommended that you [create a separate virtual environment](https://flask.palletsprojects.com/en/1.1.x/installation/#install-flask) for each Python project. This helps you avoid problems with incompatible library versions or packages installed for other projects. Make sure you install Flask inside of the virtual environment that you plan to use for this project.<br>

The Python packages used by this application are listed in `requirements.txt`:
```
click==7.1.2
Flask==1.1.2
Flask-WTF==0.14.3
itsdangerous==1.1.0
Jinja2==2.11.2
MarkupSafe==1.1.1
Werkzeug==1.0.1
WTForms==2.3.3
```

## Get the Source

On GitHub, fork BoxAndArrow -- this creates a copy of the repository available in your personal account. You can then clone from your personal repo using `git clone` (HTTPS or SSH). Move to the directory (`cd BoxAndArrow`) to start working in it.<br>

If you notice anything that needs to be addressed, you can [create a new issue](https://github.com/shelleywong/BoxAndArrow/issues). You may also [create a new pull request](https://github.com/shelleywong/BoxAndArrow/pulls). Keep in mind, the code available in this public repository was built for educational use. In the spirit of promoting academic integrity, the examples provided in this repo are kept at a minimum. Please DO NOT try to add code to this repository that implements an actual programming assignment. You ARE encouraged to download this repository and try new examples on your own, in a private repo. More details on contributing to this project can be found in the `CONTRIBUTING.md` file.

## Initial Steps

After you set up your environment for the first time, you may need to redo some of the steps listed above (for instance, each time you open up a new terminal).<br>

Reactivate the PATH and other environment variables for Emscripten:
```
$ cd emsdk
$ source ./emsdk_env.sh
```

Create a virtual environment:
```
$ python3 -m venv venv
```

Or activate your virtual environment:
```
$ . venv/bin/activate
(venv) $
```

The Flask app must be told where to find your application in order to use it. When you have multiple Flask applications in the same environment, you will need to run this command (specifying the appropriate app in place of hello.py) each time you change apps:
```
$ export FLASK_APP=hello.py
```

## General Steps

After your environment is set up and the initial steps are complete, you will need to compile the code and run the Flask app. You will need to recompile when changes are made to any code that the Emscripten Compiler Frontend (emcc) sees (including any C++, JavaScript, and HTML connected to Emscripten).
```
$ make
```

When the code is compiled, files are automatically generated for JavaScript 'glue code', WebAssembly bytecode, and an extra HTML helper file for running the code. The `runscript` file is a simple bash script for (1) moving the generated files to the locations where they will be seen by the Flask app and (2) editing the location of the the JavaScript source code in the generated HTML file.
```
$ ./runscript.sh
```

Then you can run the Flask app. If changes are only made to the .py files, or any file that does not connect to Emscripten, you may not need to run the previous commands -- just run the following:
```
$ flask run
```
By default, the Flask app runs on `127.0.0.1` (mine was on port 5000).<br>

:rainbow: Thanks for visiting my project! :star:

